#include<stdio.h>
int main(){
	int n;
	double s;
	struct point{
		int x,y;
	}c[120];
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",&c[i].x);
			scanf("%d",&c[i].y);
		}
		s=0.0;
		for(int i=0;i<n-1;i++){
			s+=(c[i].x*c[i+1].y-c[i+1].x*c[i].y);
		}
		s+=(c[n-1].x*c[0].y-c[0].x*c[n-1].y);
		printf("%.1f\n",s/2.0);
	}
	return 0;
}
