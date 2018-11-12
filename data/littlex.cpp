#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char SElemType;
typedef int status;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}Sqstack;

status initstack(Sqstack &S){
    S.base=(SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

status stackempty(Sqstack S){
    if(S.base==S.top) return OK;
    else return ERROR;
}

status pop(Sqstack &S,SElemType &e){
    //pop操作之前先判空
     if(S.base=S.top) return ERROR;
     else e=*(--S.top);
     return OK;}

status push(Sqstack &S,SElemType e){//push操作之前先判满
     if(S.top-S.base>=S.stacksize) {
        S.base=(SElemType*)realloc(S.base,sizeof(SElemType)*(S.stacksize+STACKINCREMENT));
        if(!S.base) exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
     }
     *S.top=e;
     S.top++;
     return OK;}

int main(){
    SElemType ch,e;
    Sqstack S;
    initstack(S);

    printf("请输入您需要倒置的序列！\n");
    // scanf("%c",&ch);
    push(S,'a');
    pop(S,e);

    printf("%c ",e);
    /*while(ch!='@')
    {
     push(S,ch);
     scanf("%c",&ch);}
     
    pop(S,e);
     
    while(!stackempty(S))
    {
     pop(S,e);
     printf("%c  ",e);}
     */
     return 0;
     }
