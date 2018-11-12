

public static int sum0_plus(int x) {
		int i=2,sum0=0;
		while(x!=1) {
			for(i=2;x%i!=0;++i);//得出x的最小素因数
			sum0+=i;
			x=x/i;//将x除去该因数	
		}
		return sum0;
	}//素因数各位数之和


