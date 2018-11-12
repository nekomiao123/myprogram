/*学习多项式的加法与乘法，链表实现*/


#include <bits/stdc++.h>
using namespace std;

typedef struct PolyNode *Polynomial;

struct PolyNode{
    int coef;  //系数
    int expon; //指数
    Polynomial link; 
};

void Attach(int c,int e,Polynomial *pRear);
Polynomial ReadPoly();
void PrintPoly(Polynomial P);
Polynomial Add(Polynomial T1,Polynomial T2);
Polynomial Mult(Polynomial T1,Polynomial T2);

int main()
{
    Polynomial P1,P2,PP,PS;

    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1,P2);
    PS = Add(P1,P2);
    
    PrintPoly(PP);
    PrintPoly(PS);
    return 0;
}




void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));       //申请新的空间来存放即将加入的数据
    P->coef = c;
    P->expon = e;
    P->link = NULL;

    (*pRear)->link = P;                                    //将此节点放在Rear后面加入链表
    *pRear = P;                                             //将Rear节点后移一位
}
//读入链表
Polynomial ReadPoly()
{
    Polynomial P,t,Rear;
    int N,c,e;

    P = (Polynomial)malloc(sizeof(struct PolyNode));   //申请一个空节点方便后续运算，不用判断Rear是否为空
    P->link = NULL;
    Rear = P;

    cin>>N;
    while(N--)
    {
        cin>>c>>e;
        Attach(c,e,&Rear);                             //将后一个节点加入，&Rear采用传指针的地址的方式来改变其值
    }
    t = P;                                            
    P = P->link;
    free(t);                                           //释放这个空节点
    return P;
}

void PrintPoly(Polynomial P)
{
    int flag = 0;
    if(!P){
    cout<<"0 0"<<endl;
    return ;
    }
    while(P)
    {
        if(!flag)
            flag = 1;
        else 
            cout<<" ";
        cout<<P->coef<<" "<<P->expon;
        P = P->link;
    }
    cout<<endl;
}

Polynomial Add(Polynomial T1,Polynomial T2)
{
    Polynomial P,Rear,P1,P2,t;                               //要用临时变量来往后指，不然以后就找不到头指针了
    int c,e;
    c = 0;
    e = 0;
    P1 = T1;
    P2 = T2;

    P = (Polynomial)malloc(sizeof(struct PolyNode));     //申请一个空节点用于方便后续操作
    P->link = NULL;
    Rear = P;

    if (!T1) return T2;
    if (!T2) return T1;
    if(!T1&&!T2) return NULL;
    while(P1&&P2)                                        //P1与P2都存在的时候
    {
        if(P1->expon==P2->expon)                          //指数相等时系数相加，指数不变，放进链表
        {
            c = P1->coef + P2->coef;
            e = P2->expon;
            if(c){
                Attach(c,e,&Rear);
            }
            P1 = P1->link;
            P2 = P2->link;

        }else if(P1->expon>P2->expon)                    //P1的指数大于P2的指数
        {
            c = P1->coef;
            e = P1->expon;
            Attach(c,e,&Rear);
            P1 = P1->link;
        }else if(P1->expon<P2->expon)                     //P1的指数小于P2的指数
        {
            c = P2->coef;
            e = P2->expon;
            Attach(c,e,&Rear);
            P2 = P2->link;
        }
    }
    while(P1)                                             //P1还存在，就把后面的顺次全部加入链表
    {
        Attach(P1->coef,P1->expon,&Rear);
        P1 = P1->link;
    }
    while(P2)                                              //P2还存在，也作相同的操作
    {
        Attach(P2->coef,P2->expon,&Rear);
        P2 = P2->link;
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}

//使用多项相加的方法
/*Polynomial Mult(Polynomial T1,Polynomial T2)
{
    Polynomial P,P1,P2,Rear,PT,t,PS,Rear1;
    P1 = T1;
    P2 = T2;

    if(!T1||!T2) return NULL;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    
    while(P2)
    {
        Attach(P1->coef*P2->coef,P1->expon+P2->expon,&Rear);
        P2 = P2->link;
        //PT = P;
    }
    t = P;
    P = P->link;
    free(t);

    P1 = P1->link;

    while(P1)
    {
        PT = (Polynomial)malloc(sizeof(struct PolyNode));
        PT->link = NULL;
        Rear1 = PT;
        while(P2)
        {
            Attach(P1->coef*P2->coef,P1->expon+P2->expon,&Rear1);
            P2 = P2->link;
        }
        

    }
    
}*/

//使用多项插入的方法
Polynomial Mult(Polynomial T1,Polynomial T2)
{
    Polynomial P,P1,P2,Rear,PT,t,t1;
    P1 = T1;
    P2 = T2;
    int c,e;

    if(!T1||!T2) return NULL;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    
    while(P2)
    {
        Attach(P1->coef*P2->coef,P1->expon+P2->expon,&Rear);
        P2 = P2->link;
    }
    P1 = P1->link;

    while(P1)
    {
        P2 = T2;
        Rear = P;
        while(P2)
        {
            e = P1->expon+P2->expon;
            c = P1->coef*P2->coef;
            while(Rear->link&&Rear->link->expon>e)
                Rear = Rear->link;
            if(Rear->link&&Rear->link->expon==e)
            {
                if(Rear->link->coef+c)
                    Rear->link->coef += c;
                else{
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }else{
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            P2 = P2->link;
        }
    P1 = P1->link;

    }
    t1 = P;
    P = P->link;
    free(t1);
    return P;
}





