#include<cstdio>
#define maxn 10005
int main(){
	int n;
	int num[maxn];
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		num[i]=0;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int l,r;
		int t;
		scanf("%d%d",&l,&r);
		if(l>r){
			t=l;l=r;r=t;
		}
		for(int i=l;i<=r;i++){
			num[i]=1;
		}
	}
	int cnt=0;
	for(int i=0;i<=n;i++){
		if(num[i]==0){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
