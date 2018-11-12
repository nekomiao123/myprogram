#include <bits/stdc++.h>

using namespace std;
typedef int ElementType;
typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Position;
struct TreeNode{
    ElementType data;
    SearchTree Left;
    SearchTree Right;
};

SearchTree 
MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position find(SearchTree T,ElementType x)
{
    if(!T) return NULL;
    if(x<T->data)
        return find(T->Left,x);
    else if(x>T->data)
        return find(T->Right,x);
    else 
        return T;
}

Position IterFind(SearchTree T,ElementType x)
{
    while(T)
    {
        if(x<T->data)
            T = T->Left;
        else if(x>T->data)
            T = T->Right;
        else 
            return T;
    }
    return NULL;
}


Position Findmin(SearchTree T)
{
    if(!T)return NULL;
    else if(!T->Left)
        return T;
    else
        return Findmin(T->Left);
}


Position FindMax(SearchTree T)
{
    if(T){
        while(T->Right)
            T = T->Right;
    }
    return T;
}

SearchTree
Insert(ElementType x,SearchTree T)
{
    if(T == NULL)
    {
        //create and return a one-node tree
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if(T == NULL)
            cout<<"Out of Space!";
        else
        {
            T->data = x;
            T->Left = T->Right = NULL;
        }
    }
    else 
    {
        if(x<T->data){
            T->Left = Insert(x,T->Left);
        }else if(x>T->data)
        {
            T->Right = Insert(x,T->Right);
        }
    }
    return T;

}







