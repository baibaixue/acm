#include<cstdio>
int M[10000];
int main(){
	int k,m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=1;i<=m*2;i++){
			M[i]=i;//给m个人编号 
		} 
		int k=1;
		int count=0;//出列人员计数器 
		int i=1;
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
		printf("\n");
	}
	return 0;
} 
