//链表的标准定义模板
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
        
}Elemtype;
typedef struct Lnode
{
        Elemtype data;
        struct Lnode *next;
}Lnode,*linklist;       //用typedef 将struct Lnode数据类型的名字改为Lnode;Linklist是struct Lnode
                        //指针类型的名字，Linklist等同于Lnode* 
int main(void)
{
        return 0;
}