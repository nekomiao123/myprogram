#include <bits/stdc++.h>

using namespace std;

// typedef struct SNode *Stack;

// struct SNode{
//     ElementType Data[Maxsize];
//     int Top;
// };

int fact(int n)
{
    cout<<"��"<<n<<endl;
    if(n<=1)
        return 1;
    else 
        {cout<<"��"<<n<<endl;
        return n*fact(n-1);}
    
}

int main()
{
    fact(4);
    return 0;
}