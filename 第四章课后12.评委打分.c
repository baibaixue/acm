//白雪，评委打分
#include<stdio.h> 
int main(){
	int i,j;
	int a[10];
	for(i=0;i<10;i++){//定义数组输入10个评委的打分 
		scanf("%d",&a[i]);
	}
	int t;
	for(i=0;i<10;i++){//冒泡排序法将分数排序 
		for(j=1;j<9;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	int sum=0;
	for(i=1;i<9;i++){//去掉最大值和最小值的分数和 
		sum+=a[i];
	}
	printf("%.2f\n",sum/8.0);//输出平均分 
	return 0;
}
