#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#define maxn 105
using namespace std;
int num[maxn][maxn][10];
int school[maxn];
int is_left[maxn];
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	int max=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		school[i]=x*10;
		is_left[i]=x*10;
		if(x>max){
			max=x;
		}
	}
	if(n==1){
		int X=1;
		printf("#1\n");
		for(int i=1;i<=school[1];i++){
			printf("%d",X);
			if(i%10==0){
				printf("\n");
			}else{
				printf(" ");
			}
			X+=2;
		}	
	}else{
		int cnt=1;
		int ll=n;
		int one=0;
		for(int i=1;i<=max;i++){
			for(int k=1;k<=10;k++){
				for(int j=1;j<=n;j++){
					if(is_left[j]>0){
						num[j][i][k]=cnt;
						cnt++;
						is_left[j]--;
						if(is_left[j]==0){
							ll--;
						}
						if(one==1){
							cnt+=1;
						}
					}
					if(ll==1){
						one=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			printf("#%d\n",i);
			for(int j=1;j<=school[i]/10;j++){
				printf("%d",num[i][j][1]);
				for(int k=2;k<=10;k++){
					printf(" %d",num[i][j][k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
