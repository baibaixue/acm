#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int m[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main(){
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<17;i++){
		sum+=(s[i]-'0')*m[i];
	}
	printf("%d",sum%11);
	return 0;
}
