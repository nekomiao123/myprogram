#include<stdio.h>
#include<string.h>

int main()
{
    char a[100000],b[100000];
    gets(a);
    gets(b);
    int al,bl;
    al = strlen(a);
    bl = strlen(b);
    for(int i=0;i<al;i++)
    {
        int flag = 0;
        for(int j=0;j<bl;j++)
        {
            if(a[i]==b[j])
            {
                flag = 1;
                break;
            }
        }
        if(!flag){

            printf("%c",a[i]);
        }
    }
    printf("\n");
    return 0;
}
