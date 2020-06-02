#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 1000+50
struct food{
	int j,f;
	double ave; 
}num[maxn];
int cmp(food a,food b){
	return a.ave>b.ave;
}
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF&&(m!=-1||n!=-1)){
		for(int i=0;i<n;i++){
			num[i].ave=0;
			scanf("%d%d",&num[i].j,&num[i].f);
			num[i].ave=num[i].j;
			if(num[i].f!=0){
				num[i].ave=(double)num[i].j/(double)num[i].f;
			}
		}
		sort(num,num+n,cmp);
		double ans=0.0;
		for(int i=n-1;i>=0;i--){
			if(num[i].f==0){
				ans+=num[i].j;
			}
		}
		for(int i=0;i<n;i++){
			if(num[i].j!=0&&num[i].f!=0){
				if(m>=num[i].f){
					ans+=num[i].j;
					m-=num[i].f;
				}else if(m<num[i].f){
					ans+=num[i].j*((double)m/(double)num[i].f);
					break;
				}
			}
		}
		printf("%.3f\n",ans);
	}
	return 0;
} 
