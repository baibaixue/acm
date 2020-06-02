#include<stdio.h>
#include<math.h>
#include<string.h>
void exchange(int n,int r){
	int a,b,count=0;
	b=n;
	char c[10000];
	for(int i=0;;i++){
		a=b%r;
		b=b/r;
		if(a>=0&&a<10){
			c[i]=(char)(a+'0');
		}else if(a>=10){
			switch(a%10){
				case 0:c[i]='A';break;
				case 1:c[i]='B';break;
				case 2:c[i]='C';break;
				case 3:c[i]='D';break;
				case 4:c[i]='E';break;
				case 5:c[i]='F';break;
			}
		}
		count++;
		if(b==0){
			break;
		}
	}
	for(int i=count-1;i>=0;i--){
		printf("%c",c[i]);
	}

}
int main(){
	int n,r;
	int ans;
	while(scanf("%d%d",&n,&r)!=EOF){
		if(n>=0) 
		exchange(n,r);
		else{
			printf("-");
			exchange((-n),r);
		}
		printf("\n");
	}
	return 0;
}
