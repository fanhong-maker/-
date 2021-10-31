//树的存储结构，
#include <sdtio.h>
#include <stdlib.h>
#define OK 0
#define MAXSIZE 100
typedef struct
{

}elemtype;
typedef struct pnode
{
        elemtype data;
        int parent;     //用于存放父结点的位置
}pnode;
typedef struct
{
        pnode sqbitree[MAXSIZE];
        int r, n;       //r用于存放根节点的地址，n用于存放现有结点数
}Bitree;
int main()
{
        SqBitree bt;    //声明顺序存储的二叉树变量bt
        return OK;
}