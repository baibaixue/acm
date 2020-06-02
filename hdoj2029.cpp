#include<stdio.h>
int main()
{
	int n,i,j,k,t;
	char a[9000];
	while(scanf("%d%*c",&n)!=EOF){
		for(i=0;i<n;i++){
			gets(a);
			t=1;
			for(j=0;a[j]!='\0';j++);
			for(k=0;k<j/2;k++){
				if(a[k]!=a[j-k-1]){
					t=0;
				}
			}
			if(t==1){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}
	return 0;
 } 
