#include<stdio.h>
#include<iostream>
#include<queue> 
#include<string>
using namespace std;
#define MAX 100
 
struct Node{
	int weight;			//权重 
	char c;				//字符 
	string code;		     //解码结果 
	Node *parent,*left,*right;
	//初始化 
	Node(){
		parent  = left = right = NULL;
		code=""; 
	}
};
 
//定义指针比较函数 
struct PCmp
{
    bool operator () (Node const *x, Node const *y)
    {
    	 return x->weight > y->weight;
    }
}; 
 
priority_queue<Node *,vector<Node *>,PCmp>Q;	//最小堆
 
//构造HuffmanTree 
void CreatHuffmanTree(Node *a[],int n){
	for(int i=0;i<n;i++){
		Q.push(a[i]);
	}	
	Node *parent;
	Node *s1,*s2;
	
	while(Q.empty()==false){
		s1 = Q.top();
		Q.pop();
		if(Q.empty()==true) break;		//最后队列中只有一个元素，也就是已经生成HuffmanTree 
		s2 = Q.top();
		Q.pop();
		
		parent=new Node();
		parent->c =' ';
		parent->weight = s1->weight+s2->weight; //设置权重 
		
		//设定子节点 
		parent->right = s2;
		parent->left = s1; 
		
		//设定父节点 
		s1->parent = parent;
		s2->parent = parent;
		
		Q.push(parent);
	}
}
 
//Huffman解码 
void HuffmanCode(Node *a[],int n){
	for(int i=0;i<n;i++){
		Node *cur = a[i];
		Node *parent = a[i]->parent;
		string code="";
		
		while(parent!=NULL){	//到达根节点的时候解码结束 
			if(parent->left==cur) code = "0"+code;
			else code = "1"+code;
			
			//结点向上一层 
			cur = parent;
			parent = parent->parent;
		}
		a[i]->code = code;//赋值编码 
	}
} 
 