#include<cstdio> 
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxn 10200
using namespace std;
struct money{
	int num;
	int mm;
	int nn;
}number[maxn];
int cmp(money a,money b){
	if(a.mm==b.mm){
		if(a.nn==b.nn){
			return a.num<b.num;
		}
		return a.nn>b.nn;
	}
	return a.mm>b.mm;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(number,0,sizeof(number));
//		memset(number.num,0,sizeof(number.num));
//		memset(number.nn,0,sizeof(number.nn));
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			number[i].num=i;
			for(int j=0;j<k;j++){
				int a,b;
				scanf("%d%d",&a,&b);
				number[a].mm=number[a].mm+b;
				number[i].mm=number[i].mm-b;
				number[a].nn++;
			}
		}
		sort(number+1,number+n+1,cmp);
		for(int i=1;i<=n;i++){
			printf("%d %.2f\n",number[i].num,(double)number[i].mm/100.0);
		}
	}
	return 0;
}
