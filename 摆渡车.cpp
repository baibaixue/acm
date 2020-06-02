#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 220
using namespace std;
struct node{
	int id;
	int cap;
	double x,y,z;
	double dis;
};
node send[maxn];
node receive[maxn];
int matchsend[maxn];
int matchreceive[maxn];
node rank_send[maxn][maxn];
node rank_receive[maxn][maxn];
int C;
double distance(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
bool cmp(node a,node b){
	if(a.dis==b.dis){
		return a.cap>b.cap;
	}else{
		return a.dis<b.dis;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&C);
		memset(matchsend,0,sizeof(matchsend));
		memset(matchreceive,0,sizeof(matchreceive));
		for(int i=1;i<=C;i++){
			scanf("%d",&send[i].id);
			scanf("%d%lf%lf%lf",&send[i].cap,&send[i].x,&send[i].y,&send[i].z);
		}
		for(int i=1;i<=C;i++){
			scanf("%d",&receive[i].id);
			scanf("%d%lf%lf%lf",&receive[i].cap,&receive[i].x,&receive[i].y,&receive[i].z);
			for(int j=1;j<=C;j++){
				node a,b;
				a.x=1.3;
				a.y=1.4;
				a.z=1.6;
				b.x=1.3;
				b.y=1.4;
				b.z=2.3;
				distance(a,b);
				//printf("%lf %lf",send[j].dis);
				//send[j].dis=distance(receive[i],send[j]);
				//rank_receive[i][j]=send[j];
			}
		//sort(rank_receive[i]+1,rank_receive[i]+1+C,cmp);
		}
	}
}
