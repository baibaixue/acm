#include<stdio.h>//s10的春游计划//2018新生杯 
#include<algorithm>
#define max 10020
using namespace std;
int a[max];
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+m);
		int sum=m;
		int i=0,j=m-1;
		for(;;){
			if(a[i]+a[j]>4){
				j--;
			}else{
				a[i]=a[i]+a[j];
				sum--;
				a[j]=5;
				i++;j--;
			}
			if(i>=j){
				break;
			}
		}
		sort(a,a+m);
		i=0,j=sum-1;
		for(;;){
			if(a[i]+a[j]>4){
				j--;
			}else{
				sum--;
				i++;j--;
			}
			if(i>=j){
				break;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
