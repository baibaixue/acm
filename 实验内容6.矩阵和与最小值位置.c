#include<stdio.h>//找出数组最小值及所有元素之和 11月19日 白雪 
int main(){
	int i,j;
	int c[5][5];
	int sum=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&c[i][j]);
			sum+=c[i][j];//读取输入并求和 
		}
	}
	int min=c[0][0],x,y;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(min>c[i][j]){
				min=c[i][j];
				x=i;y=j;//找出最小值坐标 
			}
		}
	}
	printf("sum=%d x=%d y=%d\n",sum,x+1,y+1);
	return 0;
} 
