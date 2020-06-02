#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)  {
	if(a%b!=0){
		return gcd(b,a%b);
	}else{
		return b;
	}
}
int main()
{
  int a, b, c;
  while(scanf("%d%d%d",&a,&b,&c)!=EOF&&(a!=0||b!=0||c!=0)){
    a=a/gcd(b,c);
    if(a&1){
    	printf("NO\n");
	}else{
		printf("%d\n",a-1);
	}
  }
  return 0;
}
