#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int m;
	while(scanf("%d",&m)!=EOF&&m){
		int ans;
		int a;
		scanf("%d",&a);
		ans=a;
		for(int i=1;i<m;i++){
			scanf("%d",&a);
			ans=ans^a;
		}
		if(ans!=0){
			printf("Rabbit Win!\n");
		}else{
			printf("Grass Win!\n");
		}
	}
	return 0;
}
