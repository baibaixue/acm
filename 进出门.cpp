#include<cstdio>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct people{
	string s;
	int timein,timeout;
}n[100000];
int cmp1(people a,people b){
	return a.timein<b.timein;
}
int cmp2(people a,people b){
	return a.timeout<b.timeout;
}
int main(){
	int N;
	cin>>N;
	while(N--){
		int M; 
		cin>>M;
		for(int i=0;i<M;i++){
			cin>>n[i].s;
			int h,m,s;
			scanf("%d:%d:%d",&h,&m,&s);
			n[i].timein=h*60*60+m*60+s;
			scanf("%d:%d:%d",&h,&m,&s);
			n[i].timeout=h*60*60+m*60+s;
		}
			sort(n,n+M,cmp1);
			cout<<n[0].s<<" ";
			sort(n,n+M,cmp2);
			cout<<n[M-1].s<<"\n";
	}
	return 0;
}
