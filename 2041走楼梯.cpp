//#include<stdio.h>
//int main(){
//	int n;
//	int m;
//	while(scanf("%d",&n)!=EOF){
//		while(n--){
//			int count=0;
//			scanf("%d",&m);
//			if(m==1){
//				printf("0\n");
//			}else{
//				for(int i=0;i<=m;i++){
//					for(int j=0;j<=m;j++){
//						if(i*1+j*2==m-1){
//							count++;
//						}
//					}
//				}
//				printf("%d\n",count);
//			}
//		}
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int m,n,i;
	int a[41]={0,0,1,2};
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d",&m);
			for(i=4;i<41;i++)
			a[i]=a[i-1]+a[i-2];
			printf("%d\n",a[m]);
		}
	}
	return 0;
}

