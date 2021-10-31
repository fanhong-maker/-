//树的链式存储结构，孩子兄弟表示法
#include<stdio.h>
#include<stdlib.h>

#define OK 0

typedef struct 
{
        /* data */
}elemtype;
typedef struct Ltreenode
{
        elemtype data;
        struct Ltreenode* firstchild,*nextbro;  //first用于指向第一个孩子结点，nextbro用于指向第一个兄弟结点
}Ltreenode;

int main()
{
        return 0;
}