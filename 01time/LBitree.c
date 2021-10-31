//链式存储结构的二叉树，递归算法访问二叉树
#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define FALSE 1
#define status int

typedef struct
{
        char data;
}elemtype;
typedef struct Binode
{
        elemtype data;
        struct Binode* rchild;
        struct Binode* lchild;
}Binode, *Bitree;
typedef struct TriTnode
{
        elemtype data;
        struct TriTnode* rchild;
        struct TriTnode* lchild; 
        struct TriTnode* parent;
}TriTnode, *Tritree;
status preordertraverse(Bitree t)       //先序遍历
{
        if(t == NULL)
        {
                //printf("树为空！\n");
                return OK;
        }
        else
        {
                printf("%c  ", t->data.data);
                preordertraverse(t->lchild);    //递归调用
                preordertraverse(t->rchild);    //递归调用
        }
}
status inordertraverse(Bitree t)        //中序遍历
{
        if(t == NULL)
        {
                //printf("树为空！\n");
                return OK;
        }
        else
        {
                inordertraverse(t->lchild);
                printf("%c  ", t->data.data);
                inordertraverse(t->rchild);
        }
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
status buildtree(Binode** t)      //先序遍历实现二叉树的创建，递归创建：创建根结点，创建根节点的左结点，创建根节点的右结点，如此递归
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
        //char data = t->data.data;
        if((*t)->data.data == '#')
        {
                *t = NULL;
                return 0;
        }
        buildtree(&(*t)->lchild);
        buildtree(&(*t)->rchild);
        return OK;
}
status copytree(Bitree t, Bitree* new_t)        //将二叉树t复制到new_t
{
        if(t == NULL)
        {
                return 0;
        }
        else
        {
                *new_t = (Bitree)malloc(sizeof(Bitree));
                (*new_t)->data = t->data ;
                copytree(t->lchild,&(*new_t)->lchild);
                copytree(t->rchild,&(*new_t)->rchild);
        }
}
int countnode(Bitree t)         //计算二叉树节点个数
{
        if(t == NULL)
        {
                return 0;
        }
        else
        {
                return (countnode(t->lchild) + countnode(t->rchild) +1);
        }
}
int depth(Bitree t)             //记录二叉树的深度
{
        int m,n;
        if(t == NULL)
        {
                return 0;
        }
        else
        {
                m = depth(t->lchild);
                n = depth(t->rchild);
                if(m>n)return m+1;
                else return n+1;
        }
}
int countlead(Bitree t)
{
        if(t == NULL)
        {
                return 0;
        }
        if(t->lchild == NULL && t->rchild == NULL)
        {
                return 1;
        }
        return  countlead(t->lchild) + countlead(t->rchild);
}
int main()
{
        Bitree t = NULL;        //Bitree是一个指向Binode的一级指针
        Bitree new_t = NULL;    //存储复制后的二叉树
        int num;                //记录二叉树的节点数
        int deep_num;              //记录二叉树的深度
        int lead_num;           //记录叶子的数量
        buildtree(&t);          //先序遍历创建ABC##DEG###F###的二叉树，
        preordertraverse(t);    //输出ABCDEGF
        puts("");
        // inordertraverse(t);     //输出CBGEDFA
        // puts("");
        // postordertraverse(t);   //输出CGEFDBA
        // puts("");
        copytree(t, &new_t);
        preordertraverse(t);
        puts("");
        num = countnode(t);
        printf("二叉树的节点个数：%d\n",num);
        deep_num = depth(t);
        printf("二叉树的深度：%d\n",deep_num);
        lead_num = countlead(t);
        printf("二叉树的叶子数量为：%d\n",lead_num);
        return 0;
}