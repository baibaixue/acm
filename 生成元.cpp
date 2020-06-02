#include<stdio.h>
#include<string.h>
# define max 100005
int main(){
	int a[max];
	int t,n;
	memset(a,0,sizeof(a));
	for(int i=1;i<max;i++){
		int x=i,y=i;
		while(x>0){
			y+=x%10;
			x/=10;
		}
		if(a[y]==0||i<a[y]){
			a[y]=i;
		}
	}
		scanf("%d",&t);
		while(t--){
			scanf("%d",&n);
			printf("%d\n",a[n]);
		}
	return 0;
}
