#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int num[105];
int x[10002];
int b_search(int i,int n,int k){
	int l=i,r=n;
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(num[m]==k){
			return 1;
		}else if(num[m]<k){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	memset(x,0,sizeof(x));
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int a=num[i]+num[j];
			if(b_search(j+1,n,a)==1){
				x[a]=1;;
			} 
		}
	}
	for(int i=0;i<10002;i++){
		if(x[i]==1){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
