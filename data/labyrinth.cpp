/*
*ʹ��DFS��ջʵ���Թ�����
*
*/
#include<iostream>
#define EORRE -1
#define MAX 10  //�Թ�����к���
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

int maze[MAX][MAX];  //�Թ�
int visit[MAX][MAX]; //��¼�Ƿ񱻷��ʹ�
int n,m;             //�к���
int count;           //·������

int dir[4][2] = {
    {-1,0},{1,0},{0,-1},{0,1}
};  //��ʾ��������

Stack path = CreatStack();//path��·


void dfs(int x,int y)
{
    if(x==n-1 && y==m-1)//˵���ҵ���·
    {
        cout << "**************·��"<<++count<<  "**************" << endl;
		show(path);
        return ; 
    }

    if(x<0||x>=n||y<0||y>=m) //Խ��
        return ;

    //��һ��˵�������Թ���
    //���ĸ�����̽��
    for(int i=0;i<4;i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(0<=nx && nx<n && 0<=ny && ny<m && maze[nx][ny]==0 && visit[nx][ny]==0)
		{//������nx,nyû�г��磬maze[nx][ny]=0����㲻���ϰ������ߣ�visit[nx][ny]=0˵��(nx,ny)û�з��ʹ������Է���
            visit[nx][ny] = 1;
            //����Ϊ���ʹ�
            Push(nx,ny,path);
            //������ջ
            dfs(nx,ny); 
            //��һ��̽��
            visit[nx][ny] = 0;
            //����
            Pop(path);
            //����ǰ���˻�ȥ
        }
    }
}

int main()
{
    count = 0;
    freopen("in.txt","r",stdin);
    Push(0,0,path);

    //�����ջ

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
        //cout<<"ջΪ��";
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





