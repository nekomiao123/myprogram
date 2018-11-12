/*ѧϰ����ʽ�ļӷ���˷�������ʵ��*/


#include <bits/stdc++.h>
using namespace std;

typedef struct PolyNode *Polynomial;

struct PolyNode{
    int coef;  //ϵ��
    int expon; //ָ��
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

    P = (Polynomial)malloc(sizeof(struct PolyNode));       //�����µĿռ�����ż������������
    P->coef = c;
    P->expon = e;
    P->link = NULL;

    (*pRear)->link = P;                                    //���˽ڵ����Rear�����������
    *pRear = P;                                             //��Rear�ڵ����һλ
}
//��������
Polynomial ReadPoly()
{
    Polynomial P,t,Rear;
    int N,c,e;

    P = (Polynomial)malloc(sizeof(struct PolyNode));   //����һ���սڵ㷽��������㣬�����ж�Rear�Ƿ�Ϊ��
    P->link = NULL;
    Rear = P;

    cin>>N;
    while(N--)
    {
        cin>>c>>e;
        Attach(c,e,&Rear);                             //����һ���ڵ���룬&Rear���ô�ָ��ĵ�ַ�ķ�ʽ���ı���ֵ
    }
    t = P;                                            
    P = P->link;
    free(t);                                           //�ͷ�����սڵ�
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
    Polynomial P,Rear,P1,P2,t;                               //Ҫ����ʱ����������ָ����Ȼ�Ժ���Ҳ���ͷָ����
    int c,e;
    c = 0;
    e = 0;
    P1 = T1;
    P2 = T2;

    P = (Polynomial)malloc(sizeof(struct PolyNode));     //����һ���սڵ����ڷ����������
    P->link = NULL;
    Rear = P;

    if (!T1) return T2;
    if (!T2) return T1;
    if(!T1&&!T2) return NULL;
    while(P1&&P2)                                        //P1��P2�����ڵ�ʱ��
    {
        if(P1->expon==P2->expon)                          //ָ�����ʱϵ����ӣ�ָ�����䣬�Ž�����
        {
            c = P1->coef + P2->coef;
            e = P2->expon;
            if(c){
                Attach(c,e,&Rear);
            }
            P1 = P1->link;
            P2 = P2->link;

        }else if(P1->expon>P2->expon)                    //P1��ָ������P2��ָ��
        {
            c = P1->coef;
            e = P1->expon;
            Attach(c,e,&Rear);
            P1 = P1->link;
        }else if(P1->expon<P2->expon)                     //P1��ָ��С��P2��ָ��
        {
            c = P2->coef;
            e = P2->expon;
            Attach(c,e,&Rear);
            P2 = P2->link;
        }
    }
    while(P1)                                             //P1�����ڣ��ͰѺ����˳��ȫ����������
    {
        Attach(P1->coef,P1->expon,&Rear);
        P1 = P1->link;
    }
    while(P2)                                              //P2�����ڣ�Ҳ����ͬ�Ĳ���
    {
        Attach(P2->coef,P2->expon,&Rear);
        P2 = P2->link;
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}

//ʹ�ö�����ӵķ���
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

//ʹ�ö������ķ���
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





