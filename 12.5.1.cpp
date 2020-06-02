#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int num[10]; 
int main(){
	int y,n;
	while(scanf("%d%d",&y,&n)!=EOF){
		for(int i=y;;i++){
			memset(num,0,sizeof(num));
			int x=i;
			int a,b,c,d;
			a=x/1000;num[a]=1;
			x=x%1000;
			b=x/100;num[b]=1;
			x=x%100;
			c=x/10;num[c]=1;
			x=x%10;
			d=x;num[d]=1;
			int k=0;
			for(int j=0;j<10;j++){
					k+=num[j];
			}
			if(k==n){
				printf("%d %04d\n",i-y,i);
				break;
			}
		}
	}
	return 0;
}
