#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct node{
	int x,y;
};
double dist(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
const double inf=0x3f3f3f3f;
int main(){
	vector<node> A;
	while(scanf("%d",&n)!=EOF){
			for(int i=0;i<n;i++){
				node a;
				scanf("%d%d",&a.x,&a.y);
				A.push_back(a); 
		}
		double Max=0;
		double Min=inf;
		for(int i=0;i<A.size();i++){
			for(int j=0;j<A.size();j++){
				if(i!=j){
					Max=max(Max,dist(A[i],A[j]));
					Min=min(Min,dist(A[i],A[j]));
				}
			}
		}
		printf("%.4lf %.4lf\n",Max,Min);
	}
}
