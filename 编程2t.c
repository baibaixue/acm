#include<stdio.h>//11��26��  ��ѩ ����ֵ���� 
#include<math.h>
void sort(double *a){
	int i;
	int j;
	double t;
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){//ð������ 
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
		scanf("%lf",&a[i]);//������ 
		if(a[i]<0){
			a[i]=-a[i];//�����ֵ 
		}
	}
	sort(a);//���� 
	for(i=0;i<10;i++){
		printf("%.2f ",a[i]);//��� 
	}
	printf("\n");
	return 0;
}
