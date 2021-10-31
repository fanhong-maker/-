//顺序表实现循环队列
//在本案例的循环队列中采用少用一个元素位的方式判断队列空或满
#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define FALSE 1
#define status int
#define MAXSIZE 6

typedef struct 
{
        int data;
}elemtype;

typedef struct
{
        elemtype* base;
        int front;
        int rear;
}Queue;

status queueinit(Queue* q)
{
        Queue *sq = q;
        sq->base = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);
        (*sq).front = 0;
        (*q).rear = 0;
        return OK;
}
status lenqueue(Queue q, int* num)
{
        *num = (q.rear - q.front + MAXSIZE) % MAXSIZE;
        return OK;
}
status getelem(Queue q, elemtype *data)
{
        if(q.front == q.rear)
        {
                printf("队列为空！\n");
                return FALSE;
        }
        *data = q.base[q.front];
        return OK;
}
status pop(Queue* q, elemtype* data)
{
        if(q->front == q->rear)
        {
                printf("队列为空！\n");
                return FALSE;
        }
        *data = q->base[q->front];
        q->front = (q->front+1)%MAXSIZE;
        return OK;
}
status push(Queue* q, elemtype data)
{
        if((q->rear+1)%MAXSIZE == q->front)
        {
                printf("队列满！\n");
                return FALSE;
        }
        q->base[q->rear] = data;
        q->rear = (q->rear+1)%MAXSIZE;
        return OK;
}
int main()
{
        Queue q;
        int num;
        elemtype data,data1;
        data.data = 10;
        queueinit(&q);
        for(int i = 0; i<6; i++)
        {
                push(&q, data);
        }
        lenqueue(q, &num);
        printf("%d\n", num);
        getelem(q, &data1);
        printf("%d\n", data1.data);
        return  0;
}