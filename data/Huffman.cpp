#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4//��Ȩֵ��Ҷ�ӽڵ�����������Ҫ������ַ���
#define M 2*N-1//n��Ҷ�ӽڵ㹹��Ĺ���������2n-1�����
#define MAX 10000
typedef char TElemType;
//��̬��������洢�ṹ
typedef struct{
	//TElemType data;
	unsigned int weight;//Ȩֵֻ��������
	int parent;
	int lchild;
	int rchild;
}HTNode;//, *HuffmanTree;
typedef HTNode HuffmanTree[M+1];//0�ŵ�Ԫ��ʹ��

typedef char ** HuffmanCode;//�洢ÿ���ַ��Ĺ������������һ���ַ�ָ�����飬ÿ������Ԫ����ָ���ַ�ָ���ָ��