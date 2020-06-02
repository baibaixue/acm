#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1010 
using namespace std;
int a[maxn][maxn],c[maxn][maxn],n=1005;
int lowbit(int x){
	return x&(-x);
}
int sum(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			sum+=c[i][j];
		}
	}
	return sum;
}
void inster(int x,int y,int z){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			c[i][j]+=z;
		}
	}
}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){
		printf("Case %d:\n",++T);
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=1;
				inster(i,j,1);
			}
		}
		int m;
		scanf("%d",&m);
		while(m--){
			char s;
			int x1,y1,x2,y2,n1;
			getchar();
			s=getchar();
			if(s=='S'){
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++;x2++;y1++;y2++;
				if(x1>x2){
					swap(x1,x2);
				}
                if(y1>y2){
                	swap(y1,y2);
				}
				printf("%d\n",sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1));
			}
			else if(s=='A'){
				scanf("%d%d%d",&x1,&y1,&n1);
				x1++;y1++;
				inster(x1,y1,n1);
				a[x1][y1]+=n1;
			}
			else if(s=='D'){
				scanf("%d%d%d",&x1,&y1,&n1);
				x1++;y1++;
				if(n1>a[x1][y1]){
					n1=a[x1][y1];
				}
				inster(x1,y1,-n1);
				a[x1][y1]-=n1;
				
			}
			else if(s=='M'){
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n1);
				x1++;y1++;x2++;y2++;
				if(a[x1][y1]>=n1){
					a[x1][y1]-=n1;
					inster(x1,y1,-n1);
					inster(x2,y2,n1);
					a[x2][y2]+=n1;
				}
				else{		
					inster(x1,y1,-a[x1][y1]);
					inster(x2,y2,a[x1][y1]);
					a[x2][y2]+=a[x1][y1];
					a[x1][y1]=0;
				}
			}
		}
	}
	return 0;
}
