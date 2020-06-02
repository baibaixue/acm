#include<stdio.h>
int main(){
	int a[100];
	int n,m,i,t;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		if(n!=0||m!=0){
			a[0]=m;
			for(i=1;i<n+1;i++){
				scanf("%d",&a[i]);
			}
			for(i=0;i<n;i++){
				if(a[i]>a[i+1]){
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
				}
			}
			printf("%d",a[0]);
			for(i=1;i<n+1;i++){
				printf(" %d",a[i]);
			}
			printf("\n");
		}
		else
		break; 
	}
	return 0;
}
