#include<stdio.h>
int grade[15];//求平均成绩和最高最低成绩 11月19日 白雪 
int main(){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&grade[i]);//记录成绩 
	}
	int max,min;
	double ave;
	max=grade[0],min=grade[0],ave=grade[0];
	for(i=1;i<10;i++){
		if(min>grade[i]){
			min=grade[i];//找最大成绩 
		}if(max<grade[i]){
			max=grade[i];//找最小成绩 
		}
		ave+=grade[i];//求总成绩 
	}
	printf("ave=%f,max=%d,min=%d\n",ave/10,max,min);
	return 0;
} 
