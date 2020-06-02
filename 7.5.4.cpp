#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct student{
	string name;
	int m;
	int e;
	int p;
	int z;
	int tot;
};
student num[120];
bool cmp(student a,student b){
	if(a.tot==b.tot){
		return a.name<b.name;
	}else{
		return a.tot>b.tot;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			getchar();
			cin>>num[i].name;
			scanf("%d%d%d%d",&num[i].m,&num[i].e,&num[i].p,&num[i].z);
			num[i].tot=num[i].p+num[i].m+num[i].z+num[i].e;
		}
		sort(num,num+n,cmp);
		for(int i=0;i<n;i++){
			if(num[i].tot>=320){
				if(num[i].m>=150*0.6&&num[i].e>=60&&num[i].p>=60&&num[i].z>=150*0.6){
					cout<<num[i].name<<" "<<num[i].tot<<endl;
				}
			}
		}
	}
} 
