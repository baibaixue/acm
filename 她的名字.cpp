#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 2002
#define mol (int)(1e9+7)
using namespace std;
char s [maxn];
int local [10][maxn];
int cmp(int a,int b){
	return a>b;
}
int main(){
	while(1){
		memset(local,0,sizeof(local));
		char c;
		if(scanf("%c",&c)!=EOF){
			if(c!='\n'){
				s[0]=c;
				local[(int)c-'0'][0]=0;
			}
			for(int i=1;;i++){
				char c;
				scanf("%c",&c);
				if(c!='\n'){
					s[i]=c;
					local[(int)c-'0'][i]=i;
				}else{
					break;
				}
			}
			for(int i=0;i<10;i++){
				sort(local[i],local[i]+maxn,cmp);
			}
			int q;
			scanf("%d",&q);
			int sum=0;
			while(q--){
				int n;
				scanf("%d",&n);
				int x,y;
				scanf("%1d%1d",&x,&y);
				if(n>2){
					for(int i=0;local[y][i]!=0;i++){
						for(int j=0;local[x][j]!=0;j++){
							if(local[x][j]<local[y][i]){
								sum+=zuhe(local[x][j]*(n-2));
								sum=sum%mol;
							}
						}
					}
					printf("%d\n",sum);
				}
				else if(n==2){
					for(int i=0;local[y][i]!=0;i++){
						for(int j=0;local[x][j]!=0;j++){
							if(local[x][j]<local[y][i]){
								sum++;
							}
						}
					}
					printf("%d\n",sum);
				}
				else if(n==1){
					printf("0\n");
				}
			}
		}
	}
	return 0;
}

