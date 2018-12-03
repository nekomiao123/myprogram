#include <bits/stdc++.h>

/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100 /* ��󶥵�����Ϊ100 */
#define INFINITYT 65535  /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
#define ERROR -1
typedef int Vertex;     /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType; /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;  /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;     /* �����<V1, V2> */
    WeightType Weight; /* Ȩ�� */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                                   /* ������ */
    int Ne;                                   /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
    DataType Data[MaxVertexNum];              /* �涥������� */
    /* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */

/* �ڽӾ���洢 - Prim��С�������㷨 */

//����δ����¼�Ķ�����dist��С��
Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
    Vertex MinV, V;
    WeightType MinDist = INFINITY;

    for (V = 0; V < Graph->Nv; V++)
    {
        //��Vδ����¼������dist[V]��С
        if (dist[V] != 0 && dist[V] < MinDist)
        {
            MinDist = dist[V]; //������С����
            MinV = V;          //���¶�Ӧ����
        }
    }
    if (MinDist < INFINITY) //�ҵ���Сdist
        return MinV;
    else
        return ERROR; //û�ҵ���Сdist
}
int Prim(MGraph Graph, LGraph MST)
{
    WeightType dist[MaxVertexNum], TotalWeight;
    Vertex parent[MaxVertexNum], V, W;
    int VCount;
    Edge E;

    //��ʼ��
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

        for (W = 0; W < Graph->Nv; W++) //����ͼ�е�ÿ������W
        {
            if (dist[W] != 0 && Graph->G[V][W] < INFINITY)
            //��W��V���ڽӵ㣬����δ����¼
            {
                if (Graph->G[V][W] < dist[W])
                //����¼V��dist[W]��С
                {
                    dist[W] = Graph->G[V][W];
                    //����dist[W]
                    parent[W] = V;
                }
            }
        }
    }
    //��MST��¼�Ķ��㲻��V����˵��ͼ����ͨ
    if (VCount < Graph->Nv)
        TotalWeight = ERROR;
    return TotalWeight;
}