#include <bits/stdc++.h>
#define N 10
using namespace std;

bool visited[N] = {false};
int main()
{

    for (int i = 0; i < N; i++)
    {
        visited[2] = true;
        visited[4] = true;
        if (!visited[i])
        {
            cout<<"hhhhhh"<<i<<endl;
        }
    }

    return 0;
}