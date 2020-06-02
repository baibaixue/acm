#include<windows.h>
#include<cstdio>
int main(){
	int L,R;
	L=15;R=2;
	HANDLE hOut; //新建句柄 hOut
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);  //实例化句柄 hOut
	COORD pos={L,R};
	SetConsoleCursorPosition(hOut,pos);
	int l,b;
	l=20;b=70;
	printf("╔"); 
	for(int i=1;i<=b;i++){
		printf("═");
	}
	printf("╗\n");
	for(int i=1;i<=l;i++){
		pos.Y=R+i;
		SetConsoleCursorPosition(hOut,pos);
		printf("║");
		for(int j=1;j<=b;j++){
			printf(" ");
		} 
		printf("║\n");
	} 
	SetConsoleCursorPosition(hOut,pos);
	printf("╚"); 
	for(int i=1;i<=b;i++){
		printf("═");
	}
	printf("╝\n");
} 

