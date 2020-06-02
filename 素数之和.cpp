#include <stdio.h>

int  isprime(int i)
{	int k;
	int a=1; 
	for(k=2;k<i-1;k++){
		if(i%k==0){
			a=0;
			break;
		}
	}
	return a;
}
int main(){
	printf("%d",isprime(41));
	return 0;
}
//	int main()
//{
//	int m,n,i;
//	int sum=0;
//	int count=0;
//	printf("请输入一个整数区间："); 
//	scanf("%d %d",&m,&n);
//	for(i=m;i<=n;i++){
//		if(isprime(i)){
//			sum+=i;
//			count++;
//		}
		//else{
			//printf("%d不是素数。",x);
		//}
//	}
//	printf("%d和%d之间的素数共%d个，素数之和为%d。",m,n,count,sum);
//	return 0;
//
//}
