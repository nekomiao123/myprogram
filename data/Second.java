

public static int sum0_plus(int x) {
		int i=2,sum0=0;
		while(x!=1) {
			for(i=2;x%i!=0;++i);//�ó�x����С������
			sum0+=i;
			x=x/i;//��x��ȥ������	
		}
		return sum0;
	}//��������λ��֮��


