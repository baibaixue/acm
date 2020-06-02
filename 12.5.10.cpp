#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
int a_e[maxn];
double a_c[maxn];
int b_e[maxn];
double b_c[maxn];
int c_e[maxn];
double c_c[maxn];
int d_e[maxn];
double d_c[maxn];
int main(){
	int n1,n2;
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++){
		scanf("%d%d",&a_e[i],&a_c[i]);
		scanf("%d%d",&d_e[i],&d_e[i]);
	}
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++){
		scanf("%d%d",&b_e[i],&b_c[i]);
	}
	if(b_c[1]==0&&b_e[1]==0){
		printf("0 0.0\n");
	}else{
		for(int i=1;i<=n1;i++){
			c_e[i]=d_e[i]-b_e[i];
			c_c[i]=d_c[i]/b_c[i];
			for(int j=1;j<=n2;j++){
				d_e[j]=d_e[j]-d_e[j];
			}
		}
	}
}
