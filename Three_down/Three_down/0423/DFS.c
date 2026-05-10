// DFS.c
// 初始化邻接矩阵，6*6二维数组，执行深度优先遍历DFS（递归、栈）
/*
   a b c d e f
a  0 1 1 0 1 0
b  1 0 0 0 1 0
c  1 0 0 0 0 1
d  0 0 0 0 1 1
e  1 1 0 1 0 0
f  0 0 1 1 0 0

*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

// 初始化邻接矩阵
void init(int a[][SIZE]);
// 打印矩阵
void show_arr(int a[][SIZE]);
// DFS调用函数
void DFS(int a[][SIZE], char data[]);
// DFS函数
void DFS_way(int a[][SIZE], int visited[], int i, char data[]);
// BFS调用函数
void BFS(int a[][SIZE], char data[]);
// BFS函数
void BFS_way(int a[][SIZE], int visited[], int i, char data[]);

int main(int argc, char const *argv[])
{
    int a[SIZE][SIZE] = {{0, 1, 1, 0, 1, 0}, {1, 0, 0, 0, 1, 0},
                         {1, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 1},
                         {1, 1, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 0}};

    // init(a);
    show_arr(a);

    char data[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f'};

    DFS(a, data);
    BFS(a, data);
    printf("\n");
    return 0;
}
// void init(int a[][SIZE]) {
//   int num[14] = {1, 2, 4, 0, 4, 0, 5, 4, 5, 0, 1, 3, 2, 3};
//   int t = 0;
//   for (int i = 0; i < SIZE; i++) {
//     for (int j = 0; j < SIZE; j++) {
//       if (num[t] == j) {
//         a[i][j] = 1;
//         t++;
//       }
//     }
//   }
// }

void show_arr(int a[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d,", a[i][j]);
            if (j + 1 == 6)
                printf("\n");
        }
    }
}
// DFS助函数
void DFS_way(int a[][SIZE], int visited[], int i, char data[])
{
    visited[i] = 1;         // 标记当前顶点已访问
    printf("%c ", data[i]); // 访问当前顶点

    // 一直遍历
    for (int j = 0; j < SIZE; j++)
    {
        // 如果相连并且未访问
        if (a[i][j] != 0 && visited[j] == 0)
        {
            // 继续遍历,把j所指的顶点变为当前节点
            DFS_way(a, visited, j, data);
        }
    }
}

void BFS_way(int a[][SIZE], int visited[], int i, char data[])
{
    int queue[SIZE] = {0}; // 队列
    int head = 0;
    int tail = 0;

    queue[tail++] = i;
    visited[i] = 1;

    while (head < tail)
    {
        // 出队,头指针后移
        int cur = queue[head++];
        printf("%c ", data[cur]);

        // 遍历当前顶点的所有相邻顶点
        for (int j = 0; j < SIZE; j++)
        {
            if (a[cur][j] != 0 && visited[j] == 0)
            {
                queue[tail++] = j; // 入队,尾指针后移
                visited[j] = 1;    // 标记当前顶点已访问
            }
        }
    }
}

// DFS遍历入口函数
void DFS(int a[][SIZE], char data[])
{
    int visited[6] = {0};
    printf("DFS遍历结果:");
    DFS_way(a, visited, 0, data);
    printf("\n");
}
void BFS(int a[][SIZE], char data[])
{
    int visited[6] = {0};

    printf("BFS遍历结果:");
    BFS_way(a, visited, 5, data);
    printf("\n");
}