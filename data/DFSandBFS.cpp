#include <bits/stdc++.h>

/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100 /* ��󶥵�����Ϊ100 */
#define INFINITYT 65535   /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;      /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;  /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;   /* ����洢������������Ϊ�ַ��� */

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

MGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӾ��� */
    /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITYT;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    E->Weight = 1;
    /* ����� <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* ��������ͼ����Ҫ�����<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

bool visited[MaxVertexNum] = {false};

void DFS(MGraph Graph, Vertex V)
{
    Vertex j;
    visited[V] = true;
    printf("%d ",V);
    for(j=0;j<Graph->Nv;j++)
    {
        if(!visited[V]&&Graph->G[V][j])
        {
            DFS(Graph,V);
        }
    } 
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);        /* ���붥����� */
    Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

    scanf("%d", &(Graph->Ne)); /* ������� */
    if (Graph->Ne != 0)
    {                                           /* ����б� */
        E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
        /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d", &E->V1, &E->V2);
            /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge(Graph, E);
        }
    }
    // /* ������������ݵĻ����������� */
    // for (V=0; V<Graph->Nv; V++)
    //     scanf(" %c", &(Graph->Data[V]));
    for(Vertex i=0;i<Graph->Nv;i++)//DFS����
    {
        if(!visited[i])
        {
            printf("{");
            DFS(Graph,i);
            printf(" }\n");
        }
    }
    return Graph;
}





int main()
{
    BuildGraph();

    return 0;
}
