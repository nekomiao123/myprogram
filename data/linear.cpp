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

//初始化
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
//查找
Position Find(List L,ElementType X)
{
    Position i = 0;
    while(i<=L->Last&&L->Data[i]!=X)
    {
        i++;
    }
    if(i>L->Last) return ERROR;//没找到返回Error
    else return i;//找到返回储存位置
}

bool Insert(List L,ElementType X,Position P)
{
    Position i;
    if(L->Last == MAXSIZE-1)
    {
        printf("表满");
        return false;
    }
    if(P<0||P>L->Last+1)
    {
        printf("输入不合法");
        return false;
    }
    for(i=L->Last;i>=P;i--){
        L->Data[i+1] = L->Data[i];//将p以及以后的元素顺序向后移动
    }
    L->Data[P] = X; //新元素插入
    L->Last++;//Last指向最后元素
    return true;
}

bool Delete(List L,Position P)
{
    Position i;

    if(P<0||P>L->Last)
    {
        printf("位置不合法");
        return false;
    }

    for(i=P+1;i<=L->Last;i++)
    {
        L->Data[i-1] = L->Data[i];
    }
    L->Last--;
    return true;
}





