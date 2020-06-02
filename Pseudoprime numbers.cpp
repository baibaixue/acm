#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int is_prime(long long int a){
	if(a<=1){
		return 0;
	}else if(a%2==0){
		return 0;
	}
	for(int j=3;j<=sqrt(a);j+=2){
		if(a%j==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	long long int p,a;
	while(scanf("%lld%lld",&p,&a)!=EOF){
		if(p==0&&a==0){
			break;
		}else{
			if(is_prime(p)==1){
				printf("no\n");
			}else{
				long long int t=a;
				long long int r=p;
				long long int d=1;
				while(r>0){
					if(r%2==1){
						d=(d*t)%p;
					}
					r/=2;
					t=t*t%p;
				}
				if(a==d){
					printf("yes\n");
				}else{
					printf("no\n");
				}
			}
		}
	}
	return 0;
}
