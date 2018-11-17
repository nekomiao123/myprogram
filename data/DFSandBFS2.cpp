#include <stdio.h>
#include <string.h>
#define MAX 10
int visit[MAX] = {0};
int G[MAX][MAX];

void DFS(int i,int N)
{
    int j;
    visit[i] = 1;
    printf(" %d",i);
    for(j=0;j<N;j++)
    {
        if(!visit[j]&&G[i][j])
        {
            DFS(j,N);
        }
    }
}

void BFS(int i,int N)
{
    int queue[MAX],rear,front,v,j;
    rear = front = -1;
    visit[i] = 1;
    queue[++rear] = i;
    while(front<rear)
    {
        v = queue[++front];
        printf(" %d",v);
        for(j=0;j<N;j++)
        {
            if(!visit[j]&&G[v][j])
            {
                visit[j] = 1;
                queue[++rear] = j;
            }
        }
    }
}


int main()
{
    int N,E,i,x,y;
    scanf("%d %d",&N,&E);
    memset(visit,0,sizeof(visit));
    for(i=0;i<E;i++)
    {
        scanf("%d %d",&x,&y);
        G[x][y] = G[y][x] = 1;
    }
    //DFS
    for(i=0;i<N;i++)
    {
        if(!visit[i])
        {
            printf("{");
            DFS(i,N);
            printf(" }\n");
        }
    }
    memset(visit,0,sizeof(visit));
    //BFS
    for(i=0;i<N;i++)
    {
        if(!visit[i])
        {
            printf("{");
            BFS(i,N);
            printf(" }\n");
        }
    }
}