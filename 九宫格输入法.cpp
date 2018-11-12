#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10][10]={"0 ","1,.?!","2ABC","3DEF","4GHI","5JKL","6MNO","7PQRS","8TUV","9WXYZ"};
    int b[10]={2,5,4,4,4,4,4,5,4,5};
    char c,d;
    int flag = 0;
    do{
        c = getchar();
        if(c!=' '&&c!='\n')
        {
            d = c;
            flag++;
        }else
        {
            cout<<a[d-'0'][(flag-1)%b[d-'0']];
            flag = 0;
        }

    }while(c!='\n');

    return 0;
}
