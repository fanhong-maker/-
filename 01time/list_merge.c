//本代码实现两个线性表的合并，既是两个线性表求交集！！！
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define status int
#define  OK 0
#define TRUE 0
#define FLASE 1
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_SIZE 20

typedef struct 
{
        int data;
}Data;

typedef struct
{
        Data list[MAX_SIZE];
        int length;
}List;

status intilist(List** l)
{
        *l = (List*)malloc(sizeof(List));
        if(!(*l))
        {
                printf("内存分配失败！");
                return FLASE;
        }
        (*l)->length = 0;
        return OK;
}
status insertnode(List** l)
{
        int length = 0;
        List* list = *l;
        while(list->list[length-1].data != -1)
        {
                printf("请输入数字(输入-1退出)\n");
                scanf("%d",&(list->list[length].data));
                length++;
        }
        length = length-1;
        if(length > MAX_SIZE)
        {
                printf("溢出\n");
                return OVERFLOW;
        }
        list->length = length;
        return OK;
}
status display(List* l)
{
        List* list = l;
        for(int i = 0; i < list->length; i++)
        {
                printf("%d  ",list->list[i].data);
        }
        printf("长度：%d",l->length);
        puts("");
        return OK;
}
status locate(List* l, Data num, int* location)
{
        List* list = l;
        int i = 0;
        while((i < list->length) && (list->list[i].data != num.data))
        {
                i++;
        }
        *location = i;
        return OK;
}
status merge(List* la, List* lb, List** lc)
{
        int i = 0;
        int j = 0;
        int location;
        intilist(lc);
        //length = (la->length > lb->length)?lb->length:la->length;
        while(i < la->length && i < lb->length)
        {
                locate(la, lb->list[i], &location); 
                if(location == la->length)
                {
                        (*lc)->list[j].data = la->list[i].data;
                        j++; 
                        (*lc)->list[j].data = lb->list[i].data;
                        j++;
                        i++;
                }
                else
                {
                        (*lc)->list[j].data = la->list[i].data;
                        j++;
                        i++;
                }
        }
        if(la->length > lb->length)
        {
                while(i < lb->length)
                {
                        (*lc)->list[j].data = la->list[i].data;
                        j++; 
                        i++;
                }
        }
        else
        {
                while(i < lb->length)
                {
                        (*lc)->list[j].data = lb->list[i].data;
                        j++; 
                        i++;   
                }
        }
        (*lc)->length = j;
}
int main(void)
{
        List *la = NULL;
        List *lb = NULL;
        List *lc = NULL;
        intilist(&la);
        insertnode(&la);
        display(la);
        intilist(&lb);
        insertnode(&lb);
        display(lb);
        merge(la, lb, &lc);
        display(lc);
        return 0;
}

