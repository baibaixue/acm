#include<stdio.h>
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	int n,s=0,t=0;
	while(scanf("%d",&n)==1){
		s+=n;
		t++;
		printf("%d  ",t);
	}
	printf("%d %.3f\n",s,(double)s/t);
	return 0;
}
