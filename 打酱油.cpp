#include<cstdio>
int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		int ans=0;
		while(a>0){
			if(a>=50){
				ans+=7;
				a=a-50;
			}else if(a>=30){
				ans+=4;
				a=a-30;
			}else if(a>=10){
				ans+=a/10;
				a=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
