#include<stdio.h>
int main(){
	int m;
	double a,b,c;
	while(scanf("%d",&m)!=EOF){
		while(m--){
			scanf("%lf%lf%lf",&a,&b,&c);
			if(a+b>c&&b+c>a&&a+c>b){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
