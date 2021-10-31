//链栈，其实就是单链表,链栈基本不存在栈满的情况
//链栈和顺序栈的区别在于：链栈的大小是动态的，顺序栈的大小是固定的
#include<stdio.h>
#include<stdlib.h>

#define status int
#define OK 0
#define FALSE 1

typedef struct 
{
        int data;
}elemtype;

typedef struct stack
{
        elemtype data;
        struct stack *next;
}linkstack;

status initstack(linkstack **s)  //栈的初始化
{
        *s = NULL;
        return OK;
}
status stackempty(linkstack *s)  //判断栈是否为空
{
        if(!s)printf("栈不为空！\n");
        else printf("栈为空！\n");
        return OK;
}

status stackdestory(linkstack **s)
{
        linkstack *p,*temp;
        p = *s;
        while(p!=NULL)
        {
                temp = p;
                p = p->next;
                free(temp);
        }
        return OK;
}
status pop(linkstack** s, elemtype *data)
{
        linkstack* p = *s;
        *data = p->data;
        printf("%d  ", (*s)->data.data);
        *s = (*s)->next;
}
status push(linkstack** s, elemtype data)
{
        linkstack* temp = *s;
        *s = (linkstack*)malloc(sizeof(linkstack));
        (*s)->data = data;
        (*s)->next = temp;
        printf("%d  ", (*s)->data.data);
        return OK;
}
int main()
{
        linkstack *s;
        elemtype data;
        elemtype data1;
        elemtype data2;
        data1.data = 10;
        data2.data = 20;
        initstack(&s);
        printf("%p\n",s);
        push(&s, data1);
        push(&s, data2);
        printf("%d\n",s->data.data);
        pop(&s, &data);
        printf("%d\n",s->data.data);
        return 0;
}