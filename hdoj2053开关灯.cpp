#include<cstdio>
#include<string.h>
const int max=100020;
int c[max];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(c,0,sizeof(c));
		int count=0;
		for(int i=1;i<=n;i++){
			if(n%i==0){
				count++;
			}
		}
		if(count%2==0){
			c[n]=0;
		}else{
			c[n]=1;
		}
		printf("%d\n",c[n]);
	}
	return 0;
}
