#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 105
using namespace std;
struct line{
	double x1,x2,y1,y2;
}l[maxn];
int chaji(line a,line b);
int P(line a,line b){
	if(chaji(a,b)==1&&chaji(b,a)==1){
		return 1;
	}else{
		return 0;
	}
}
int chaji(line a,line b){
	double x=(a.x2-a.x1)*(b.y2-a.y1)-(b.x2-a.x1)*(a.y2-a.y1);
	double y=(a.x2-a.x1)*(b.y1-a.y1)-(b.x1-a.x1)*(a.y2-a.y1);
	if(x*y<=0){
		return 1;
	}if(x*y>0){
		return 0;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(P(l[i],l[j])==1){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
