#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 10000005
using namespace std;
int boy[maxn];
int num[maxn];
int find(int x){
	if(boy[x]==-1){
		return x;
	}
		else{
			int r=find(boy[x]);
			boy[x]=r;//µÝ¹éÑ¹ËõÂ·¾¶ 
			return r;
		}
//	while(r!=boy[r]){
//		r=boy[r];
//	}//³¬Ê± 

}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<maxn;i++){
			boy[i]=-1;
			num[i]=1;
		}
		for(int i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
				a=find(a);
				b=find(b);
				if(a!=b){
					boy[a]=b;
					num[b]+=num[a];
				}
		}
//		for(int i=1;i<=n;i++){
//			num[find(i)]++;
//		}
		int max=0;
		for(int i=1;i<maxn;i++){
			if(num[i]>max){
				max=num[i];
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
