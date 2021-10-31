//用邻接矩阵建立图 (有向网)
#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define FALSE -1
#define status int
#define MAXVALUE 32767          //表示无穷大,网（有权图）用无穷大，图用0
#define MAXNUM 100              //最大顶点个数
typedef char Vertextype;         //设顶点的数据类型为字符型
typedef int Arctype;             //弧的数据类型为整型
typedef struct
{
        Vertextype vexs[MAXNUM];        //顶点表
        Arctype arcs[MAXNUM][MAXNUM];   //邻接矩阵
        int vexnum, arcnum;             //当前顶点数，和边数
}AMGraph;       //邻接矩阵

Arctype locatevex(Vertextype, AMGraph);
status initgraph(AMGraph*);
status creatgraph(AMGraph*);

Arctype locatevex(Vertextype v, AMGraph g)
{
        for(int i=0; i<g.vexnum; i++)
        {
                if(g.vexs[i] == v)
                {
                        return i;
                }
        }
        return -1;
}
status initgraph(AMGraph* g)
{
        printf("请输入vexnum：");
        scanf("%d", &g->vexnum);
        printf("please input arcnum：");
        scanf("%d", &g->arcnum);
        for(int i=0; i<g->vexnum; i++)
        {
                printf("请输入第%d个顶点：",i+1);
                getchar();
                scanf("%c", &g->vexs[i]);
        }
        for(int i=0; i<g->vexnum;i++)
        {
                for(int j=0; j<g->vexnum; j++)
                {
                        g->arcs[i][j] = MAXVALUE;
                }
        }
        return OK;
}
status creatgraph(AMGraph* g)
{
        Vertextype vi, vj;
        Arctype w;
        int i;
        int j;
        for(int n = 0; n < g->arcnum; n++)
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
                scanf("%d", &w);
                g->arcs[i][j] = w;    
                g->arcs[j][i] = w;    //无向网
        }       
        return OK;
}
//递归算法实现邻接矩阵图的遍历
/*本算法是领悟递归算法的重要案例，切记*/
/*深度优先遍历的思想，沿着条路径，当遇到都没访问过的顶点时，随机访问一个顶点
直到访问到的顶点的邻接顶点都已访问过，此时依次退回上一个顶点，退回的过程中，
看是否有未访问的邻接顶点，若有继续访问，如此，直到退回到初始顶点则访问完毕*/
/*深度优先遍历类似于树的先序遍历，可用递归算法实现。其主要思想是访问某顶点后，
对其为任一访问的邻接顶点访问，直到某一顶点的邻接结点都访问了（这里恰好对应分治法的思想），
则退回，退回步骤恰好对应于递归的先入后出规律*/
status DFS(AMGraph g, int i)    //v为遍历入口         
{
        static int visited[6] = {0};           //辅助矩阵
        printf("%c->",g.vexs[i]);
        visited[i] = 1;
        for(int j=0; j<g.vexnum; j++)
        {
                if(g.arcs[i][j] != 32767 && visited[j]==0)
                {
                       DFS(g, j);
                }
        }
}
int main()
{
        AMGraph g;
        initgraph(&g);
        creatgraph(&g);
        DFS(g, 1);
        return 0;
}