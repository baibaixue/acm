#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100010
using namespace std;
int train[maxn];
int road[maxn];
int b_search(int n,int m){
	int l=0,r=m;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(road[mid]>n){
			r=mid-1;
		}else {
			l=mid+1;
		}
	}
	if(road[l]>n){
		return l;
	}
	return -1;
} 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&train[i]);
		}
		memset(road,0,sizeof(road));
		int len=0;
		for(int i=0;i<n;i++){
			int x=b_search(train[i],len);
			if(x==-1){
				road[len]=train[i];
				len++;
			}else{
				road[x]=train[i];
			}
		//	sort(road,road+len);
		}
		printf("%d\n",len);
	}
	return 0;
}
//#include<iostream>
//
//#include<string.h>
//using namespace std;
//int count[100000];
//int t = 0;
//int search(int x){
////二分法查找
//int high = t,low = 0;
//int mid;
//while(low<=high){
//mid = (low+high)/2;
//if(x>count[mid])
//low = mid + 1;
//else
//high = mid-1;
//}
//if(count[low]>x)
//return low;
//return 0;
//}
//int main(){
//int n,m;	
//cin>>n;
//memset(count,0,sizeof(count));
//for(int i = 0;i<n;i++){
//cin>>m;
//int p = search(m);
//if(p)
//count[p] = m;//如果存在比自己大的则插入
//else
//count[++t] = m;//否则新开一个空间
//}
//cout<<t<<endl;
//}

