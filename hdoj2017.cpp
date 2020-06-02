#include<stdio.h>
#include<ctype.h>
int isdigit(char a);
int main(){
	int n,i,j,m=0;
	char a;
	int sum;
	while(scanf("%d",&n)!=EOF){
		scanf("%*c");
		for(i=0;i<n;i++){
			while(scanf("%c",&a)!=EOF){
				if(a!='\x0a'){
					if(a<65){
					m+=1;
					}
				}else
				break;
			}
			printf("%d\n",m);
			m=0;
		}
	}
	return 0;
}
