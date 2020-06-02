#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
char str[50];
int main(){
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		cin.getline(str,50,'\n');
		long long n=0;
		for(int i=0;i<strlen(str);i++){
			if(str[i]<='9'&&str[i]>='0'){
				n=n*10+(long long)str[i]-'0';
			}
		}
		printf("%lld\n",n*513);
	}
}
