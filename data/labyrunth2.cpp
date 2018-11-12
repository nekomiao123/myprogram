#include<bits/stdc++.h>
#define MAX 5
using namespace std;

/*  
 *  x���Թ��еĺ�����
 *  y���Թ��е�������
 *  direction��ʾ�ڵ�ǰ������Ҫ�ߵ���һ������
 *  nextָ����ָ��ջ�е���һ������
 */
typedef struct LNode {
    int x;    
    int y;    
    int direction;
    struct LNode *next;
}LNode;

/*
 * topָ��ָ��ջ�Ķ���
 * ����Ҫbaseָ��
 */
typedef struct {
    LNode *top;
}Stack;

/*
 * IntiStack()
 * ��ʼ��һ��ջ������һ��Stack�ṹ��ĵ�ַ��ṹָ��
 * topָ��ָ��һ��ͷ��㣬��ͷ��㲻�������굫nextָ��ָ��ջ�Ķ���������
 */
void IntiStack(Stack *result){
    result->top = (LNode *)malloc(sizeof(LNode));
    result->top->next = NULL;
}

/*
 * Push()
 * ��һ���µ����������ջ�У���ʹ�õķ��������ڱ�ͷ���뷨
 * ����direction�����ڵ��������һ��Ҫ�ߵķ���
 */ 
void Push(Stack *result, int x, int y, int direction){
    LNode *topNode = (LNode *)malloc(sizeof(LNode));
    topNode->x = x;
    topNode->y = y;
    topNode->direction = direction;
    topNode->next = result->top->next;
    result->top->next = topNode;
}

/*
 * Pop()
 * �ú��������ߵ��Թ�����·ʱ������Լ�����������
 * ����topָ����nextָ����ָ��Ľ�㣬Ҳ����ջ�Ķ����ڵ�
 * �����ڴӱ�ͷɾ��һ���ڵ㣬�����ظýڵ�
 */ 
LNode *Pop(Stack *result){
    LNode *temp = result->top->next;
    if(temp != NULL){
        result->top->next = temp->next;
    }
    temp->next = NULL;
    return temp;
}

void show(Stack *result){
    LNode *temp;
    if(result->top->next != NULL){
        temp = Pop(result);
        show(result);
        cout << "(" << temp->x << "," << temp->y << ")" << endl;
    }
}




int main(void){
    /*
     * MAX��ֵΪ5
     * ����һ����ά����
     * �����Թ�����ֵ������ʼ��һ��ջ
     */ 
    freopen("in2.txt","r",stdin);
    int maze[MAX][MAX];
    int i, j;
    for(i = 0;i < MAX;i++){
        for(j = 0;j < MAX;j++){
            cin>>maze[i][j];
        }
    }
    Stack result;
    IntiStack(&result);

    /*
     * ������һ���Թ�����ʱ������Ӧ�÷ֱ����ĸ������Ƿ���·��
     * �ݶ�direction = 1�� 2�� 3�� 4�ֱ��ʾ�����ϣ�������
     * flagDirection ���ʾ�Ѿ��ҵ�һ�����еķ�������һ���ڱ�
     * row�� col��ʾ��ǰ��������
     * ���Ƚ���0�� 0�������ջ��directionĬ�ϴ�1��ʼ������������һ��˳ʱ���        �����������Ķ�����ʹ���ϰ�Ҳû��ϵ
     * ��Ϊ�Ѿ���������0�� 0����������ǲ���������������԰�������
     * currentָ��ָ��ջ�Ķ����ڵ�
     */ 
    int flagDirect = 1;
    int row = 0;
    int col = 0;
    int direction = 1;
    Push(&result, row, col, direction);
    maze[row][col] = 1;
    LNode *current;

    /*
     * ������һ������ѭ��������ѭ���������ǵ����(4, 4)
     * ���˳ʱ��ı����ĸ�����ͨ��ʹ��switch�жϿ��еķ��򣬵����򲻿��е�        ʱ��direction��1������һ�������Ƿ����
     * ���ǵ����з��򶼲�����ʱ֤�����������Թ��е�һ����·��Ҫ�˻�ȥ
     * ��ʱͨ��Pop������ջ�˻ص���·���ߵ������
     * ֮ǰ���߹����������Ͼ���Ϊ�˲������ظ���·��������·��ѭ����Ҳ�����ջ
     */ 
    while(1){
        if(row == (MAX - 1) && col == (MAX - 1)){
            break;
        }
        flagDirect = 1;
        current = result.top->next;
        row = current->x;
        col = current->y;
        while(flagDirect){
            switch(current->direction){
                case 1:if(col + 1 < MAX && maze[row][col + 1] == 0){
                           maze[row][col] = 1;
                           col++;
                           Push(&result, row, col, 1);
                           flagDirect = 0;
                       }
                       else{
                           current->direction++;
                       }
                       break;
                case 2:if(row + 1 < MAX && maze[row + 1][col] == 0){
                           maze[row][col] = 1;
                           row++;
                           Push(&result, row, col, 1);
                           flagDirect = 0;
                       }
                       else{
                           current->direction++;
                       }
                       break;
                case 3:if(col - 1 >= 0 && maze[row][col - 1] == 0){
                           maze[row][col] = 1;
                           col--;
                           Push(&result, row, col, 1);
                           flagDirect = 0;
                       }
                       else{
                           current->direction++;
                       }
                       break;
                case 4:if(row - 1 >= 0 && maze[row - 1][col] == 0){
                           maze[row][col] = 1;
                           row--;
                           Push(&result, row, col, 1);
                           flagDirect = 0;
                       }
                       else{
                           current->direction++;
                       }
                       break;
                default:Pop(&result);
                        flagDirect = 0;
                        break;
            }
        }
    }
    show(&result);
    return 0;
}
