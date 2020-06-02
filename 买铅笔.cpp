#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a1,b1;
	int a2,b2;
	int a3,b3;
	scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
	int a,b,c;
	if(n%a1==0){
		a=n/a1*b1;
	}else if(n%a1!=0){
		a=n/a1*b1+b1;
	}if(n%a2==0){
		b=n/a2*b2;
	}else if(n%a2!=0){
		b=n/a2*b2+b2;
	}if(n%a3==0){
		c=n/a3*b3;
	}else if(n%a3!=0){
		c=n/a3*b3+b3;
	}
	int ans=min(a,b);
	ans=min(ans,c);
	printf("%d\n",ans);
	return 0;
}
