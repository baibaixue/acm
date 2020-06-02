#include<stdio.h>
int main(){
	char a[100];
	int i,j;
	while(gets(a)!=NULL){
		for(j=0;a[j]!='\0';j++);
		a[0]-=32;
		for(i=1;i<j;i++){
			if(a[i]==32){
				a[i+1]-=32;
			}
		}for(i=0;i<j;i++){
			printf("%c",a[i]);
		}
		printf("\n");
	}
	return 0;
}
