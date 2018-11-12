#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define MAXSIZE 10

typedef int Position;
typedef struct LNode *List;
typedef int ElementType;

struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

//��ʼ��
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
//����
Position Find(List L,ElementType X)
{
    Position i = 0;
    while(i<=L->Last&&L->Data[i]!=X)
    {
        i++;
    }
    if(i>L->Last) return ERROR;//û�ҵ�����Error
    else return i;//�ҵ����ش���λ��
}

bool Insert(List L,ElementType X,Position P)
{
    Position i;
    if(L->Last == MAXSIZE-1)
    {
        printf("����");
        return false;
    }
    if(P<0||P>L->Last+1)
    {
        printf("���벻�Ϸ�");
        return false;
    }
    for(i=L->Last;i>=P;i--){
        L->Data[i+1] = L->Data[i];//��p�Լ��Ժ��Ԫ��˳������ƶ�
    }
    L->Data[P] = X; //��Ԫ�ز���
    L->Last++;//Lastָ�����Ԫ��
    return true;
}

bool Delete(List L,Position P)
{
    Position i;

    if(P<0||P>L->Last)
    {
        printf("λ�ò��Ϸ�");
        return false;
    }

    for(i=P+1;i<=L->Last;i++)
    {
        L->Data[i-1] = L->Data[i];
    }
    L->Last--;
    return true;
}





