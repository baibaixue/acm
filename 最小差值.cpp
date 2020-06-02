#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1005
using namespace std;
int a[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int the_min=a[1]-a[0]; 
		for(int i=1;i<n;i++){
			if(the_min>a[i]-a[i-1]){
				the_min=a[i]-a[i-1];
			}
		}
		printf("%d\n",the_min);
	}
	return 0;
}
