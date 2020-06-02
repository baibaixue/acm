#include<stdio.h>
#define maxn 1020 
int main(){
	int x,i,j1,j2,t,n;
	char a[2][maxn];
	int b[maxn]; 
	scanf("%d",&x);
		int kase=0;
		while(x--){
			scanf("%s%s",a[0],a[1]);
			for(j1=0;a[0][j1]!='\0';j1++);//j1数1的长 
			for(j2=0;a[1][j2]!='\0';j2++);//j2数二的长 
			printf("Case %d:\n",++kase);
			for(n=0;n<j1;n++){
				printf("%c",a[0][n]);
			}
			printf(" + ");
			for(n=0;n<j2;n++){
				printf("%c",a[1][n]);
			}
			printf(" = ");
			if(j1>j2){
				for(int i=j2;i<j1;i++){
					a[1][i]='0'; 
				}
			}else{
				for(int i=j1;i<j2;i++){
					a[0][i]='0';//初始化两个数组一样长 
				}
			}
			int max;
			if(j1>j2){
				max=j1;
			}else{
				max=j2;
			}
			for(int i=0;i<=max;i++){
				b[i]=0;//初始化结果数组b 
			}
			for(int i=0;i<max;i++){
				int c=j1-i-1;
				int d=j2-i-1;
				if(c<0){
					b[i+1]=(b[i]+0+a[1][d]-'0')/10;
					b[i]=(b[i]+0+a[1][d]-'0')%10;
				}else if(d<0){
					b[i+1]=(b[i]+a[0][c]-'0'+0)/10;
					b[i]=(b[i]+a[0][c]-'0'+0)%10;
				}else{
					b[i+1]=(b[i]+a[0][c]-'0'+a[1][d]-'0')/10;
					b[i]=(b[i]+a[0][c]-'0'+a[1][d]-'0')%10;
				}
//				printf("\n");
//				printf("a[0]=%d\n",a[0][j1-i-1]-'0');
//				printf("a[1]=%d\n",a[1][j2-i-1]-'0');
//				printf("max=%d\n",max-i-1);
//				printf("%d\n",(a[0][j1-i-1]-'0'+a[1][j2-i-1]-'0')%10); 
//				printf("%d\n",(a[0][j1-i-1]-'0'+a[1][j2-i-1]-'0')/10);
			}
				if(b[max]!=0){
					printf("%d",b[max]);

				}
			for(int i=max-1;i>=0;i--){
				printf("%d",b[i]);
			}
			printf("\n"); 
			if(x!=0){
			printf("\n");
		}
			}
	return 0;
}
