//顺序栈的标准定义模板
//栈是一种线性表，是一种先进后出、后进先出的数据结构，只能在栈顶（表尾）进行数据的删除和添加操作
//编写c到现在，总结一下：指针也只不过是一个变量，是一个存放地址的变量，我们声明一个结构体变量时
//是可以通过该变量访问结构体的成员的，但是，我们声明一个结构体指针变量，但未对其赋值，此时通过该指针
//是不可以访问结构体的成员的，因为，此时该指针是一个野指针，它所指向的内存空间并没有声明该结构体类型
#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define FALSE 1
#define status int
#define MAXSIZE 100
typedef struct 
{
        /* data */
}elemtype;

typedef struct
{
        elemtype* top;  //用于指向栈顶的指针
        elemtype* base; //用于指向栈底的指针
        int stacksize;
}stack; 
status intistack(stack* s)      //初始化
{
        (s)->base = (elemtype*)malloc(MAXSIZE*sizeof(elemtype));
        if(!(s)->base)
        {
                printf("内存分配失败！\n");
                return FALSE;
        }
        (s)->top = (s)->base;
        (s)->stacksize = MAXSIZE;
        return OK;
}
status stackempty(stack* s)     //判断栈是否为空
{
        if(s->top - s->base == 0)
        {
                printf("栈为空！\n");
        }
        else
        {
                printf("栈不为kong!\n");
        }
        return OK;
}
status stacklen(stack* s, int* num)     //求解栈的大小
{
        *num = s->top - s->base;
        return OK;
}
status stackclear(stack* s)     //清空栈
{
        if(s->base)s->top = s->base;
        return OK;
}
status stackdestroy(stack* s)   //释放栈空间
{
        free(s->base);
        s->stacksize = 0;
        s->base = NULL;
        s->top = NULL;
        return OK;
}
status push(stack s, elemtype num)      //入栈
{
        if(s.top-s.base == s.stacksize)
        {
                printf("栈满！\n");
                exit(0);
        }
        else
        {
                *s.top++ = num;
        }
        return OK;
}
status pop(stack s, elemtype* data)     //出栈
{
        if(s.top != s.base)
        {
                *data = *--s.top;
        }
        else
        {
                printf("下溢");
                exit(0);
        }
        return OK;
}
int mian()
{
        stack s;
        s.base = NULL;
        return 0;
}