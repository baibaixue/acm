#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[15];
int b[15];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,y;
		int sum=0;
		int tot=0;
		scanf("%d%d%d",&n,&m,&y);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i]; 
		}
		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
			tot+=b[i];
		}
		int res=tot-sum;
		if(res>y){
			printf("Wait\n");
		}else{
			printf("Go\n");
		}
	}
	return 0;
}
