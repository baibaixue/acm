#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 405
using namespace std;
int c[maxn];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            int t;
            if(l>r){
                t=l;
                l=r;
                r=t;
            }
            if(l%2==1){
                l=l+1;
            }if(r%2==1){
                r=r+1;
            }
            for(int j=l;j<=r;j++){
                c[j]++;
            }
        }
        sort(c,c+maxn,cmp);
        printf("%d\n",c[0]*10);
    }
    return 0;
} 
