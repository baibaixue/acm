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
	printf("			欢迎来到打字练习游戏！\n");
	printf("				1————start\n");
	printf("				2————help\n");
	printf("				3————exit\n");
	key=getch();
		switch(key){
			case '1':screen();break;
			case '2':help();break;
			case '3':exit(0);
			default :system("CLS");printf("error!\n-----按任意键返回\n");
			key=getch();
			content();
		}
} 
void help(){
	system("CLS");
	printf("\n\n	      在游戏中，每次会有一个字母下落，你的任务就是在字母落到屏幕下方之前按下正确的按键，\n" 
			"			每成功一次会加十分，失败则会扣去二十分，\n"
			"		当你的分数达到一定分数时会开启下一关，小心不要游戏失败呦！\n"
			"				 			\(^o^)/~\n"
			"											------- 按下'1'返回主菜单\n"
			"											------- 按下'0'结束游戏\n");
		key=getch();
		switch(key){
			case '1':system("CLS");content();break;
			case '0':exit(0);
			default:system("CLS");printf("error!\n-----按任意键返回\n");while(!kbhit){
				system("CLS");
				help();
			}
		}
}
void my_rand(){
	srand(time(0));//以时间为种子
	a=(char)rand()%26;//rang()返回随机整数将其强制转换为字符 
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
			printf("\t\t恭喜你通过第%d关!!\n\t\t让我们继续接下来的挑战吧！\n\t\t(按任意键继续)\n",levels);
				key=getch();
				screen();
		}else if(scores<(100*levels-100)){
			system("CLS");
			printf("\t\tGAME OVER!\n\t\t(按任意键回到主菜单)\n");
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
