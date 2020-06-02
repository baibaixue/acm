#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 220
#define inf 0x3f3f3f3f
using namespace std;
struct node{
	int id;
	double cap;
	double x,y,z;
	double dis;
};
node send[maxn];
node receive[maxn];
int matchsend[maxn];
int matchreceive[maxn];
vector<node> rank_send[maxn];
vector<node> rank_receive[maxn];
int C;
double distance(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
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
			scanf("%f%f%f%f",&send[i].cap,&send[i].x,&send[i].y,&send[i].z);
		}
		for(int i=1;i<=C;i++){
			scanf("%d",&receive[i].id);
			scanf("%f%f%f%f",&receive[i].cap,&receive[i].x,&receive[i].y,&receive[i].z);
			for(int j=1;j<=C;j++){
				send[j].dis=distance(receive[i],send[j]);
				rank_receive[i].push_back(send[j]);
			}
			sort(rank_receive[i].begin()+1,rank_receive[i].end(),cmp);
		}
	}
}

