/*
1.分为上三角和下三角，上三角的思路是同蛇形矩阵（不完全） 
注意应该判断前面对角线个数的奇偶性来确定是前面对角线之和加行还是列；奇加行，偶加列； 
2.至于下三角则需要用到对称的思想： 
首先易推知a[i][j]的对称式为a[n+1-i][n+1-j],如5阶矩阵中a[2][5]对称式a[4][1]， 
其次根据对称的两对数之和等于n*n+1, 
*/


for (i=1;i<=n;i++)
    for (j=1;j<=n+1-i;j++)//每一行打印多少个元素
    {
        k=i+j-2;
        sum=(k+1)*k/2;
        if (k%2)//如果前面的对角线个数是奇数
            a[i][j]=sum+i;
        else
           a[i][j]=sum+j;
    }


for (i=1;i<=n;i++)
        for (j=1;j<=n+1-i;j++)     //每一行打印多少个元素
     {
         k=i+j-2;                  //算出它之前有几条对角线
         sum=(k+1)*k/2;            //前k条对角线的和，那么加上列数就是第(i,j)的值
         if (j==n+1-i)             //如果是每一行的最后一列，那么要换行
            printf("%d\n",sum+j);
         else
            printf("%d ",sum+j);
     }



int num = 1;
int total = n*n;
for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i % 2 == 0)
                a[j][i - j] = num++;
            else
                a[i - j][j] = num++;
        }
    }

for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i%2==0)
                a[n - 1 - j][n - 1 - i + j] = total--;
            else
                a[n - 1 - i + j][n - 1 - j] = total--;
        }
    }
}

