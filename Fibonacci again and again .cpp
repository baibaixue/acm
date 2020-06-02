#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
using namespace std;
int f[17]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};
int sg[maxn];
int visit[maxn];
void SG(){
	sg[0]=0;
	sg[1]=1;
	for(int i=2;i<maxn;i++){
		memset(visit,0,sizeof(visit));
		for(int j=1;f[j]<=i;j++){
			visit[sg[i-f[j]]]=1;
		}for(int j=0;j<maxn;j++){
			if(visit[j]==0){
				sg[i]=j;
				break;
			}
		}
	}
}
int main(){
	int m,n,p;
	SG();
	while(scanf("%d%d%d",&m,&n,&p)!=EOF&&(m||n||p)){
		int a=sg[m];
		int b=sg[n];
		int c=sg[p];
		if((a^b^c)!=0){
			printf("Fibo\n");
		}else{
			printf("Nacci\n");
		}
	}
	return 0;
}
