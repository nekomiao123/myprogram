#include <stdio.h>

void swap(int &x,int &y);

int main()
{
    int x=10;
    int y=2;
    printf("%d %d\n",x,y);
    swap(x,y);
    printf("After\n");
    printf("%d %d\n",x,y);
    return 0;
}

void swap(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}