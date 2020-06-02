#include<cstdio>
int main(){
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		int h,m;
		m=c*60+d-a*60-b;
		h=m/60;
		m=m%60; 
		printf("%d %d\n",h,m);
	}
	return 0;
}
