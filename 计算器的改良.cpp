#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
char s[100000];
int main(){
	int x1=0;
	int x2=0;
	int s1=0;int s2=0;
	int len=1;
	char x;
	int a=0;
	scanf("%c",&s[0]);
	int equal=0;
	int less=0;
	int turn=0;
	if(s[0]=='-'){
		less=1;
	}else if(s[0]<='9'&&s[0]>='0'){
		a+=s[0]-'0';
	}else if(s[0]<='z'&&s[0]>='a'){
		x=s[0];
		x1+=1;
	}
	while(1){
		scanf("%c",&s[len]);
		if(s[len]=='\n'){
			break;
		}
		if(s[len-1]<='z'&&s[len-1]>='a'&&s[len]>='0'&&s[len]<='9'){
			turn=1;
		}
		if(s[len]=='='){
			if(turn==1){
				x1+=a;
			}else{
				s1+=a;
			}
			turn=0;
			equal=1;
			less=0;
			a=0;
		}if(s[len]=='+'){
			less=0;
			if(equal==1){
				if(turn==1){
					x2+=a;
				}else{
					s2+=a;	
				}
			}else{
				if(turn==1){
					x1+=a;
				}else{
					s1+=a;
				}
			}
			a=0;turn=0;
		}if(s[len]=='-'){
			less=1;
			if(equal==1){
				if(turn==1){
					x2+=a;
				}else{
					s2+=a;	
				}
			}else{
				if(turn==1){
					x1+=a;
				}else{
					s1+=a;
				}
			}
			a=0;turn=0;
		}
		
		if(s[len-1]=='='&&s[len]=='-'){
			less=1;
		}if(s[len-1]=='='&&s[len]<='z'&&s[len]>='a'){
			x2+=1;
		}
		if(equal==0){
			if(s[len]<='z'&&s[len]>='a'){
				x=s[len];
				if(s[len-1]=='+'){
					x1+=1;
				}else if(s[len-1]=='-'){
					x1-=1;
				}
				x1+=a;
				a=0;
			}
			if(s[len]<='9'&&s[len]>='0'){
				if(less==0){
					a=a*10+s[len]-'0';
				}else{
					a=a*10-(s[len]-'0');
				}
			}
		}else if(equal==1){
			if(s[len]<='z'&&s[len]>='a'){
				x=s[len];
				if(s[len-1]=='+'){
					x2+=1;
				}else if(s[len-1]=='-'){
					x2-=1;
				}
				x2+=a;
				a=0;
			}
			if(s[len]<='9'&&s[len]>='0'){
				if(less==0){
					a=a*10+s[len]-'0';
				}else{
					a=a*10-(s[len]-'0');
				}
			}
		}
		len++;
	}
	s2+=a;
	int X=x1-x2;
	int S=s2-s1;
	if(S*X<0){
		printf("%c=-%.3f\n",x,abs(S*1.0/X));
	}else{
		printf("%c=%.3f\n",x,abs(S*1.0/X));
	}
	return 0;
}
