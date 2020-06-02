#include<stdio.h>
#include<math.h>
int main(){
	int a[100];
	int i,j,t,n;
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
			for(i=0;i<n;i++){
				scanf("%d",&a[i]);
			}
			for(i=0;i<n-1;i++){
				for(j=1;j<n;j++){
					if(fabs((double) a[j-1])<fabs((double) a[j])){
						t=a[j-1];
						a[j-1]=a[j];
						a[j]=t;
					}
				}
			}
			printf("%d",a[0]);
			for(i=1;i<n;i++){
				printf(" %d",a[i]);
			}
			printf("\n");
		}
		else 
		break;
	}
	return 0;
}
