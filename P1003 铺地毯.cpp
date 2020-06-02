#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 1005
using namespace std;
int map[maxn][maxn]; 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,g,k;
		scanf("%d%d%d%d",&a,&b,&g,&k);
		for(int j=a;j<=a+g;j++){
			for(int m=b;m<=b+k;m++){
				map[j][m]=i;
			}
		}
	}
	int x,y;
	scanf("%d%d",&x,&y);
	if(map[x][y]!=0){
		printf("%d\n",map[x][y]);
	}else{
		printf("-1\n");
	}
	return 0;
}
