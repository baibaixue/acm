#include<cstdio>
#include<string.h>
int main(){
	char A[10];
	char B[10];
	scanf("%s",A);
	getchar();
	scanf("%s",B);
	int a=1,b=1;
	for(int i=0;A[i]!='\0';i++){
		a*=(int)(A[i]-'A'+1);
	}
	for(int i=0;B[i]!='\0';i++){
		b*=(int)(B[i]-'A'+1);
	}
	a=a%47;
	b=b%47;
	if(a==b){
		printf("GO\n");
	}else{
		printf("STAY\n");
	}
	return 0;
}
