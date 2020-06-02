#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int chaji(int a,int b,int c,int d){
	return a*d-c*b;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int x0,y0;
		int x1,y1;
		int x,y;
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		int ao=0;
		int a=x0,b=x0;
		int a1=x1,b1=y1;
		for(int i=2;i<n;i++){
			scanf("%d%d",&x,&y);
			int ans=chaji(x-x0,y-y0,x1-x0,y1-y0);
			x0=x1;y0=y1;
			x1=x;y1=y;
			if(ans>0){
				ao==1;
			}
			//printf("%d\n",ans);
		}
		if(chaji(a-x0,b-y0,x1-x0,y1-y0)>=0||chaji(a1-x1,b1-y1,a-x1,b-y1)>=0){
			//printf("%d\n%d\n",chaji(a-x0,b-y0,x1-x0,y1-y0),chaji(a1-x1,b1-y1,a-x1,b-y1));
			ao=1;
		}if(ao==1){
			printf("concave\n");
		}else{
			printf("convex\n");
		}
	}
	return 0;
}
