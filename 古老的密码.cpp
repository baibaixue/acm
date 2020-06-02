#include<stdio.h>
#include<string.h>
int readchar(){
	for(;;){
		int ch=getchar();
		if(ch!='\n'&&ch!='\r'){
			return ch;
		}
	}
}
int readlen(int c){
	int v=0;
	while(c--){
		v=v*2+readchar()-'0';
	}
	return 0;
}
int code[8][1<<8];
int readcode(){
	memset(code,0,sizeof(code));
	code[1][0]=readchar();
	for(int len=2;len<=7;len++){
		for(int i=0;i<(1<<len)-1;i++){
			int ch=getchar(); 
			if(ch==EOF){
				return 0;
			}
			if(ch=='\n'||ch=='\r'){
				return 1;
			}
			code[len][i]=ch;
		}
		return 1;
	}
}
void printcode(){
	for(int len=1;len<=7;len++){
		for(int i=0;i<(1<<len)-1;i++){
			if(code[len][i]==0) return;
			printf("code[%d][%d]=%c\n",len,i,code[len][i]);
		}
	}
}
int main(){
	while(readcode()){
		//}printcode();
		for(;;){
			int len=readlen(3);
			if(len==0) break;
			for(;;){
				int v=readlen(len);
				if(v==(1<<len)-1){
					break;
				}else
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}
