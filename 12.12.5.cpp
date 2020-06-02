#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std; 
int main()
{
    string s;
    int num=0,n;
    int a=1;
    scanf("%d",&n);
    for(;;){
        num++;
        if(s.length()||a/n!=0){
			s+='0'+a/n;
			}
        a%=n;
        if(a==0){
            cout<<s<<" "<<num<<"\n";
            return 0;
        }
        a=a*10+1;
    }
}

