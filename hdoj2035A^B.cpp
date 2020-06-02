#include<stdio.h>
#include<math.h>
int main(){
	int a,b,ans;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a!=0||b!=0){
			ans=a;
			for(int i=0;i<b-1;i++){
				ans*=a;
				ans=ans%1000;
			}
			printf("%d\n",ans);
		}
		else
		break;
	}
	return 0;
}
