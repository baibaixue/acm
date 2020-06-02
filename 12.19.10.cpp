#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 100005
using namespace std;
int num[maxn];
int bei[maxn];
int m[maxn];
int find(int x){
	int r=x;
	int k=1;
	while(r!=num[r]){
		r=num[r];
		k++;
	}
	return k;
} 
//void b(int x){
//	if(num[x]==x){
//		bei[x]=1;
//		return ;
//	}else{
//		bei[x]=b(num[x]);
//	}
//}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		if(num[i]==-1){
			num[i]=i;
		}
	}
	int max=0;
	for(int i=1;i<=n;i++){
		bei[i]=find(i);
		//b(i);
		if(max<bei[i]){
			max=bei[i];
		}
	}
	printf("%d\n",max);
	int aa;
	for(int i=1;i<=n;i++){
		if(bei[i]==max){
			printf("%d",i);
			aa=i;
			break;
		}
	}
	for(int j=aa+1;j<=n;j++){
		if(bei[j]==max)
		printf(" %d",j);
	}
	printf("\n");
	return 0;
}
