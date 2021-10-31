//通过邻接表建立图(有向网)
#include<stdio.h>
#include<stdlib.h>
#define MAXVNUM 100
#define OK 0
#define status int

typedef char Vertextype;
typedef struct Arcnode          //定义弧的信息
{
        int adjvex;
        struct Arcnode *nextarc;
        int info;
}Arcnode;
typedef struct Vnode            //定义表的信息
{
        Vertextype data;        //顶点信息
        Arcnode* firstarc;      //指向邻接顶点
}Vnode, Adjlist[MAXVNUM];       //定义邻接表时，Vnode v[MAXVNUM] 相当于 Adjlist v
typedef struct 
{
        Adjlist vertics;
        int vexnum, arcnum;     //定点数和弧的数
}ALGraph;
int locatevex(Vertextype v, ALGraph g)
{
        for(int i=0; i < g.vexnum; i++)
        {
                if(g.vertics[i].data == v)
                {
                        return i;
                }
                else 
                {
                        return -1;
                }
        }
}
status initgraph(ALGraph* g)            //图的初始化
{
        printf("please input vexnum:");
        scanf("%d",&g->vexnum);
        printf("please input arcnum");
        scanf("%d",&g->arcnum);
        for(int i=0; i < g->vexnum; i++)
        {
                printf("请输入第%d个顶点：",i+1);
                getchar();
                scanf("%c", &g->vertics[i].data);
                g->vertics[i].firstarc = NULL;
        }
        return OK;
}
status creategraph(ALGraph* g)
{
        Vertextype vi,vj;
        int i,j;
        int info;       //权重值
        for(int n=0; n < g->arcnum; n++)
        {
                printf("输入出顶点和入顶点(格式为A-B)：");
                getchar();
                scanf("%c-%c",&vi,&vj);
                i = locatevex(vi,*g);
                j = locatevex(vj,*g);
                if(i==-1 || j==-1)
                {
                        printf("超出索引范围\n");
                        return FALSE;
                }
                printf("输入%c-%c的权重：",vi,vj);
                scanf("%d", &info);
                Arcnode *temp;
                temp = (Arcnode*)malloc(sizeof(Arcnode));
                temp->adjvex = j;
                temp->info = info;
                temp->nextarc = g->vertics[i].firstarc;
                g->vertics[i].firstarc = temp;
                /*
                Arcnode temp1;
                temp1->adjvex = g->vertics[i];
                temp1->info = info;
                temp1->nextarc = g->vertics[j].firstarc;
                */ //无向网
        }
        return OK;
}
int main()
{
        ALgraph g;
        initgraph(&g);
        creategraph(&g);
        return 0;
}
