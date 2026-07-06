// 实现实现客户端的多次读写（循环加退出条件）
// hw1.c

#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_TID 4
// 客户端多线程函数
void *Client_io(void *arg);

sem_t sem;
// 控制动态创建线程
volatile int flag = 1;
// 需要输出的信息
char su_password[] = "112233\n";
char shutdown_order[] = "shutdown\n";
char msg_continue[] = "----Server continue!----\n";
char buf_exit[] = "exit";
char msg_exit[] = "----Server Exit!----\n";
char msg[] = "---发送成功！---\n";

// 传入线程函数的参数的结构体
typedef struct net_info
{
    int fd;
    int tid;
    int c_fd;

} NET_INFO;

int main()
{

    // 初始化信号量，控制最大线程数
    sem_init(&sem, 0, MAX_TID);
    // 创建服务端套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("描述符创建失败\n");
        return EXIT_FAILURE;
    }

    // 定义地址的协议族
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9000);

    // 绑定地址
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind 绑定失败");
        close(fd);
        exit(EXIT_FAILURE);
    }

    listen(fd, MAX_TID);
    printf("----等待连接----\n");

    // 用来记录客户端地址
    struct sockaddr_in c_addr;
    memset(&c_addr, 0, sizeof(c_addr));

    int len = sizeof(c_addr);
    // 记录客户端号码
    int c_num = 0;

    // 循环动态创建线程
    while (flag)
    {
        // 线程满了就会阻塞
        sem_wait(&sem);
        // 先分配内存给结构体
        NET_INFO *info = malloc(sizeof(NET_INFO));
        // 如果有客户端连接，就会启动线程
        int c_fd = accept(fd, (struct sockaddr *)&c_addr, (socklen_t *)&len);
        if (c_fd == -1)
        {
            free(info);
            sem_post(&sem);
            if (flag == 0)
                break; // 服务端主动关闭，退出循环
            else
                continue; // 其他错误，继续等待
        }
        info->c_fd = c_fd;
        info->fd = fd;
        info->tid = c_num + 1;

        pthread_t t;
        pthread_create(&t, NULL, Client_io, (void *)info);
        // 不需要join，让线程结束时自动释放
        pthread_detach(t);
        c_num++;
    }

    printf("----服务端已关闭----\n");
    close(fd);
    return 0;
}

// 带返回值检查的read，统一处理正常/断开/出错三种情况
int checked_read(int fd, char *buf, int size, int tid)
{
    int n = read(fd, buf, size);
    if (n > 0)
    {
        buf[n] = '\0';
    }
    else if (n == 0)
    {
        printf("客户端%d号断开连接\n", tid);
    }
    else
    {
        write(fd, "客户端出错，请重新连接\n", strlen("客户端出错，请重新连接\n"));
        printf("客户端%d号断开连接\n", tid);
    }
    return n;
}

void *Client_io(void *arg)
{
    char msg_suc[] = "已连接服务端!\n";
    int fd = ((NET_INFO *)arg)->fd;
    int tid = ((NET_INFO *)arg)->tid;
    int c_fd = ((NET_INFO *)arg)->c_fd;

    // 验证连接是否成功
    if (c_fd == -1)
    {
        perror("----客户端连接失败----\n");
        printf("----客户端%d号断开连接----\n", tid);
        sem_post(&sem);
        free(arg);
        return NULL;
    }
    write(c_fd, msg_suc, strlen(msg_suc));
    printf("客户端%d号已连接\n", tid);

    // 无限循环判断输入内容是否是退出客户端还是关闭服务端
    while (1)
    {
        char buf[1024];
        memset(buf, 0, 1024);
        // 缓冲区
        int read_size = checked_read(c_fd, buf, sizeof(buf), tid);
        // 判断read返回值
        if (read_size <= 0)
            break;
        // read没问题就发送，并进行判断
        write(c_fd, msg, strlen(msg));
        printf("客户端%d号发来: %s\n", tid, buf);

        // 判断是不是要退出客户端
        if (strncmp(buf, buf_exit, 4) == 0)
        {

            // 二次确认
            write(c_fd, "确定退出?y or n\n", strlen("确定退出?y or n\n"));
            char buf_sure[1024];
            memset(buf_sure, 0, sizeof(buf_sure));
            int read_size2 = checked_read(c_fd, buf_sure, sizeof(buf_sure), tid);
            // 判断read返回值
            if (read_size2 <= 0)
                break;
            // read没问题就继续判断二次确认的结果
            if (strncmp(buf_sure, "y", 1) == 0)
            {
                printf("客户端%d号发来: %s\n", tid, buf_sure);
                write(c_fd, msg_exit, strlen(msg_exit));
                printf("客户端%d号断开连接\n", tid);
                break;
            }
            else
            {
                // 否则不是y就把内容发送出去，并提示服务继续
                write(c_fd, msg_continue, strlen(msg_continue));
                printf("客户端%d号发来: %s\n", tid, buf_sure);
                write(c_fd, msg, strlen(msg));
            }
        }
        // 再判断是不是要关闭服务端
        else if (strncmp(buf, shutdown_order, 8) == 0)
        {
            // 新的缓冲区，用来存输入的密码
            char buf_password[1024];
            memset(buf_password, 0, sizeof(buf_password));
            write(c_fd, "请输入密码\n", strlen("请输入密码\n"));
            // 固定判断read返回值
            int read_size = checked_read(c_fd, buf_password, sizeof(buf_password), tid);
            if (read_size <= 0)
                break;
            // 返回值没问题就看密码对不对
            if (strncmp(buf_password, su_password, 6) == 0)
            {
                write(c_fd, msg, strlen(msg));
                printf("客户端%d号发来: %s\n", tid, buf_password);
                printf("！！！客户端%d号执行关闭服务器！！！\n", tid);
                write(c_fd, "----正在关闭服务器----\n", strlen("----正在关闭服务器----\n"));
                // 修改flag，主线程就不会再循环了
                flag = 0;
                close(fd);
                close(c_fd);
                sem_post(&sem);
                free(arg);
                return NULL;
            }
            // 密码不对，继续服务
            else
            {
                write(c_fd, msg, strlen(msg));
                write(c_fd, "密码错误\n", strlen("密码错误\n"));
            }
        }
    }
    // 前面如果出现问题了，就释放线程资源
    sem_post(&sem);
    close(c_fd);
    free(arg);
    return NULL;
}
