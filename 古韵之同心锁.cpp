#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define maxn 2000
using namespace std;
string s;
string sa;
string sb;
char w[8]={'I','m','m','o','r','t','a','1'};
char q[6]={'h','h','4','7','4','2'};
char e[4]={'1','0','1','3'};
int main(){
	while(cin>>s){
		int m,n,p;
		int len=s.length();
		scanf("%d",&m);
		sa=s.substr(0,m-1); 
		//cout<<sa<<endl;
		sb=s.substr(m-1,len-m+1); 
		//cout<<sb<<endl;
		scanf("%d%d",&n,&p);
		if(n==1){
			for(int i=0;i<len;i++){
				if(s[i]<='z'&&s[i]>='a'){
					s[i]-=32;
				}
				else if(s[i]<='Z'&&s[i]>='A'){
					s[i]+=32;
				}
				for(int j=0;j<=p;j++){
					printf("%c",s[i]);
				}
			}
			for(int i=0;i<8;i++){
				for(int j=0;j<=p;j++){
					printf("%c",w[i]);
				}
			}
		}
		if(n==2){
			int x=s.find(sb);
			int y=s.find(e);
			for(int i=0;i<len;i++){
				if(i==x){
					i+=sb.length()-1;
					x=s.find(sb,i);
				}
				else if(i==y){
					i+=3;
					for(int j=0;j<6;j++){
						for(int k=0;k<=p;k++){
							printf("%c",q[j]);
						}
					}
					y=s.find(e,i);
				}
				else{
					for(int j=0;j<=p;j++){
						printf("%c",s[i]);
					}
				}
			}
		}
		if(n==3){
			for(int i=0;i<m-1;i++){
				if(i==fabs(n-m)+1){
					for(int j=0;j<len-m+1;j++){
						for(int k=0;k<=p;k++){
							printf("%c",sb[j]);
						}
					}
				}
				for(int k=0;k<=p;k++){
					printf("%c",s[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
} 
