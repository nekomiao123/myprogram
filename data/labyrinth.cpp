/*
*使用DFS与栈实现迷宫问题
*
*/
#include<iostream>
#define EORRE -1
#define MAX 10  //迷宫最大行和列
using namespace std;

typedef int ElementType;
typedef struct SNode *Stack;

struct SNode{
    ElementType x;
    ElementType y;
    struct SNode *Next;
};

Stack CreatStack();
bool IsEmpty(Stack S);
void Push(ElementType x,ElementType y,Stack S);
Stack Pop(Stack S);
void show(Stack S);

int maze[MAX][MAX];  //迷宫
int visit[MAX][MAX]; //记录是否被访问过
int n,m;             //行和列
int count;           //路径条数

int dir[4][2] = {
    {-1,0},{1,0},{0,-1},{0,1}
};  //表示上下左右

Stack path = CreatStack();//path记路


void dfs(int x,int y)
{
    if(x==n-1 && y==m-1)//说明找到出路
    {
        cout << "**************路径"<<++count<<  "**************" << endl;
		show(path);
        return ; 
    }

    if(x<0||x>=n||y<0||y>=m) //越界
        return ;

    //这一步说明还在迷宫内
    //从四个方向探测
    for(int i=0;i<4;i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(0<=nx && nx<n && 0<=ny && ny<m && maze[nx][ny]==0 && visit[nx][ny]==0)
		{//条件：nx,ny没有出界，maze[nx][ny]=0这个点不是障碍可以走，visit[nx][ny]=0说明(nx,ny)没有访问过，可以访问
            visit[nx][ny] = 1;
            //设置为访问过
            Push(nx,ny,path);
            //将其入栈
            dfs(nx,ny); 
            //进一步探测
            visit[nx][ny] = 0;
            //回溯
            Pop(path);
            //将当前点退回去
        }
    }
}

int main()
{
    count = 0;
    freopen("in.txt","r",stdin);
    Push(0,0,path);

    //起点入栈

    cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visit[i][j] = 0;
			cin >> maze[i][j];
		}
	}
	dfs(0,0);

    return 0;
}


Stack CreatStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Next==NULL);
}

void Push(ElementType x,ElementType y,Stack S)
{
    Stack Tmp;
    Tmp = (Stack)malloc(sizeof(struct SNode));
    Tmp->x = x;
    Tmp->y = y;
    Tmp->Next = S->Next;
    S->Next = Tmp;
}

Stack Pop(Stack S)
{
    Stack FirstCell;
    Stack top;
    if(IsEmpty(S))
    {
        //cout<<"栈为空";
        return NULL;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        top = (Stack)malloc(sizeof(struct SNode));
        top->x = FirstCell->x;
        top->y = FirstCell->y;
        top->Next = NULL;
        free(FirstCell);
        return top;
    }
}

void show(Stack S)
{
    Stack tmp;
    Stack r;
    Stack t;
    tmp = CreatStack();
    while(!IsEmpty(S))
    {
        r = Pop(S);
        Push(r->x,r->y,tmp);
    }
    while(!IsEmpty(tmp))
    {
        t = Pop(tmp);
        Push(t->x,t->y,S);
        cout << "(" << t->x << "," << t->y << ")" << endl;
    }
}





