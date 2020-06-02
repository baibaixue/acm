#include<stdio.h>
int main(){
	int a[100];
	int i,min,x,n,count;
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
			for(i=0;i<n;i++){
				scanf("%d",&a[i]);
			}
			min=a[0];
			count=0;
			for(i=0;i<n;i++){
				if(a[i]<min){
					min=a[i];
					x=i;
					count++;
				}
			}
			if(count!=0){
			a[x]=a[0];
			a[0]=min;
			printf("%d",a[0]);
			for(i=1;i<n;i++) {
				printf(" %d",a[i]);
			}
			printf("\n");
		}else{
			printf("%d",a[0]);
			for(i=1;i<n;i++) {
				printf(" %d",a[i]);
			}
			printf("\n");
		}
		
		}
		else
		break;
	}
	return 0;
}
