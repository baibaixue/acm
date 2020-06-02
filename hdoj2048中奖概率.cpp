//#include<stdio.h> 
//int main(){
//	int n;
//	double c[22]={0,1,0.5,};  
//	while(scanf("%d",&n)!=EOF){
//		for(int i=4;i<22;i++){
//			c[i]=(c[i-1]+c[i-2])*(i-1);
//		}
//		printf("%.2f%\n",c[n]*100);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n,m,i;
	long long a[25];
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		double sum = 1;
		for (i = 1; i <= m; i++)
			sum *= i;
		a[0]=a[1] = 0; a[2] = 1;
		for (i = 3; i <= m; i++)
			a[i] = (i - 1)*(a[i - 1] + a[i - 2]);
		printf("%.2llf%%\n", a[m] / sum*100);
	}
	return 0;
}
