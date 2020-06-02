#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include <functional>
using namespace std;
struct q{
	long long int x[10020];
	int t;//每个集合里的元素个数 
}num[55];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i].t); 
			for(int j=0;j<num[i].t;j++){
				scanf("%lld",&num[i].x[j]);//读取每个集合里面的元素 
			}
			sort(num[i].x,num[i].x+num[i].t);//排序 
		}
		int k;
		scanf("%d",&k);//k次查询 
		for(int i=0;i<k;i++){
			int a,b;
			scanf("%d%d",&a,&b);//要查询的两个集合的序号 
			int c=0,t=0;
			sort(num[a].x,num[a].x+num[a].t);
			sort(num[b].x,num[b].x+num[b].t);
			if(num[a].t==1){
				t++;
			}else if(num[a].t>1){
				for(int i=0;i<num[a].t;i++){
					if(num[a].x[i]!=num[a].x[i+1]){
						t++;
					}
				}
			}
			if(num[b].t==1){
				t++;
			}else if(num[a].t>1){
				for(int i=0;i<num[b].t;i++){
					if(num[b].x[i]!=num[b].x[i+1]){
						t++;
					}
				}
			}
			//t=unique(num[a].x,num[a].x+num[a].t)-num[a].x+unique(num[b].x,num[b].x+num[b].t)-num[b].x;
			//a,b集合各自不重复的元素之和 
			cout<<"t="<<t<<endl; 
			if(binary_search(num[b].x,num[b].x+num[b].t,num[a].x[0]))
			c++;//第一个元素是否在交集中 
			for(int i=1;i<num[a].t;i++){
				if(binary_search(num[b].x,num[b].x+num[b].t,num[a].x[i])&&num[a].x[i]!=num[a].x[i-1]){
					c++;//从第二个元素开始并且和前一个元素不相等时，判断是否在交集中 
				}
			}
			t=t-c;//t-交集元素个数为并集元素个数 
			cout<<"c="<<c<<endl;
			cout<<"t="<<t<<endl;
			double ans=c*1.0/t*100;//计算相似率 
			printf("%.2f%\n",ans);
		}
		return 0;
	}
}

