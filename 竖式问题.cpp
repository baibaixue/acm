#include<stdio.h>
#include<string.h>
int main(){
	char a[20],b[100];
	int count=0;
	while(scanf("%s",a)!=NULL){
		for(int abc=111;abc<1000;abc++){
			for(int de=11;de<100;de++){
				int x=abc*(de%10),y=abc*(de/10),z=abc*de;
				sprintf(b,"%d%d%d%d",abc,de,x,y,z);
				int ok=1; 
				for(int i=0;i<strlen(b);i++){
					if(strchr(a,b[i])==NULL){
						ok=0;
					}
				}
				if(ok==1){
					count++;
					printf("<%d>\n",count);
					printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%4d\n\n",abc,de,x,y,z);
				}
			}
		}
		printf("The number of solution=%d\n",count);
		count=0;
	}
	return 0;
} 
