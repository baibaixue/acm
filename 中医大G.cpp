#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF){
		int a=(x+2)/3        ;
		if(x<=2){
			printf("No\n");
		}else{
			if(a>=y){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}
	return 0;
}
