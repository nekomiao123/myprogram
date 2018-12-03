#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define OK         1
#define maxnn 100000
typedef struct student{   //学生类，储存学生的姓名成绩
	char name[10];
	double score;
}student,*pstudent;
typedef struct HTNode{     //赫夫曼树的节点
	student stu;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;
 
void Select(HuffmanTree HT,int i,int &s1,int &s2){  //选出最大的两个节点
	int j,s3;
	double min,min2,max;
	max=min = HT[1].stu.score;
	s1 = 1;
	s3 = 1;
	for (j = 1; j <= i; j++)
	{
		if (min > HT[j].stu.score)
		{
			min = HT[j].stu.score;
			s1 = j;
		}
		if (max < HT[j].stu.score)
		{
			max = HT[j].stu.score;
			s3 = j;
		}
	}
	HT[s1].stu.score = HT[s3].stu.score+1;
	s2 = 1;
	min2 = HT[1].stu.score;
	for (j = 1; j <= i; j++)
	{
		if (min2 >HT[j].stu.score)
		{
			min2 = HT[j].stu.score;
			s2 = j;
		}
	}
	HT[s1].stu.score = min;
}
 
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,pstudent w,int n){  //建立赫夫曼树
	int m;
	int i;
	int s1,s2;
	char *cd;
	int start;
	HuffmanTree p;
	if(n<=1)
		return;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(p=HT+1,i=1;i<=n;i++,p++){
		p->stu.score=w[i].score;
		strcpy(p->stu.name,w[i].name);
	}
	for(;i<=m;i++,p++){
		p->lchild=p->parent=p->rchild=p->stu.score=0;
	}
	for(i=n+1;i<=m;i++){
		Select(HT,i-1,s1,s2);
		HT[s1].parent=HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].stu.score=HT[s1].stu.score+HT[s2].stu.score;
		HT[s1].stu.score=HT[s2].stu.score=maxnn;
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));               //进行赫夫曼编码
	for(i=1;i<=n;i++){  
		cd=(char *)malloc(n*sizeof(char));
		cd[n-1]='\0';
		start=n-1;
		int c=i;
		int f=HT[i].parent;
		for(;f!=0;c=f,f=HT[f].parent){
			if(HT[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		if(start!=0){
			int j;
			for(j=0;j<n-start;j++,start++)
				cd[j]=cd[start];
			cd[j]='\0';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],cd);
	}
	free(cd);
	for(p=HT+1,i=1;i<=n;i++,p++){
		p->stu.score=w[i].score;
		strcpy(p->stu.name,w[i].name);
	}
}
 
int main(){
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	printf("学生人数：");
	scanf("%d",&n);
	pstudent ps;
	ps=(pstudent)malloc((n+1)*sizeof(student));
	printf("姓名   成绩   \n");
	for(int i=1;i<=n;i++)
		scanf("%s %lf",ps[i].name,&ps[i].score);
	HuffmanCoding(HT,HC,ps,n);
	for(int i=1;i<=n;i++){	
		printf("姓名   成绩   赫夫曼编码\n");
		printf(" %s    %.1lf     %s\n",HT[i].stu.name,HT[i].stu.score,HC[i]);
	}
	return OK;
}
