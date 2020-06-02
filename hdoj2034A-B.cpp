#include<stdio.h>
#include<string.h> 
int a[120],b[120];
int n,m;
int in(int a,int* b){
	for(int i=0;i<m;i++){
		if(a==b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n!=0||m!=0){
			int c[120];
			for(int i=0;i<n;i++){
				scanf("%d",&a[i]);
			}
			for(int j=0;j<m;j++){
				scanf("%d",&b[j]);
			}
			int x=0;
			int len=0;
			for(int i=0;i<n;i++){
				if(in(a[i],b)==1){
					c[x++]=a[i];
					len++;
				}
			}
			if(len==0){
				printf("NULL");
			}else{
				int t;
				for(int i=0;i<len-1;i++){
					for(int j=0;j<len-i-1;j++){
						if(c[j]>c[j+1]){
							t=c[j];
							c[j]=c[j+1];
							c[j+1]=t;
						}
					}
				}
				for(int i=0;i<len;i++){
					printf("%d ",c[i]);
				}
			}
			printf("\n");
		}
		else if(n==0&&m==0)
		break;
	}
	return 0;
}
