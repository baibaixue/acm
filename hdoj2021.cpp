#include<stdio.h>
int main(){
	int n,i,count=0;
	int a[100];
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
			for(i=0;i<n;i++){
				scanf("%d",&a[i]);
			}
			for(i=0;i<n;i++){
				while(a[i]>0){
					if(a[i]>=100){
						a[i]-=100;
						count++;
					}else if(a[i]>=50){
						a[i]-=50;
						count++;
					}else if(a[i]>=10){
						a[i]-=10;
						count++;
					}else if(a[i]>=5){
						a[i]-=5;
						count++;
					}else if(a[i]>=2){
						a[i]-=2;
						count++; 
					}else{
						a[i]-=1;
						count++;
					}
				}
			}
			printf("%d\n",count);
			count=0;
		}
		else
		break;
	}
} 
