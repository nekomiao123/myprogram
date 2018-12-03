#include<iostream>
#include<stdlib.h>
#include<string.h> 
#include <algorithm>
#define MINDATA -10000 
#define ERROR -1
#define SIZE 10
using namespace std;

typedef struct Haff* HaffNode;
struct Haff{
	int weight;//Ȩ�أ���¼�ַ����ִ���
	char data;//���ַ�����
	HaffNode lchild;//����
	HaffNode rchild;//�Һ���
};

typedef struct HNode *Heap;//�ѵ�����
struct HNode{
	HaffNode *Data;  //����Ԫ�ص�����
	int Size;        //���е�ǰԪ�ظ���
	int Capacity;    //�ѵ��������
};
typedef Heap MinHeap;
char code[256][50];//�ö�ά�����������ַ��Ĺ��������룬���е�һά���±��ʾ��������ַ���ASCII��  


void swap(HaffNode *a,HaffNode *b)
{
	HaffNode tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//����MaxSize�Ŀյ���С��
MinHeap CreateHeap(int MaxSize)
{
	
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (HaffNode*)malloc((MaxSize+1)*sizeof(HaffNode));
	for(int i=0;i<=MaxSize;i++)
	{
		H->Data[i] = (HaffNode)malloc(sizeof(struct Haff));
	}
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0]->weight = MINDATA;//�ڱ�
	H->Data[0]->lchild = NULL;
	H->Data[0]->rchild = NULL;
	return H;
}
//�ж϶��Ƿ�Ϊ��
bool IsFull(MinHeap H)
{
	return (H->Size==H->Capacity);
}
//�ж϶��Ƿ�Ϊ��
bool IsEmpty(MinHeap H)
{
	return (H->Size==0);
}
//ɾ����С�Ѷ���Ԫ�ز��ҷ���
HaffNode DeleteMin(MinHeap H)
{
	int parent,child,X;
	HaffNode MinItem;

	if(IsEmpty(H))
	{
		cout<<"��С����Ϊ��";
		return 0;
	}

	MinItem = (HaffNode)malloc(sizeof(struct Haff));
	MinItem->weight = H->Data[1]->weight;
	MinItem->data = H->Data[1]->data;
	MinItem->lchild = H->Data[1]->lchild;
	MinItem->rchild = H->Data[1]->rchild;
	X = H->Data[H->Size--]->weight;
	
	for(parent=1;parent*2<=H->Size;parent=child)
	{
		child = parent*2;
		if((child!=H->Size)&&(H->Data[child]->weight>
		H->Data[child+1]->weight))
			child++;
		if(X<H->Data[child]->weight)
			break;
		else{
			H->Data[parent]->weight = H->Data[child]->weight;
			H->Data[parent]->data = H->Data[child]->data;
			H->Data[parent]->lchild = H->Data[child]->lchild;
			H->Data[parent]->rchild = H->Data[child]->rchild;
		}
	}
	H->Data[parent]->weight = X;
	H->Data[parent]->data = H->Data[H->Size+1]->data;
	H->Data[parent]->lchild = H->Data[H->Size+1]->lchild;
	H->Data[parent]->rchild = H->Data[H->Size+1]->rchild;
	return MinItem;
}

