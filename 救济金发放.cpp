#include<stdio.h>
#define max 22
int r[max];
int n,k,m;
int quit(int x,int y,int z){
	while(z--){
		do{
			x=(x+y+n-1)%n+1;
		}while(r[x]==0);
	}
	return x;
	
}
int main(){
	while(scanf("%d%d%d",&n,&k,&m)==3&&n){
		for(int i=1;i<=n;i++){
			r[i]=i;
		}
		int a=n,b=1;
		int left=n;
		while(left>0){
			a=quit(a,1,k);
			b=quit(b,-1,m);
			if(a==b){
				printf("%d",a);
				left--;
				r[a]=0;
			} 
			if(a!=b){
				printf("%d %d",a,b);
				left=left-2;
				r[a]=r[b]=0;
			}
			if(left!=0) printf(",");
		}
		printf("\n");
	}
	return 0;
}
