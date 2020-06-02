#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int no_zero(int x){
	int ans=x;
	while(ans%10==0){
		ans=ans/10;
	}
	printf("no_zero(%d)=%d\n",x,ans%10);
	return ans%10;
//	double m=log10(x);
//	m=m-(int)m;
//	int ans=(int)pow(10.0,m);
//	ans=ans%10;
//printf("no_zero(%d)=%d\n",x,ans);
//	return ans;
}
int  main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int answ=1;
		for(int i=1;i<=n;i++){
			answ=no_zero(answ)*i;
		}
		printf("%d\n",answ);
	}
}
