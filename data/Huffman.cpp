#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4//带权值的叶子节点数或者是需要编码的字符数
#define M 2*N-1//n个叶子节点构造的哈夫曼树有2n-1个结点
#define MAX 10000
typedef char TElemType;
//静态三叉链表存储结构
typedef struct{
	//TElemType data;
	unsigned int weight;//权值只能是正数
	int parent;
	int lchild;
	int rchild;
}HTNode;//, *HuffmanTree;
typedef HTNode HuffmanTree[M+1];//0号单元不使用

typedef char ** HuffmanCode;//存储每个字符的哈夫曼编码表，是一个字符指针数组，每个数组元素是指向字符指针的指针