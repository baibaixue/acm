#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<set>
using namespace std; 
struct p{
	char s[10];
	int k[1005];
	int r;
	double congfu;
}num[110];
int cmp(p a,p b){
	if(a.r==b.r){
		return a.congfu<b.congfu;
	}else{
		return a.r>b.r;
	}
}
int main(){
	int n;
	scanf("%d",&n);
		getchar();
		for(int i=0;i<n;i++){
			int d;
			scanf("%s",num[i].s);
			scanf("%d",&d);
			num[i].r=d;
			num[i].congfu=0;
			memset(num[i].k,0,sizeof(num[i].k));
			for(int j=0;j<d;j++){
				int a;
				scanf("%d",&a);
				num[i].k[j]=a;
			}
			sort(num[i].k,num[i].k+d);
			for(int j=1;j<d;j++){
				if(num[i].k[j]==num[i].k[j-1]){
					num[i].r--;
					num[i].congfu++;
				}
			}
			num[i].congfu/=d*1.0;
		}
		sort(num,num+n,cmp);
		if(n==1){
			cout<<num[0].s<<" "<<"-"<<" "<<"-"<<"\n";
		}else if(n==2){
			cout<<num[0].s<<" "<<num[1].s<<" "<<"-"<<"\n";
		}else{
			cout<<num[0].s<<" "<<num[1].s<<" "<<num[2].s<<"\n";
		}
}
