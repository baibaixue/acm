#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int num[105];
	int sum=0;
	int c;
	scanf("%d",&c);
	while(c--){
		int n;
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		double ave;
		ave=sum*1.0/n;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(num[i]>=ave){
				cnt++;
			}
		}
		printf("%.2f %d\n",ave,cnt);
	}
}
