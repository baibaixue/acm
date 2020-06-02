#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long A(long long x){
	long long int l=0,r=pow(2.0,20.0);
	long long int m;
	while(l<r){
		m=(l+r)/2;
		long long int mid=(m*(m+1)*(2*m+1)/6+m*(m+1)/2)/2;
		if(x<=mid){
			r=m;
		}else{
			l=m+1;
		}
	}
	return l;
} 
long long int B(long long int x){
	long long int l=0,r=pow(2.0,20.0);
	long long int m;
	while(l<r){
		m=(l+r)/2;
		long long int mid=(m*(m+1)/2);
		if(x<=mid){
			r=m;
		}else{
			l=m+1;
		}
	}
	return l;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long s;
		while(n--){
			scanf("%lld",&s);
			long long a,b,c;
			a=A(s);
			s=s-(a*(a-1)*(2*a-1)/6+a*(a-1)/2)/2;
			b=B(s);
			c=s-(b*(b-1)/2);
			printf("%lld %lld %lld\n",a,b,c);
		}
	}
	return 0;
}


