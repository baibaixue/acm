#include<stdio.h>
long long c(int n,int m){
	long long int ans=1;
	if(m<n-m){
		m=n-m;
	}
	for(int i=m+1;i<=n;i++){
		ans*=i;
	}
	for(int j=1;j<=n-m;j++){
		ans/=j;
	}
	return ans;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		printf("%d\n",c(n,m));
	}
	return 0;
} 
