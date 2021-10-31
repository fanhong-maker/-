//实现二叉树的层次遍历
#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define FALSE 1
#define MAXSIZE 16
#define status int
//二叉树
typedef struct
{
        char data;
}elemtype;
typedef struct Binode 
{
        elemtype data;
        struct Binode *lchild, *rchild;
}Binode,*Bitree;
//队列
typedef struct 
{
        Binode** base;
        int front;
        int rear;
}Queue;

status initqueue(Queue* q)
{
        q->base = (Bitree*)malloc(sizeof(Bitree)*MAXSIZE);
        if(!q->base)
        {
                printf("内存申请失败!\n");
                return FALSE;
        }
        q->front = 0;
        q->rear = 0;
        return OK;
}
status emptyqueue(Queue q)
{
        if(q.front == q.rear)
        {
                return 0;
        }
        return 1;
}
status push(Queue* q, Binode* data)
{
        if((q->rear+1)%MAXSIZE == q->front)
        {
                printf("队列已满！\n");
                return FALSE;
        }
        q->base[q->rear] = data;
        q->rear = (q->rear + 1) % MAXSIZE;
        return OK;
}
status pop(Queue* q)
{
        if(!emptyqueue)
        {
                printf("队列为空！\n");
                return FALSE;
        }
        q->front = (q->front + 1)%MAXSIZE;
        return OK;
}
status  leveltraversal(Binode* t)
{
        Queue q;
        initqueue(&q);
        if(!t)
        {
                printf("二叉树为空！\n");
                return FALSE;
        }
        push(&q, t);
        while(emptyqueue(q))
        {
                if(q.base[q.front]->lchild)
                {
                        push(&q, q.base[q.front]->lchild);
                }  
                if(q.base[q.front]->rchild)
                {
                        push(&q, q.base[q.front]->rchild);
                } 
                printf("%c  ", q.base[q.front]->data.data);
                pop(&q);
        }
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
status postordertraverse(Bitree t)      //后序遍历
{
        if(t == NULL)
        {
                //printf("树为空！\n");
                return OK;
        }
        else
        {
                postordertraverse(t->lchild);
                postordertraverse(t->rchild);
                printf("%c  ", t->data.data);
        }
        return OK;
}
int main()
{
        Bitree t = NULL;
        buildtree(&t);
        postordertraverse(t);
        puts("");
        leveltraversal(t);
        return 0;
}