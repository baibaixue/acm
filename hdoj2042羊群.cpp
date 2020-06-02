#include<stdio.h>
int main(){
	int n,a,m;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d",&a);
			m=3;
			for(int i=0;i<a;i++){
				m=(m-1)*2;
			}
			printf("%d\n",m);
		}
	}
	return 0;
}
