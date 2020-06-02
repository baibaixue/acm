#include<stdio.h>
int main(){
	int a=0,b=0,c=0,i;
	int n;
	double d;
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
		for(i=0;i<n;i++){
			scanf("%lf",&d);
			if(d<0){
				a++;
			}else if(d==0){
				b++;
			}else{
				c++;
			}
		}
		printf("%d %d %d\n",a,b,c);
		a=0,b=0,c=0;
		}else
		break;
	}
	return 0;
}
