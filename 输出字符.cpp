#include<stdio.h>
void prn(char c,int m){
	int i;
	for(i=0;i<m;i++){
		printf("%c ",c);
	}
	printf("\n");
}
int main(){
	char c;
	int m;
	scanf("%c%d",&c,&m);
	prn(c,m);
	return 0;
} 
