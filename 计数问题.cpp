#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,x;
	while(scanf("%d%d",&n,&x)!=EOF){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int a=i;
			while(a>0){
				int b=a%10;
				if(b==x){
					cnt++;
				}
				a=a/10;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
