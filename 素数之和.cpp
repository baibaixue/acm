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
//	printf("������һ���������䣺"); 
//	scanf("%d %d",&m,&n);
//	for(i=m;i<=n;i++){
//		if(isprime(i)){
//			sum+=i;
//			count++;
//		}
		//else{
			//printf("%d����������",x);
		//}
//	}
//	printf("%d��%d֮���������%d��������֮��Ϊ%d��",m,n,count,sum);
//	return 0;
//
//}
