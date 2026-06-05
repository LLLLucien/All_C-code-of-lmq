// hash.c
// 使用线性探测实现一个哈希表，容量NUM，哈希算法 mod mod
#include <stdio.h>
#include <stdlib.h>
//
#define NUM 10
#define mod 7
typedef struct hash_arr {
    int data[NUM]; // 数据
    int count;     // 已存容量
} Hash_arr;
// 哈希函数
int Hash(int data);
// 初始化
void init(Hash_arr *arr);
// 插入
int insert(int data, Hash_arr *arr);
// 查找
int find(int data, Hash_arr *arr);
// 展示
void show(Hash_arr *arr);
int main(int argc, char const *argv[])
{
    Hash_arr arr;
    init(&arr);
    insert(38, &arr);
    insert(25, &arr);
    insert(74, &arr);
    insert(63, &arr);
    insert(52, &arr);
    insert(48, &arr);
    insert(49, &arr);
    insert(50, &arr);
    insert(51, &arr);
    insert(53, &arr);
    insert(54, &arr);

    if (insert(54, &arr) >= 0)
    {
        printf("插入成功\n");
    } else if (insert(54, &arr) == -1)
    {
        printf("插入失败\n");
    }
    int n = 74;
    if (find(n, &arr) >= 0)
    {
        printf("查找成功,下标为%d\n", find(n, &arr));
    } else
    {
        printf("查找失败\n");
    }
    show(&arr);

    return 0;
}
void init(Hash_arr *arr)
{
    for (int i = 0; i < NUM; i++)
    {
        arr->data[i] = -1;
    }
    arr->count = 0;
}
int Hash(int data) { return data % mod; }
// 插入
int insert(int data, Hash_arr *arr)
{
    // 求data的哈希值
    int data_hash = Hash(data);
    // 判断是否满
    // if (arr->count == NUM)
    // {
    //     return -2;
    // }
    // 如果没有数据就直接放
    if (arr->data[data_hash] == -1)
    {
        arr->data[data_hash] = data;
    } else
    {
        int tmp = data_hash;
        while (1)
        {
            if (arr->data[tmp] != -1)
            {
                tmp++;
                tmp %= NUM;
                // 如果一直探测，回到原来的位置，则插入失败
                if (tmp == data_hash)
                {
                    return -1;
                }
                continue;
            } else
            {
                arr->data[tmp] = data;
                break;
            }
        }
    }
    arr->count++;
    return 0;
}
int find(int data, Hash_arr *arr)
{
    int data_hash = Hash(data);
    for (int i = 0; i < NUM; i++)
    {
        int index = (data_hash + i) % NUM;
        if (arr->data[index] == data)
        {
            return index;
        }
        // 遇到-1就不可能存在要查找的数据
        else if (arr->data[index] == -1)
            break;
    }
    return -1;
}

void show(Hash_arr *arr)
{
    printf("{");
    for (int i = 0; i < NUM; i++)
    {
        if (arr->data[i] == -1)
        {
            printf(" ,");
        } else
            printf("%d,", arr->data[i]);
    }
    printf("\b}\n");
}