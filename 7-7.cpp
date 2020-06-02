#include<cstdio>
#include<cmath>
int main(){
	int n;
	char c;
	while(scanf("%d%*c",&n)!=EOF){
		scanf("%c",&c);
		int h;
		if(n%2!=0){
			h=n/2+1;
		}else{
			h=n/2;
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<n;j++){
				printf("%c",c);
			}
			printf("\n");
		}
	}
	return 0;
}
