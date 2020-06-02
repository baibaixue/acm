#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int broad[8][8]={
				{1,2,3,4,5,6,7,8},
				{11,12,13,14,15,16,17,18},
				{21,22,23,24,25,26,27,28},
				{31,32,33,34,35,36,37,38},
				{41,42,43,44,45,46,47,48},
				{51,52,53,54,55,56,57,58},
				{61,62,63,64,65,66,67,68},
				{71,72,73,74,75,76,77,78},
				} ;

int step[8][2]={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
int steps[10][10];
int bfs(int a,int b){
	queue<int> Q;
	Q.push(a);
	int x=a/10;
	int y=a%10;
	steps[x][y]=0;
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		int nowa=now/10;
		int nowb=now%10; 
		if(now==b){
			return steps[nowa][nowb];
		}
		for(int i=0;i<8;i++){
			int nexta=nowa+step[i][0];
			int nextb=nowb+step[i][1];
			int next=nexta*10+nextb;
			if(nexta>=0&&nextb>=1&&nexta<=7&&nextb<=8){
				if(steps[nexta][nextb]==-1){
					Q.push(next);
					steps[nexta][nextb]=steps[nowa][nowb]+1;
					//printf("steps[%c][%d]=%d\n",(char)nexta+'a',nextb,steps[nexta][nextb]);
				}
			}
		}
	}
	return -1;
}
int main(){
	char c1,c2;
	int n1,n2;
	int start,end;
	while(scanf("%c",&c1)!=EOF){
		scanf("%d%*c%c%d%*c",&n1,&c2,&n2);
		start=(int)(c1-'a')*10+n1;
		end=(int)(c2-'a')*10+n2;
		memset(steps,-1,sizeof(steps));
		int ans=bfs(start,end);
//		cout<<" ";
//		char c='a';
//		for(int i=0;i<8;i++){
//			printf(" %c",c++);
//		}
//		printf("\n");
//		int k=1;
//		for(int i=0;i<8;i++){
//			printf("%d ",k++);
//			for(int j=1;j<=8;j++){
//				printf("%d ",steps[i][j]);
//			}
//			cout<<"\n";
//		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,n1,c2,n2,ans);
	}
	return 0;
}
