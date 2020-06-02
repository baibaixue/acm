#include<cstdio>
#include<algorithm>
#include<iostream>
#include<ctype.h>
#include<string.h>
#define maxn 100000
using namespace std;
char a[maxn],b[maxn];
int is_zhengshu(char* s,int a){
	int k=1;
	for(int i=0;i<a;i++){
		if(isdigit(s[i])==0){
			k=0;
		}
		if(s[0]=='0'){
			k=0;
		}
	}
	return k;
}
int main(){
	while(scanf("%s%*c",a)!=EOF){
		cin.getline(b,maxn);
		int lena=strlen(a);
		int lenb=strlen(b);
		int suma=0,sumb=0;
		if(is_zhengshu(a,lena)==1){
			for(int i=0;i<lena;i++){
				suma=suma*10;
				suma+=(int)(a[i]-'0');
			}
			if(suma>=1&&suma<=1000){
				cout<<a;
			}else{
				cout<<"?";
			}
		}else{
			cout<<"?";
		}
		cout<<" "<<"+"<<" ";
		if(is_zhengshu(b,lenb)==1){
			for(int i=0;i<lenb;i++){
				sumb=sumb*10;
				sumb+=(int)(b[i]-'0');
			}
				if(sumb>=1&&sumb<=1000){
					cout<<b;
				}else{
					cout<<"?";
				}
		}else{
			cout<<"?";
		}
		cout<<" "<<"="<<" ";
		if(is_zhengshu(a,lena)==1&&is_zhengshu(b,lenb)==1&&suma>=1&&suma<=1000&&sumb>=1&&sumb<=1000){
			cout<<suma+sumb<<endl;
		}else{
			cout<<"?"<<endl;
		}
	}
	return 0;
}
