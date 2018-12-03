#include<stdio.h>
#include<iostream>
#include<queue> 
#include<string>
using namespace std;
#define MAX 100
 
struct Node{
	int weight;			//Ȩ�� 
	char c;				//�ַ� 
	string code;		     //������ 
	Node *parent,*left,*right;
	//��ʼ�� 
	Node(){
		parent  = left = right = NULL;
		code=""; 
	}
};
 
//����ָ��ȽϺ��� 
struct PCmp
{
    bool operator () (Node const *x, Node const *y)
    {
    	 return x->weight > y->weight;
    }
}; 
 
priority_queue<Node *,vector<Node *>,PCmp>Q;	//��С��
 
//����HuffmanTree 
void CreatHuffmanTree(Node *a[],int n){
	for(int i=0;i<n;i++){
		Q.push(a[i]);
	}	
	Node *parent;
	Node *s1,*s2;
	
	while(Q.empty()==false){
		s1 = Q.top();
		Q.pop();
		if(Q.empty()==true) break;		//��������ֻ��һ��Ԫ�أ�Ҳ�����Ѿ�����HuffmanTree 
		s2 = Q.top();
		Q.pop();
		
		parent=new Node();
		parent->c =' ';
		parent->weight = s1->weight+s2->weight; //����Ȩ�� 
		
		//�趨�ӽڵ� 
		parent->right = s2;
		parent->left = s1; 
		
		//�趨���ڵ� 
		s1->parent = parent;
		s2->parent = parent;
		
		Q.push(parent);
	}
}
 
//Huffman���� 
void HuffmanCode(Node *a[],int n){
	for(int i=0;i<n;i++){
		Node *cur = a[i];
		Node *parent = a[i]->parent;
		string code="";
		
		while(parent!=NULL){	//������ڵ��ʱ�������� 
			if(parent->left==cur) code = "0"+code;
			else code = "1"+code;
			
			//�������һ�� 
			cur = parent;
			parent = parent->parent;
		}
		a[i]->code = code;//��ֵ���� 
	}
} 
 