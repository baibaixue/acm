#include<stdio.h>
int main(){
	int a[50][5];
	double b[5];
	int n,m,i,j,i1,j1,t,count;
	double x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		x=0.0;
		y=0.0;
				for(j=0;j<m;j++){
					x+=a[0][j];
				}
				printf("%.2f",x/m);
				x=0.0;
			for(i=1;i<n;i++){
				for(j=0;j<m;j++){
					x+=a[i][j];
				}
				printf(" %.2f",x/m);
				x=0.0;
			}
			printf("\n");
			count=0;
			for(i=0;i<n;i++){
				y+=a[i][0];
			}
			printf("%.2f",y/n);
			b[0]=y/n;
			y=0.0;
			for(j=1;j<m;j++){
				for(i=0;i<n;i++){
					y+=a[i][j];
					}
				b[j]=y/n;
				printf(" %.2f",b[j]);
				y=0.0;
			}
			for(i=0;i<n;i++){
				t=1;
				for(j=0;j<m;j++){
					if(a[i][j]<b[j]){
						t=0;
						break;
					}
				}
				if(t==1){
					count++;
				}
			}
			printf("\n");
			printf("%d\n\n",count);
			}
	return 0;
}
