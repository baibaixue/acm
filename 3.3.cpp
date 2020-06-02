#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct sub{
	int day;
	int point;
	double ave;
}num[1010];
int cmp(sub a,sub b){
	if(a.ave==b.ave){
		return a.point>b.point;
	}else{
		return a.ave<b.ave;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int all_points=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i].day);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&num[i].point);
			all_points+=num[i].point;
			if(num[i].point==0){
				num[i].ave=0;
			}else
				num[i].ave=(num[i].day*1.0)/(num[i].point*1.0);
		}
		int days=n;
		int get_points=0;
		int count=0;
		while(days--){
			sort(num+count,num+n,cmp);
			for(int i=count;i<n;i++){
				if(num[i].ave>0){
					get_points+=num[i].point;
					count++;
					num[i].day=0;
					break;
				}
			}
			for(int i=count;i<n;i++){
				num[i].day--;
				if(num[i].point==0){
					num[i].ave=0;
				}else
					num[i].ave=(num[i].day*1.0)/(num[i].point*1.0);
			}
		}
		printf("%d\n",all_points-get_points);
	}
	return 0;
}
