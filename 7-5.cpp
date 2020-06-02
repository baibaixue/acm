#include<cstdio>
int N(int a){
	int m=1;
	for(int j=1;j<=a;j++){
		m*=j;
	}
	return m;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int s=0;
		for(int i=1;i<=n;i++){
			s+=N(i);
		}
		printf("%d\n",s);
	}
	return 0;
}
