#include<cstdio>
int c[10000];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a,b,count=0;
		b=n;
		for(int i=0;;i++){
			a=b%2;
			b=b/2;
			c[i]=a;
			count++;
			if(b==0){
				break;
			}
		}
		for(int i=count-1;i>=0;i--){
			printf("%d",c[i]);
		}
		printf("\n");
	}
	return 0;
}
