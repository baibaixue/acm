#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    int t;
    char a[50];
    scanf("%d",&t);
    while(t--){
    	int n;
        scanf("%d",&n);
        getchar();
        int ans=0;
        while(n--)
        {
            cin.getline(a,33);
            if(a[0]=='i') ans+=4;
            if(a[0]=='f') ans+=4;
            if(a[0]=='b') ans+=1;
            if(a[0]=='c') ans+=1;
            if(a[0]=='l') ans+=8;
            if(a[0]=='d') ans+=8;
        }
        if(ans%1024==0){
			printf("%d\n",ans/1024);
		}
        else{
        	printf("%d\n",ans/1024+1);
		}
    }
    return 0;
}
