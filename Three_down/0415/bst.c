// 二叉搜索树
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;           // 数据域
    struct node *left;  // 左
    struct node *right; // 右

} Node, Tree;

// 操作：插入、先序、后序、中序
Node *insert(Tree *root, int data);
void pre_order(Tree *root);  // 先序
void post_order(Tree *root); // 后序
void in_order(Tree *root);   // 中序
void ceng_order(Tree *root); // 层序
int min(Tree *root);
int max(Tree *root);
void reverse(Tree *root);

int main(int argc, char const *argv[])
{
    Tree *root = NULL; // 空树
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);

    printf("中序\n");
    in_order(root);
    printf("\n");
    printf("层序\n");
    ceng_order(root);
    printf("\n");
    printf("前序\n");
    pre_order(root);
    printf("\n");
    printf("后序\n");
    post_order(root);
    printf("\n");
    printf("min=%d\n", min(root));
    printf("max=%d\n", max(root));
    printf("翻转\n");
    reverse(root);
    in_order(root);
    printf("\n");

    return 0;
}
Node *insert(Tree *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (data < root->data) // 小于往左边插
    {
        root->left = insert(root->left, data); // 递归
    } else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    // 相等则不插，不进行操作
    return root;
}
// 先序
void pre_order(Tree *root)
{
    if (root != NULL)
    {
        printf("%d,", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}
// 后序
void post_order(Tree *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d,", root->data);
    }
}
// 中序
void in_order(Tree *root)
{
    if (root != NULL)
    {
        in_order(root->left);      // 先左子树
        printf("%d,", root->data); // 根
        in_order(root->right);     // 右子树
    }
}
// 层序
void ceng_order(Tree *root)
{
    if (root != NULL)
    {
        Node *queue[100];
        int head = 0;
        int tail = 0;

        queue[tail++] = root;
        while (head < tail)
        {
            Node *cur = queue[head++];
            printf("%d,", cur->data);
            if (cur->left != NULL)
                queue[tail++] = cur->left;
            if (cur->right != NULL)
                queue[tail++] = cur->right;
        }
    }
}
int min(Tree *root)
{
    if (root != NULL)
        if (root->left != NULL)
        {
            return min(root->left);
        } else
        {
            return root->data;
        }
}
int max(Tree *root)
{
    if (root != NULL)
        if (root->right != NULL)
        {
            return max(root->right);
        } else
        {
            return root->data;
        }
}
void reverse(Tree *root)
{
    if (root != NULL)
    {
        // 直接交换左右孩子
        Node *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        // 递归处理左右子树
        reverse(root->right);
        reverse(root->left);
    }
}
