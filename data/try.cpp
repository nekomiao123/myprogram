#include <bits/stdc++.h>

using namespace std;

int main()
{
    double money = 1948721;
    int n = 0;
		while(money!=0)
		{
			n++;
			money = (int)money/10;
		}
		cout<<n<<endl;
}