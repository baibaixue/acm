#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int num[100005];
int Search[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			Search[num[i]]=i;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(i!=num[i]){
				int temp;
				temp=num[i];
				num[i]=num[Search[i]];
				num[Search[i]]=temp;
				temp=Search[num[i]];
				Search[num[i]]=i;
				Search[num[temp]]=temp;
				res++;
			}
		} 
		printf("%d\n",res);
	}
	return 0;
}
