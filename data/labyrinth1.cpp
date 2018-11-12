#include<iostream>
#include<stack>
using namespace std;
 
int maze[10][10];//�Թ�
int vis[10][10];//��¼�Թ��е�ĳ��λ���Ƿ���ʹ�
int n,m;    //�Թ����к���
 
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};//���������ĸ�����

struct point//λ��
{
	int x,y;    
} p;
 
stack<point> path,temp;//��¼·��,temp��һ����ʱ��������pathһ����·��
 
int count;//·������
 
void dfs(int x,int y)//x,y:��ǰλ��
{
	if(x==n-1 && y==m-1)//Ѱ·�ɹ����Թ�---���洦��·������
	{
		cout << "**************·��"<< ++count <<  "**************" << endl;
		while(!path.empty())//��path����ĵ�ȡ����������temp����
		{//path��ջ��-ջ�׵ķ���·���Ǵ��յ�-����˳��
			point p1 = path.top();
			path.pop();
			temp.push(p1);
		}
		while(!temp.empty())
		{//���temp�����·���������պ��Ǵ���㵽�յ��˳��
			point p1 = temp.top();
			temp.pop();
			path.push(p1);//��·���Ż�path���棬��Ϊ���滹Ҫ����!!!
			cout << "(" << p1.x << "," << p1.y << ")" << endl;
		}
		return;
	}
 
	if(x<0 || x>=n || y<0 || y>=m)//Խ��
		return;
	
	//���������һ����˵����û�гɹ���û�г���
	for(int i=0;i<4;i++)//��4������̽��
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];//nx,ny��ѡ��һ������ǰ��һ��֮���µ�����
		if(0<=nx && nx<n && 0<=ny && ny<m && maze[nx][ny]==0 && vis[nx][ny]==0)
		{//������nx,nyû�г��磬maze[nx][ny]=0����㲻���ϰ������ߣ�vis[nx][ny]=0˵��(nx,ny)û�з��ʹ������Է���
			
			vis[nx][ny]=1;//��Ϊ���ʹ�
			p.x = nx;
			p.y = ny;
			path.push(p);//�õ�ǰ���ջ
 
			dfs(nx,ny);//��һ��̽��
 
			vis[nx][ny]=0;//����
			path.pop();//�����ǻ��ݣ����Ե�ǰ�������˻�ȥ�ĵ㣬��Ҫ��ջ
		}
	}
}
 
int main()
{
	count = 0;
	freopen("in.txt","r",stdin);//��ȡ.cpp�ļ�ͬĿ¼�µ���Ϊin.txt���ļ�
 
	p.x = 0;
	p.y = 0;
	path.push(p);//�������ջ
 
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			vis[i][j] = 0;
			cin >> maze[i][j];
		}
	}
	dfs(0,0);
 
	return 0;
}
