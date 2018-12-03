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


/* �ڽӾ���洢 - Prim��С�������㷨 */

//����δ����¼�Ķ�����dist��С��
Vertex FindMinDist(MGraph Graph,WeightType dist[])
{ 
    Vertex MinV,V;
    WeightType MinDist = INFINITY;

    for(V=0;V<Graph->Nv;V++)
    {
        if(dist[V]!=0&&dist[V]<MinDist)
        {
            MinDist = dist[V];
            
        }
    }
}
