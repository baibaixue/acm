#include<stdio.h>
#include<ctype.h>
int main(){
	char a[50];
	int n,i1,i2,j,t;
	while(scanf("%d%*c",&n)!=EOF){
		for(i1=0;i1<n;i1++){
			gets(a);
			t=1;
			for(j=0;a[j]!='\0';j++);
			if(isdigit(a[0])!=0){
				t=0;
			}
			for(i2=0;i2<j;i2++){
				if(isalpha(a[i2])==0&&isdigit(a[i2])==0&&a[i2]!='_'){
					t=0;
					break;
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
