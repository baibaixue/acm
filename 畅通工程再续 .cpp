#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;
int sum[maxn];
struct distant{
	int s;
	int e;
	double dis;
}b[maxn*maxn];
struct local{
	int x;
	int y;
	int note;
}land[maxn];
int find(int x){
	int r=x;
	if(r==land[r].note){
		return r;
	}else{
		return find(land[r].note);
	}
}
void hebing(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		land[b].note=a;
		sum[a]+=sum[b];
	}
}
int cmp(distant a,distant b){
	return a.dis<b.dis;
}
double dist(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int c;
		scanf("%d",&c);
		for(int i=1;i<=c;i++){
			land[i].note=i;
			sum[i]=1;
			scanf("%d%d",&land[i].x,&land[i].y);
		}
		int k=0;
		for(int i=1;i<=c;i++){
			for(int j=1;j<=c;j++){
				double l=dist(land[i].x,land[i].y,land[j].x,land[j].y);
				if(l>=10.0&&l<=1000.0){
					b[k].s=land[i].note;
					b[k].e=land[j].note;
					b[k].dis=l;
					k++;
				}
			}
		}
		sort(b,b+k,cmp);
		double ans=0;
		for(int i=0;i<=k;i++){
			if(find(b[i].s)!=find(b[i].e)){
				ans+=b[i].dis;
				hebing(b[i].s,b[i].e);
			}
		}
		if(sum[find(1)]==c){
			printf("%.1f\n",ans*100);
		}else{
			printf("oh!\n");
		} 
	}
	return 0;
} 
