#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 100005
using namespace std;
int c[maxn];
int main(){  
    int n,a,m,b;  
    while(scanf("%d",&n)!=EOF&&n){ 
    	int a,b;
        memset(c,0,sizeof(c));
        int j=n;
		m=0;  
        while(j--){  
            scanf("%d%d",&a,&b);  
            c[a]++;
			c[b+1]--;  
        }  
        for(int i=1;i<n;i++){  
            m+=c[i];
            printf("%d ",m);  
        }  
        printf("%d\n",m+c[n]);  
    }  
    return 0;  
}
