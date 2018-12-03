#include <bits/stdc++.h>

/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100 /* 最大顶点数设为100 */
#define INFINITYT 65535  /* ∞设为双字节无符号整数的最大值65535*/
#define ERROR -1
typedef int Vertex;     /* 用顶点下标表示顶点,为整型 */
typedef int WeightType; /* 边的权值设为整型 */
typedef char DataType;  /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;     /* 有向边<V1, V2> */
    WeightType Weight; /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                                   /* 顶点数 */
    int Ne;                                   /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
    DataType Data[MaxVertexNum];              /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */

/* 邻接矩阵存储 - Prim最小生成树算法 */

//返回未被收录的顶点中dist最小者
Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
    Vertex MinV, V;
    WeightType MinDist = INFINITY;

    for (V = 0; V < Graph->Nv; V++)
    {
        //若V未被收录，并且dist[V]更小
        if (dist[V] != 0 && dist[V] < MinDist)
        {
            MinDist = dist[V]; //更新最小距离
            MinV = V;          //更新对应顶点
        }
    }
    if (MinDist < INFINITY) //找到最小dist
        return MinV;
    else
        return ERROR; //没找到最小dist
}
int Prim(MGraph Graph, LGraph MST)
{
    WeightType dist[MaxVertexNum], TotalWeight;
    Vertex parent[MaxVertexNum], V, W;
    int VCount;
    Edge E;

    //初始化
    for (V = 0; V < Graph->Nv; V++)
    {
        dist[V] = Graph->G[0][V];
        parent[V] = 0;
    }

    TotalWeight = 0;
    VCount = 0;
    MST = CreateGraph(Graph->Nv);
    E = (Edge)malloc(sizeof(struct ENode));

    dist[0] = 0;
    VCount++;
    parent[0] = -1;

    while (1)
    {
        V = FindMinDist(Graph, dist);
        if (V == ERROR)
            break;

        E->V1 = parent[V];
        E->V2 = V;
        E->Weight = dist[V];
        InsertEdge(MST, E);
        TotalWeight += dist[V];
        dist[V] = 0;
        VCount++;

        for (W = 0; W < Graph->Nv; W++) //对于图中的每个顶点W
        {
            if (dist[W] != 0 && Graph->G[V][W] < INFINITY)
            //若W是V的邻接点，并且未被收录
            {
                if (Graph->G[V][W] < dist[W])
                //若收录V后dist[W]变小
                {
                    dist[W] = Graph->G[V][W];
                    //更新dist[W]
                    parent[W] = V;
                }
            }
        }
    }
    //若MST收录的顶点不到V个，说明图不连通
    if (VCount < Graph->Nv)
        TotalWeight = ERROR;
    return TotalWeight;
}