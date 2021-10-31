//用顺序表实现多项式的加减运算
#include<stdio.h>
#include<stdlib.h>

#define LIST_SIZE 100
#define FLASE 0
#define TRUE 1
#define ERROR 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct 
{
        int coefficient;
        int power;
}Elemtype;
typedef struct
{
        Elemtype elem[LIST_SIZE];
        int length;
}Polynomial;        //定义顺序表的标准模板

int initpol(Polynomial** list)
{
        *list = (Polynomial*)malloc(sizeof(Polynomial));
        if(!list)
        {
                printf("申请内存失败！");
                exit(ERROR);
        }
        (*list)->length = 0;
        return OK;
}
int destroypol(Polynomial *list)
{
        free(list);
        list = NULL;
        return OK;
}
int clearpol(Polynomial* list)
{
        list->length = 0;
        return OK;
}
int lengthpol(Polynomial* list)
{
        return list->length;
}
int isempty(Polynomial* list)
{
        if(list->length == 0)
        {
                return TRUE;
        }
        else
        {
                return FLASE;
        }
}
int getelem(Polynomial* list, int i, Elemtype* elem)
{
        if(i < 1 || i > list->length+1)
        {
                printf("超出范围！");
                return INFEASIBLE;
        }
        else
        {
                *elem = list->elem[i-1];
        }
        return OK;
}
int insertpol(Polynomial*list)
{
        printf("请输入多项式的元素个数：");
        int num;
        scanf("%d",&num);
        list->length = num;
        for(int i=0; i < num; i++)
        {
                printf("请输入第%d元素的系数：", i+1);
                scanf("%d",&(list->elem[i].coefficient));
                printf("请输入第%d元素的指数：", i+1);
                scanf("%d",&(list->elem[i].power));
        }
        return 0;
}
int displaypol(Polynomial list)
{
        for(int i=0; i<list.length; i++)
        {
                printf("%d(%d)  ",list.elem[i].coefficient,list.elem[i].power);
        }
        return 0;
}
int addpol(Polynomial l1, Polynomial l2, Polynomial *l)
{
        int m = 0;
        int n = 0;
        printf("%d\n",l1.length);
        printf("%d\n",l2.length);
        while(m<l1.length && n<l2.length)
        {
                if(l1.elem[m].power<l2.elem[n].power)
                {
                        l->elem[l->length].coefficient = l1.elem[m].coefficient;
                        l->elem[l->length].power = l1.elem[m].power;
                        m++;
                        l->length++;
                }
                else if(l1.elem[m].power>l2.elem[n].power)
                {
                        l->elem[l->length].coefficient = l2.elem[n].coefficient;
                        l->elem[l->length].power = l2.elem[n].power;
                        n++;
                        l->length++;
                }
                else if(l1.elem[m].power==l2.elem[n].power)
                {
                        l->elem[l->length].coefficient = l1.elem[m].coefficient+l2.elem[n].coefficient;
                        l->elem[l->length].power = l2.elem[n].power;
                        m++;
                        n++;
                        l->length++;
                }
        }
        if(m>=l1.length)
        {
                while(n<l2.length)
                {
                        l->elem[l->length].coefficient = l2.elem[n].coefficient;
                        l->elem[l->length].power = l2.elem[n].power;
                        n++;
                        l->length++;
                }
        }
        if(n>=l2.length)
        {
                while(m<l1.length)
                {
                        l->elem[l->length].coefficient = l1.elem[m].coefficient;
                        l->elem[l->length].power = l1.elem[m].power;
                        m++;
                        l->length++;
                }
        }
        return OK;
}
int main(void)
{

        Polynomial *L1;
        Polynomial *L2;
        Polynomial *L;
        initpol(&L1);
        initpol(&L2);
        initpol(&L);
        insertpol(L1);
        insertpol(L2);
        addpol(*L1, *L2, L);
        printf("%d\n",(*L).length);
        displaypol(*L);
        return 0;
}