#include<stdio.h>//绝对值最大 11月18日 白雪
#include<math.h>
int main(){
	int s[10][10];
	int i,j;
	printf("print 5*6 groups:\n");
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			scanf("%d",&s[i][j]);//读入5*6方阵 
		}
	}
	int max=fabs(s[0][0]);//初始化最大值 
	int x,y;
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			if(max<fabs(s[i][j])){//找出最大值 
				max=fabs(s[i][j]); 
				x=i;y=j;//标记最大值的位置 
			}
		}
	}
	printf("%d %d %d",s[x][y],x+1,y+1);
	return 0;
} 
