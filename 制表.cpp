#include<windows.h>
#include<cstdio>
int main(){
	int L,R;
	L=15;R=2;
	HANDLE hOut; //�½���� hOut
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);  //ʵ������� hOut
	COORD pos={L,R};
	SetConsoleCursorPosition(hOut,pos);
	int l,b;
	l=20;b=70;
	printf("�X"); 
	for(int i=1;i<=b;i++){
		printf("�T");
	}
	printf("�[\n");
	for(int i=1;i<=l;i++){
		pos.Y=R+i;
		SetConsoleCursorPosition(hOut,pos);
		printf("�U");
		for(int j=1;j<=b;j++){
			printf(" ");
		} 
		printf("�U\n");
	} 
	SetConsoleCursorPosition(hOut,pos);
	printf("�^"); 
	for(int i=1;i<=b;i++){
		printf("�T");
	}
	printf("�a\n");
} 

