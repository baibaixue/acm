#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define maxn 25
using namespace std;
char c[maxn][maxn]={' '};
int levels,scores;
char key;
char a;
int b;
double stay_time=1000;
void content();
void help();
void screen();
void my_rand();
void content(){
	system("CLS");
	printf("			��ӭ����������ϰ��Ϸ��\n");
	printf("				1��������start\n");
	printf("				2��������help\n");
	printf("				3��������exit\n");
	key=getch();
		switch(key){
			case '1':screen();break;
			case '2':help();break;
			case '3':exit(0);
			default :system("CLS");printf("error!\n-----�����������\n");
			key=getch();
			content();
		}
} 
void help(){
	system("CLS");
	printf("\n\n	      ����Ϸ�У�ÿ�λ���һ����ĸ���䣬��������������ĸ�䵽��Ļ�·�֮ǰ������ȷ�İ�����\n" 
			"			ÿ�ɹ�һ�λ��ʮ�֣�ʧ������ȥ��ʮ�֣�\n"
			"		����ķ����ﵽһ������ʱ�Ὺ����һ�أ�С�Ĳ�Ҫ��Ϸʧ���ϣ�\n"
			"				 			\(^o^)/~\n"
			"											------- ����'1'�������˵�\n"
			"											------- ����'0'������Ϸ\n");
		key=getch();
		switch(key){
			case '1':system("CLS");content();break;
			case '0':exit(0);
			default:system("CLS");printf("error!\n-----�����������\n");while(!kbhit){
				system("CLS");
				help();
			}
		}
}
void my_rand(){
	srand(time(0));//��ʱ��Ϊ����
	a=(char)rand()%26;//rang()���������������ǿ��ת��Ϊ�ַ� 
	while(!(a>='a'&&a<='z')){
		a=(char)rand();
	}
}
void screen(){
		system("CLS");
		my_rand();
		int x=rand()%25;
		int y=0;
		stay_time=1000/levels;
		printf("levels:%d score:%d hint:0----exit 1----menu\n",levels,scores);
		for(int i=0;i<maxn;i++){
				printf("---");
			}
			printf("\n");
		if(scores>=100*levels){
			levels++;
			system("CLS");
			printf("\t\t��ϲ��ͨ����%d��!!\n\t\t�����Ǽ�������������ս�ɣ�\n\t\t(�����������)\n",levels);
				key=getch();
				screen();
		}else if(scores<(100*levels-100)){
			system("CLS");
			printf("\t\tGAME OVER!\n\t\t(��������ص����˵�)\n");
					key=getch();
					scores=0;
					levels=1;
					content();
		}
		else{
			while(y<=24){
				
				c[y][x]=a;
				for(int i=0;i<x;i++){
					printf(" ");
				}
				printf("%c",c[y][x]);
				for(int i=0;i<80;i++){
					printf(" ");
				}
				Sleep(stay_time);
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  "              
					   "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  "
					   "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  "
					   "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  "
					   /*"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  "*/);
					   printf("\n");
					   y++;
				if(kbhit()!=0){
					key=getch();
					if(key==a){
						scores+=10;
						system("CLS");
						screen();
					}else if(key=='0'){
						exit(0);
					}else if(key=='1'){
						system("CLS");
						content();
						}
					else {
						scores-=20;
						screen();
					}
					printf("\n");
				}
			}
			scores-=20;
			screen();
		}
}
int main(){
	levels=1;scores=0;
	content();
	return 0;
}