//������С��
void MinHeapadjust(MinHeap H,int parent)
{
	int t = parent;//����һ��parent��ֵ
	int temp = H->Data[parent]->weight;
    int child = 0;
    for (; parent * 2 <= H->Size; parent = child) {
        child = parent * 2;
        if ((child != H->Size) && 
            (H->Data[child+1]->weight < H->Data[child]->weight)) {
            child++;//���ҽڵ��С��
        }
        if (temp <= H->Data[child]->weight) {
            break;
        }
        else {
            H->Data[parent]->weight = H->Data[child]->weight;
			H->Data[parent]->data = H->Data[child]->data;
			H->Data[parent]->lchild = H->Data[child]->lchild;
			H->Data[parent]->rchild = H->Data[child]->rchild;
			//swap(&H->Data[parent],&H->Data[child]);
        }
    }
    H->Data[parent]->weight = temp;
	H->Data[parent]->data = H->Data[t]->data;
	H->Data[parent]->lchild = H->Data[t]->lchild;
	H->Data[parent]->rchild = H->Data[t]->rchild;
}
//������С��
void buildMinHeap(MinHeap minHeap) {
    for (int i = minHeap->Size / 2; i > 0; i--) {
        MinHeapadjust(minHeap, i);
    }
}
//������С��
void printMinHeap(MinHeap minHeap) {
    if (minHeap == NULL) {
        cout << "The min heap is not created." << endl;
        return;
    }
    for (int i = 0; i < minHeap->Size; i++) {
        cout << minHeap->Data[i+1]->weight << " ";
		//cout<<"d"<<minHeap->Data[i+1]->data<<"d"<<" ";
    }
    cout << endl;
}
//����С���в�������
void insert(MinHeap minHeap,HaffNode node)
{
	if (minHeap == NULL) {
        cout << "��Ϊ��" << endl;
        return;
    }
    if (IsFull(minHeap)) {
        cout << "������" << endl;
        return;
    }

	int i = ++(minHeap->Size);
	for (; minHeap->Data[i / 2]->weight > node->weight; i /= 2) {
        minHeap->Data[i]->weight = minHeap->Data[i / 2]->weight;
		minHeap->Data[i]->data = minHeap->Data[i/2]->data;
        minHeap->Data[i]->lchild = minHeap->Data[i / 2]->lchild;
        minHeap->Data[i]->rchild = minHeap->Data[i / 2]->rchild;
    }
	minHeap->Data[i]->data = node->data;
    minHeap->Data[i]->weight = node->weight;
    minHeap->Data[i]->lchild = node->lchild;
    minHeap->Data[i]->rchild = node->rchild;

}
//������������
HaffNode buildHuffmanTree(MinHeap H)
{
	HaffNode T = NULL;
	buildMinHeap(H);
	//cout<<"H->Size"<<H->Size<<endl;
	//cout<<"H->Capacity"<<H->Capacity<<endl;
	int tmp = H->Size;
	//Size��ѭ��ʱ�������ˣ���������ʹ��tmp��¼�����sizeֵ
	for(int i=0;i<tmp-1;i++)
	{
		T = (HaffNode)malloc(sizeof(struct Haff));
		T->lchild = DeleteMin(H);
		T->rchild = DeleteMin(H);
		T->weight = T->lchild->weight+T->rchild->weight;
		insert(H,T);
	}
	T = DeleteMin(H);
	return T;
}
//���������������
void preOrderTraverse(HaffNode head) {
    if (head) {
        cout << head->weight << " ";
		// if(head->data)
		// 	cout<<"d"<<head->data<<"d"<<" ";
        preOrderTraverse(head->lchild);
        preOrderTraverse(head->rchild);
    }
}

void coding(HaffNode Node,char* keep,int length)
{	
	if(Node->lchild==NULL&&Node->rchild==NULL){
		keep[length] = '\0';
		strcpy(code[Node->data-'0'],keep);
		return;
	}
	cout<<"zheng";
	keep[length] = '0';
	coding(Node->lchild,keep,length+1);
	keep[length] = '1';
	coding(Node->rchild,keep,length+1);
}
int main() {
	char keep[50];//������ʱ����
	// HaffNode node[100];//����������ڵ�
	// for(int i=0;i<100;i++)
	// {
	// 	node[i] = (HaffNode)malloc(sizeof(struct Haff));
	// }
    MinHeap minHeap = NULL;
    minHeap = CreateHeap(SIZE);
    for (int i = 0; i <SIZE; i++) {
        minHeap->Data[i+1]->weight = SIZE - i;
		minHeap->Data[i+1]->data = '0'+ SIZE - i;
        minHeap->Data[i+1]->lchild = NULL;
        minHeap->Data[i+1]->rchild = NULL;
        minHeap->Size++;
    }
	for(int i=0;i<SIZE;i++)
	{
		cout<<minHeap->Data[i+1]->data<<" ";
	}
	cout<<endl;

	//�Բ�������ĳ���
	// HaffNode node = NULL;
	// node = (HaffNode)malloc(sizeof(struct Haff));
	// node->data = '2';
	// node->weight = 11;
	// node->lchild = node->rchild = NULL;
	//insert(minHeap,node);
	
    cout << "ԭʼ�������У�" << endl;
    printMinHeap(minHeap);
    buildMinHeap(minHeap);
    cout << "��С���������У�" << endl;
    printMinHeap(minHeap);

    HaffNode huffumanTree = buildHuffmanTree(minHeap);
    cout << "������������������У�" << endl;
    preOrderTraverse(huffumanTree);
    cout << endl;

	// coding(huffumanTree,keep,0);
	// int i=0;
	// while(code[49][i]!='\0'){
	// 	cout<<code[49][i];
	// 	i++;
	// }
	
    return 0;
}

