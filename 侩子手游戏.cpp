#include<stdio.h>
#include<string.h>
#define max 100
int lose,win;
char s[max],s1[max];
int rnd,chance,left;
void guess(char c){
	int bad=1;
	for(int i=0;i<strlen(s);i++){
		if(s[i]==c){
			left--;
			s[i]=' ';
			bad=0;
		}
	}
		if(bad==1){
			chance--;
		}
		if(chance==0){
			lose=1;
		}if(left==0){
			win=1;
		}
}
int main(){
	while(scanf("%d%s%s",&rnd,s,s1)==3&&rnd!=-1){
		printf("Round :%d\n",rnd);
		win=lose=0;
		chance=7;
		left=strlen(s);
		for(int i=0;i<strlen(s1);i++){
			guess(s1[i]);
			if(win||lose){
				break;
			}
		}
		if(win){
			printf("You win!\n");
		}else if(lose){
			printf("You lose!\n");
		}else{
			printf("You chickened out.\n");
		}
	}
	return 0;
}

