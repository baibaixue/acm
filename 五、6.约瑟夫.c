#include<stdio.h>//约瑟夫问题 11月18日 白雪
int main(){
	int m,n;
	int M[1000];
	int i,j;
	printf("printf m,n:\n");
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
		M[i]=i;//给m个人编号 
	} 
	int k=1;
	int count=0;//出列人员计数器 
	i=1;
	int x;
	for(;;){
		x=i%m;
		if(i%m==0){//圆圈序列取余找出相应的下标 
			x=m;
		}
		if(k==n&&M[x]!=0){//k为报数 
			printf("%d ",M[x]); 
			M[x]=0;//转换为0表示出列 
			k=1;
			count++;
		}else if(M[x]!=0){
			k++;
		}
		i++;
		if(count==m){//m个人全部出列结束循环 
			break;
		}
	} 
	return 0;
} 
