#include<cstdio>
#include<string.h>
using namespace std;
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			printf("%c",'a'+(i%k));
		}
		
		printf("\n");
	}
	return 0;
}
