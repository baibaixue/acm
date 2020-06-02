#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cmath>
#define maxn 100000
using namespace std;
int num[maxn];
int ne_xt[maxn];
int mm[maxn];
int anum[maxn];
int bnum[maxn];
int nn[maxn];
int main(){
	int address;
	int N;
	scanf("%d%d",&address,&N);
	int a,b,c;
	int k=1;
	int l=0;
	memset(nn,0,sizeof(nn));
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&a,&b,&c);
		num[a]=b;
		ne_xt[a]=c;
	}
	int before;
	int xbefore;
	anum[0]=address;
	nn[(int)fabs(num[address])]++;
	for(int i=1;ne_xt[address]!=-1;i++){
		if(nn[(int)fabs(num[ne_xt[address]])]==0){
			anum[k++]=ne_xt[address];
			nn[(int)fabs(num[ne_xt[address]])]++;
			address=ne_xt[address];
		}else{
			bnum[l++]=ne_xt[address];
			address=ne_xt[address];
		}
	}
	for(int i=0;i<k-1&&anum[i]!=-1;i++){
		printf("%05d %d %05d\n",anum[i],num[anum[i]],anum[i+1]);
	}
	printf("%05d %d -1\n",anum[k-1],num[anum[k-1]]);
	if(l!=0){
		for(int i=0;i<l-1;i++){
			printf("%05d %d %05d\n",bnum[i],num[bnum[i]],bnum[i+1]);
		}
		printf("%05d %d -1\n",bnum[l-1],num[bnum[l-1]]);
	}
	return 0;
}
