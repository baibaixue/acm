#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define maxn 100005
using namespace std;
long long a[maxn];
void qsort(int l,int r){
	int i=l;int j=r;
	long long temp=a[l];
	long long t;
	if(i>=j){
		return ;
	}else{
		while(i!=j){
			while(a[j]>temp&&i<j){
				j--;
			}
			while(a[i]<=temp&&i<j){
				i++;
			}
			if(i<j){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		if(i==j){
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
			qsort(l,j-1);
			qsort(j+1,r);
		} 
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort(0,n-1);
	printf("%lld",a[0]);
	for(int i=1;i<n;i++){
		printf(" %lld",a[i]);
	}
	printf("\n");
	return 0;
}
