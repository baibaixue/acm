#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 1005
using namespace std;
int a [maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int the_max=fabs(a[1]-a[0]);
		for(int i=1;i<n;i++){
			if(the_max<fabs(a[i]-a[i-1])){
				the_max=fabs(a[i]-a[i-1]);
			}
		}
		printf("%d\n",the_max);
	}
	return 0;
}
