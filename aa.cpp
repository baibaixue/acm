#include<cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n%m==0){
			printf("0\n");
		}else{
			printf("1\n");
		}
	}
} 
