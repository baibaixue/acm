#include<stdio.h>//11月26号  白雪 绝对值排序 
#include<math.h>
void sort(double *a){
	int i;
	int j;
	double t;
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){//冒泡排序 
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
int main(){
	double a[10];
	int i;
	for(i=0;i<10;i++){
		scanf("%lf",&a[i]);//读入数 
		if(a[i]<0){
			a[i]=-a[i];//求绝对值 
		}
	}
	sort(a);//排序 
	for(i=0;i<10;i++){
		printf("%.2f ",a[i]);//输出 
	}
	printf("\n");
	return 0;
}
