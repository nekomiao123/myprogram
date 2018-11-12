#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef int ElementType;

typedef struct TreeNode *BinTree;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreOderTraversal(BinTree BT)
{
    if(BT)
    {
        cout<<BT->Data<<endl;
        PreOderTraversal(BT->Left);
        PreOderTraversal(BT->Right);
    }
}





int main(int argc, char const *argv[])
{
    
    return 0;
}
