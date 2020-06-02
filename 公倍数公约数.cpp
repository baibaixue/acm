//求最小公倍数 和 最大公约数 
		int x;
		while(B!=0){
			x=A%B;
			A=B;
			B=x;
		}
