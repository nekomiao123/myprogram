#include<bits/stdc++.h>
#define MAX 5
using namespace std;

/*  
 *  x是迷宫中的横坐标
 *  y是迷宫中的纵坐标
 *  direction表示在当前坐标内要走的下一个方向
 *  next指针则指向栈中的下一个坐标
 */
typedef struct LNode {
    int x;    
    int y;    
    int direction;
    struct LNode *next;
}LNode;

/*
 * top指针指向栈的顶部
 * 不需要base指针
 */
typedef struct {
    LNode *top;
}Stack;

/*
 * IntiStack()
 * 初始化一个栈，传入一个Stack结构体的地址或结构指针
 * top指针指向一个头结点，该头结点不包含坐标但next指针指向栈的顶部坐标结点
 */
void IntiStack(Stack *result){
    result->top = (LNode *)malloc(sizeof(LNode));
    result->top->next = NULL;
}

/*
 * Push()
 * 将一个新的坐标结点放入栈中，所使用的方法类似于表头插入法
 * 其中direction是现在的坐标点下一步要走的方向
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
 * 该函数用于走到迷宫的死路时向后退以及遍历输出结点
 * 弹出top指针中next指针所指向的结点，也就是栈的顶部节点
 * 类似于从表头删除一个节点，并返回该节点
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
     * MAX的值为5
     * 定义一个二维数组
     * 输入迷宫的数值，并初始化一个栈
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
     * 当处于一个迷宫结点的时候，我们应该分别检测四个方向是否有路走
     * 暂定direction = 1， 2， 3， 4分别表示东，南，西，北
     * flagDirection 则表示已经找到一个可行的方向，它是一个哨兵
     * row， col表示当前结点的坐标
     * 首先将（0， 0）结点入栈，direction默认从1开始，它还将经过一次顺时针遍        历，所以它的东方向即使是障碍也没关系
     * 因为已经遍历过（0， 0）这个点我们不会再走这个点所以把它堵上
     * current指针指向栈的顶部节点
     */ 
    int flagDirect = 1;
    int row = 0;
    int col = 0;
    int direction = 1;
    Push(&result, row, col, direction);
    maze[row][col] = 1;
    LNode *current;

    /*
     * 设置了一个无限循环，跳出循环的条件是到达点(4, 4)
     * 如何顺时针的遍历四个方向？通过使用switch判断可行的方向，当方向不可行的        时候direction加1测试下一个方向是否可行
     * 但是当所有方向都不可行时证明该坐标是迷宫中的一条死路需要退回去
     * 这时通过Pop操作出栈退回到有路可走的坐标点
     * 之前把走过的坐标点堵上就是为了不再走重复的路避免在死路里循环，也方便出栈
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
