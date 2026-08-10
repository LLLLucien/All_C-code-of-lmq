// p1.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
// unix std - POSIX 规范定义的标准 API
int main(void)
{
    __PID_T_TYPE pid = fork();
    printf("pid=%d\n", pid);
    if (pid == -1)
    {
        perror("创建失败\n");
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        printf("我是p1子进程,worker=%d,master=%d\n", getpid(), getppid());

        // exec - execute
        // 用新程序替换当前进程的代码，PID 不变，但执行的内容全换了
        // execl list  多个参数，逗号分隔
        // execv array 一个数组
        // execlp list 用 PATH 找（只用文件名）

        // 1. 路径 2. 程序名字 3. 参数 4. NULL 表示结束
        execlp("./test", "test", NULL);

        exit(42);
    }
    else
    {
        printf("我是p1父进程,worker=%d,master=%d\n", getpid(), getppid());
        // 获得子进程的退出状态
        sleep(10);
        int status;
        waitpid(pid, &status, WUNTRACED);
        if (WIFEXITED(status))
        {
            int val = WEXITSTATUS(status);
            printf("val=%d", val);
        }
    }
    return 0;
}