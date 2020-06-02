#include<stdio.h>//计算机与会计学//2018新生杯 
#include<algorithm>
#define maxn 20
using namespace std;
int a[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<maxn;i++){
			a[i]=0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int max=a[0];
			for(int i=0;i<n;i++){
				if(max<a[i+1]){
					max=a[i+1];
				}
			}
			for(int i=max;i>0;i--){
				for(int j=0;j<n;j++){
					if(a[j]>=i){
						printf("#");
					}else
					{
					printf(".");
					}
				}
				printf("\n");
			}
			for(int i=0;i<n;i++){
				printf("@");
			}
		printf("\n");
	}
	return 0;
}
