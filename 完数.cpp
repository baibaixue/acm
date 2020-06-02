#include<stdio.h>
int wan(int a){
	int i;
	int sum=0;
	for(i=1;i<a;i++){
		if(a%i==0){
			sum+=i;
		}
	}
	if(sum==a){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int a;
	scanf("%d",&a);
	printf("%d\n",wan(a));
	return 0;
}
