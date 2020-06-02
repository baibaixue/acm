#include<stdio.h>
int main(){
	int n,x;
	int i,j;
	int a[100];
	double res=0.0;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n-1;i++){
			for(j=0;j<n-i-1;j++){
				if(a[j+1]<a[j]){
					x=a[j];
					a[j]=a[j+1];
					a[j+1]=x;
				}
			}
		}
		for(i=1;i<n-1;i++){
			res+=a[i];
		}
		res=res/(n-2);
		printf("%.2f\n",res);
		res=0.0;
	}
	return 0; 
}
