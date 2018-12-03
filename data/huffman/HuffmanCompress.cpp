#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//����һ���������ڵ㣬���Ǹ��ṹ��
struct haffNode{
	int weight;//Ȩ�أ���������ַ����ֵĸ������������ڵ��Ǹ����ڵ�Ļ� �����������ӽڵ�Ȩ�صĺ� 
	char data;//����������ַ����������ַ���'c'��data='c'; 
	struct haffNode *leftChild=NULL,*rightChild=NULL;//���������ӽڵ�ָ�� 
}; 
char code[256][50];//�ö�ά�����������ַ��Ĺ��������룬���е�һά���±��ʾ��������ַ���ASCII��  
haffNode left[50];//�����������е����ӽڵ� 
haffNode right[50];//�����������е����ӽڵ� 
unsigned char saveChar = 0; //��������������ļ�����Ϊchar������1���ֽڣ�����ÿ8λ����һ�� ,������unsigned�޷����ͣ��������λ���� 
unsigned char slidChar;//����һ���ַ����ã���Ӧ�Կ�����Ҫ�Ĳ��� 
//������,��һ�������ǹ������Ľڵ����飬�ڶ���������ĳ��ȣ�������ð������ 
void sort(haffNode* node,int length){
	int i,j; 
	haffNode t;
	for(i=0; i<length-1; i++){
		for(j=i+1; j<length-i-1;j++){
			if(node[j].weight < node[j+1].weight){
				t = node[j];
				node[j] = node[j+1];
				node[j+1] = t;
			}
		}
	} 
} 
//������������ 
void creatHaffman(haffNode *node,int length){
	if(length==1){
	return; //������鳤��Ϊ1��������ݹ飬����ľͲ���ִ�� 
	}
	sort(node,length);	//��node���鰴��weight�Ӵ�С���� 
	haffNode parent;//���ɸ��ڵ㣬��Ϊ���ǵ�����Ӵ�С������ˣ��������������ľ�����С�Ľڵ� 
	left[length] = node[length-2],right[length]=node[length-1];//�������ֽڣ��������������������ڵ� 
	parent.weight = left[length].weight + right[length].weight;//���ڵ��Ȩ�ص��������ӽڵ�� Ȩ��
	//���������ӽڵ�,��Ϊparent.leftChild��ָ�����ͣ����Ը�ֵ��ʱ��Ҫ��& 
	parent.leftChild= &left[length];
	parent.rightChild = &right[length]; 
	//��������������ӽڵ��޳������ɸ��ڵ㣬Ȼ��ݹ鴴���������Ĳ��� 
	node[length-2] = parent;
	creatHaffman(node,length-1); 
}
//�����ַ��Ĺ��������� ,��һ�������ǹ����������ڵ㣬�ڶ����������������ַ����飬�������������ַ�����ĳ��ȣ���0��ʼ 
void coding(haffNode *node,char *keepCode,int length){
	//����ڵ�û���ӽڵ㣬��˵������Ҷ�ڵ㣬���������code������ 
	if(node->leftChild == NULL || node->rightChild == NULL){
		keepCode[length] ='\0';//������һ����ֹ�����γ�һ���������ַ��������㿽�����Է�������֮ǰ�ı��롣 
		strcpy(code[node->data-0],keepCode);//����strcpy���������ַ���������code���±��ýڵ���ַ�(data)-0�õ� 
		return; 
	}
	keepCode[length] = '0';
	coding(node->leftChild,keepCode,length+1);
	keepCode[length] = '1';
	coding(node->rightChild,keepCode,length+1);
} 
//��ѹ��  
haffNode* unzip(haffNode *node,int flag){
	if(flag == 0)
	return node->leftChild;
	if(flag == 1)
	return node->rightChild;
} 
int main(){
    int count[128]={0};//����ͳ���ַ�������һ��ʼ���㣬���������±�ű�ʾ����ַ���ASCII��
    char keepCode[50];//���������ɱ����ʱ�� ��ʱ������� �������������ĵط��������������code[][]���� 
    char reder;//�������ļ��е��ַ� 
    int fileLength=0;//��������ԭ�ĳ��� 
    int zipLength=0;//��������ѹ���ĳ��� 
    int i; 
    int num=0;//����������ֵ��ַ��ĸ��� ������һЩ�������� 
    haffNode node[100];//��������������ڵ㣬����������100���ռ���ʵ�ϲ���Ҫ��ô�󣬴����Ҫ26+26+20��26��Ӣ����ĸ��Сд+�����ţ� 
	FILE *fpr = fopen("text.txt","r");//�����ļ�������input.txt��·����Ҫ�Լ����ã������Լ�����һ���ı���дһЩӢ�Ľ�ȥ 
	FILE *fpw = fopen("output1","wb");//д���ļ���wb��д��������ļ���·���������⣬����Ҫ���ϸ�ʽ��д���ʱ���ļ��Զ����ɡ�
	FILE *fpr1= fopen("output1","rb");;//���ڽ�ѹ��ʱ�����ļ� ��rb�Ƕ���������ļ� 
	FILE *fpw1 = fopen("output3.txt","w"); //���ڽ�ѹ��ʱд���ļ� 
	//��ѹ��Ҫ�õ� 
	char op;
	haffNode *z;
	//��ȡ�ļ� 
	while((reder=fgetc(fpr))!=EOF){//һ��һ���ض����ַ� 
		fileLength ++;//ÿ����һ����ԭ�ĳ���+1 
		count[reder-0]++;//reder-0���Եõ��ַ���ASCII��,Ȼ���ۼ�ͳ�� 
	} 
	//ѭ�����飬��ΪASCII������255���ַ���������������Щ�ַ�����ȫû�г��ֹ��ģ�����Ҫ�����ֹ��Ĵ���charNode����� 
	for(i=0; i<128; i++){
		if(count[i]!=0){
			node[num].data=i;//֮ǰ˵�����±���ǳ��ֵ��ַ���ASCII��
			node[num].weight=count[i];//count[i]��ľ����ַ����ֵĴ���
			num++;//������1 
		}
	}
	//������������
	creatHaffman(node,num); 
	//�������������
	coding(&node[0],keepCode,0); 
	//���ݹ����������ԭ�����ı�ѹ������ 
	//��ȡ�ļ� 
	num=0;//���� 
	fseek(fpr,0L,0);//��Ϊ�����Ѿ������ļ��ˣ�fprָ���Ѿ������ƶ����������ʹ�� fseek������ָ�븴ԭ����0���ļ���ʼλ�ã�0L����0���ֽڣ��� 
	while((reder=fgetc(fpr))!=EOF){ //һ��һ���ض����ַ� 
		for(i=0; i<strlen(code[reder-0]); i++){
			saveChar |= code[reder-0][i]-'0';//��saveChar�ͱ����е�ÿһλ���л���������ַ���'1'-'0'���Ϳɵõ�0000 0001.     
			num++;
			if(num == 8){
				fwrite(&saveChar,sizeof(char),1,fpw);//ÿ8λд��һ���ļ�
				zipLength++; 
				saveChar = 0;//������0 
				num=0;
			} 
			else{
				saveChar = saveChar << 1	; //ÿ����һ����������һλ  
			}
		}
	} 
	//������ʣ��ı��벻��8λ�������Ƶ������
	if(num != 8){
		saveChar = saveChar<<(8-num);//�Ƶ������ 
		fwrite(&saveChar,sizeof(char),1,fpw);
		zipLength++;
	} 
	fclose(fpr);
	fclose(fpw);
	//���ݹ����������ѹ��,��Ҫ˼���Ǹ��ݱ�������������� 
	num=0;//�����ѹ������ļ����� 
	z = &node[0];
	while(fread(&reder,sizeof(char),1,fpr1)){
		//�����ѹ���ĳ��ȵ���ԭ�ĳ��ȣ�ֹͣ��ѹ����Ϊʲô����һ����������Ϊ�ڱ���ѹ����ʱ����ܳ���ʣ��ı��벻��8λ�����������8λ����8λ�󣬺���Ĳ�λ������ɸ��� 
		if(fileLength == num){
			break;
		} 
		op = 128;//1000 0000
		for(i=0; i< 8; i++){
		slidChar = reder & op;
		reder = reder << 1;
		slidChar = slidChar >>7;
		z = unzip(z,slidChar-0);
		if(z->leftChild == NULL || z->rightChild == NULL){
			fprintf(fpw1,"%c",z->data);
			num++;//ÿд��һ���ַ�+1 
			z = &node[0];
		}
	}
	}
	fclose(fpr1);
	fclose(fpw1);
	//����ѹ����	
	printf("ԭ�ļ���%dK\n",fileLength/1024+1);
	printf("ѹ����ɣ���鿴output1��%dK\n",zipLength/1024+1); 
	printf("��ѹ����ɣ���鿴output3.txt:\%dK\n",fileLength/1024+1); 
	printf("ѹ���ʣ�%.2f%%\n",(float)(fileLength-zipLength)/fileLength*100);	
    return 0;
    } 
