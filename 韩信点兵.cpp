#include<stdio.h>
int main(){
	int a,b,c,k=0;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		int res=0;
		for(int i=10;i<=100;i++){
			if(i%3==a&&i%5==b&&i%7==c){
				res=i;
				break;
			}
		}
		k++;
		printf("Case %d:",k);
		if(res==0){
			printf("No answer\n");
		}else
			printf("%d\n",res);
	}
	return 0;
}
