#include<stdio.h>
#include<math.h>
int main(){
	int i,j,max,min,x,y,z;
	int a[10];
	double ave=0;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		ave+=a[i];
	}
	ave=ave/10.0;
	double min_ave;
	min_ave=10000;
	int count=0;
	max=a[0];min=a[0];x=0;y=0;z=0;
	for(i=0;i<10;i++){
		if(max<a[i]){
			max=a[i];
			x=i;
		}if(min>a[i]){
			min=a[i];
			y=i;
		}if(min_ave>a[i]-ave&&a[i]-ave>0){
			min_ave=a[i]-ave;
			z=i;
		}
		if(a[i]<ave){
			count++;
		}
	}
	printf("Maximum: a[%d]=%d\nMinimum: a[%d]=%d\nAverage: %.1f\nClosest to: a[%d]=%d\nLess than: %d\nSort: "
	,x,max,y,min,ave,z,a[z],count);
	int t;
	for(i=0;i<10;i++){
		for(j=0;j<9-i;j++){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("%d",a[0]);
	for(i=1;i<10;i++){
		printf(" %d",a[i]);	
	}
	printf("\n");
	return 0;
} 
