#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long int gongyinshu(long long int n,long long int m){
	if(n==m){
		return 1;
	}
	int a=max(n,m);
	int b=min(n,m);
	long long int x;
	while(b!=0){
		x=a%b;
		a=b;
		b=x;
	}
	return a;
}
int main(){
	long long int n,m;
	while(scanf("%lld%lld",&n,&m)!=EOF){
		long long int ans=n/gongyinshu(n,m)*m;
		printf("%lld\n",ans);
	}
	return 0;
}
//#include <stdio.h>
//int main()
//{
//    int a,b,i,t;
//    while(~scanf("%d%d",&a,&b))
//    {
//    if(a<b)
//    {
//        t=a;
//        a=b;
//        b=t;
//    }
//    for(i=a;;i++)
//    {
//        if(i%a==0&&i%b==0)
//        {
//            printf("%d\n",i);
//            break;
//        }
//    }
//    }
//    return 0;
//}
