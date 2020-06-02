#include<stdio.h>
int main(){
	int n=0;
	char c,b;
	double score=0;
	int kase=0;
	while(scanf("%c%c",&c,&b)!=EOF){
		switch(c){
			case 'A':score+=4,n++;break;
			case 'B':score+=3,n++;break;
			case 'C':score+=2,n++;break;
			case 'D':score+=1,n++;break;
			case 'F':score+=0,n++;break;
			default:kase=1;
		}
		if(b=='\n'){
			if(kase==1){
				printf("Unknown letter grade in input\n");
				n=0;score=0;kase=0;
			}else{
				printf("%.2f\n",score/n);
				n=0;score=0;kase=0;
			}
		}
	}
	return 0;
}
