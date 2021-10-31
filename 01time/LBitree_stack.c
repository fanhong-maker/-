//运用栈实现二叉树的非递归遍历
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define FALSE 1
#define status int

typedef struct
{
        char data;
}elemtype;
typedef struct Binode
{
        elemtype data;
        struct Binode* rchild;
        struct Binode* lchild;
}Binode, *Bitree;
typedef struct Snode
{
        Bitree data;
        struct Snode* next;
}Stack;
status initstack(Stack** s)
{
        *s = (Stack*)malloc(sizeof(Stack));
        if(!*s)
        {
                printf("内存分配失败！\n");
                return FALSE;
        }
        (*s) = NULL;
        return OK;
}
status pop(Stack** s, Bitree* data)
{
        
        Stack* temp = *s;
        *data = (temp->data);
        *s = (*s)->next;
        //printf("%c  ", (*s)->data->data.data);
        return OK;
}
status push(Stack** s, Bitree data)
{
        Stack* temp = *s;
        (*s) = (Stack*)malloc(sizeof(Stack));
        if(!*s)
        {
                printf("内存分配失败！\n");
                return FALSE;
        }
        (*s)->data = data;
        (*s)->next = temp;
        //printf("%c  ", (*s)->data->data.data);
        return OK;
}
int emptystack(Stack *s)
{
        if(s==NULL)
        {
                return 0;  
        }
        else
        {
                return 1;
        }
}
status getstack(Stack s, Bitree *data)
{
        *data = s.data;
        return OK;
}
status buildtree(Bitree* t)      //先序遍历实现二叉树的创建，递归创建：创建根结点，创建根节点的左结点，创建根节点的右结点，如此递归
{
        *t = (Bitree)malloc(sizeof(Bitree));
        if(!*t)
        {
                printf("内存分配失败！\n");
                return FALSE;
        }
        printf("请输入结点数据:");
        scanf("%c",&(*t)->data.data);
        getchar();
        if((*t)->data.data == '#')
        {
                *t = NULL;
                return 0;
        }
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
        return OK;
}
status preordertraverse(Bitree t)      //后序遍历
{
        if(t == NULL)
        {
                //printf("树为空！\n");
                return OK;
        }
        else
        {
                printf("%c  ", t->data.data);
                preordertraverse(t->lchild);
                preordertraverse(t->rchild);     
        }
        return OK;
}
status traverse(Bitree t)       //非递归遍历
{
        Stack* s;
        initstack(&s);
        Bitree* data;
        Bitree value;
        Bitree T = t;
        while(T || emptystack(s))
        {
                if((T) != NULL)
                {
                        push(&s, T);
                        T = T->lchild;
                }
                else
                {
                        pop(&s, &value);
                        printf("%c  ", value->data.data);
                        T = value->rchild;
                }
        }
        return OK;
}
int main()
{
        Bitree t = NULL;
        buildtree(&t);
        preordertraverse(t);
        puts("");
        traverse(t);
        return 0;
}