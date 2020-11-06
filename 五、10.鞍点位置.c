#include<stdio.h>//鞍点位置 11月18日 白雪
int main(){
	int c[10][10];
	int n;
	int i,j,l;
	scanf("%d",&n);//n阶方阵 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&c[i][j]);//读入方阵 
		}
	}
	int x,y;
	int k;
	int t;
	int kase=0;//不存在鞍点 
	for(i=0;i<n;i++){//从第一行开始找 
		t=c[i][0];//t保存最大值 
		x=i;y=0;
		for(j=0;j<n;j++){
			if(c[i][j]>t){
				x=i;y=j;//标记每一行的最大值 
				t=c[i][j];
			}
		}
		k=1; //假设改行行鞍点存在为k=1； 
		for(l=0;l<n;l++){
			if(t>c[l][y]){//将这一行的最大值与这一列的值比较 
				k=0;//该行鞍点不存在 
			}
		}
		if(k==1){
			printf("%d %d\n",y+1,x+1);//输出 
			kase=1;//鞍点存在 
		}
	}
	if(kase==0){
		printf("N0\n");
	} 
	return 0;
} 
