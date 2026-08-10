// p1.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define N 8
// unix std - POSIX 规范定义的标准 API
int main(void)
{
    //  __PID_T_TYPE pid = fork();
    for (int i = 0; i < N; i++)
    {
        __PID_T_TYPE pid = fork();
        if (pid == 0)
        {
            printf("我是p2子进程,worker=%d,master=%d\n", getpid(), getppid());
            // sleep(5);
            int val = i + 40;
            exit(val);
        }
        else
        {
            printf("我是p2父进程,worker=%d,master=%d\n", getpid(), getppid());
        }
    }

    for (int i = 0; i < N; i++)
    {
        int status;
        waitpid(-1, &status, WUNTRACED);
        if (WIFEXITED(status))
        {
            int val = WEXITSTATUS(status);
            printf("val=%d\n", val);
        }
    }
    printf("master :end\n");
    return 0;
}