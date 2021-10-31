#include<stdio.h >
#include<stdlib.h>

#define OK 0
#define FALSE 1
#define status int

typedef struct 
{
        int data;
}elemtype;
typedef struct Lnode 
{
        elemtype data;
        struct Lnode* next;
}Lqueue;
typedef struct 
{
        Lqueue* rear;
        Lqueue* front; 
}Qptr;
status queueinit(Qptr* q)
{
        (q)->rear = (q)->front = (Lqueue*)malloc(sizeof(Lqueue));
        if(!(q)->front)
        {
                printf("内存申请失败！\n");
                exit(0);
        }
        (q)->rear->next = NULL;
        return 0;
}
status pop(Qptr* q)
{
        Lqueue *temp = q->front->next;
        if(q->front == q->rear)
        {
                printf("队列为空！\n");
                return FALSE;
        }
        if(temp == q->rear)
        {
                q->rear = q->front;
                free(temp);
                return OK;
        }
        q->front->next = temp->next;
        free(temp);
        return OK;
}
status push(Qptr* q)
{
        elemtype data;
        int num;
        printf("输入个数：");
        scanf("%d",&num);
        for(int i = 0; i < num; i++)
        {
                printf("input data：");
                scanf("%d", &data.data);
                q->rear->next = (Lqueue*)malloc(sizeof(Lqueue));
                if(!q->rear->next)
                {
                        printf("内存分配失败！\n");
                        return FALSE;
                }
                q->rear = q->rear->next;
                q->rear->data.data = data.data;
                q->rear->next = NULL;
        }
        return  OK;
}
status dislqueue(Qptr q)
{
        if(q.rear == q.front)
        {
                printf("队列空！\n");
                return OK;
        }
        while(q.front != q.rear)
        {
                q.front = q.front->next;
                printf("%d  ", q.front->data.data);
        }
        puts("");
        return OK;
}
status destory(Qptr *q)
{  
        while(q->front != NULL)
        {
                Lqueue* temp = q->front;
                q->front = q->front->next;
                free(temp);
        }
        q->front = q->rear = NULL;
        return OK;
}
int main()
{
        Qptr q;
        queueinit(&q);
        push(&q);
        dislqueue(q);
        pop(&q);
        dislqueue(q);
        destory(&q);
        dislqueue(q);
        return 0;
}