#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#define maxn 150005
using namespace std;
set<int>Nums;
bool isGe(int n) {
    if(n==1) return true;
    int tmp=n;
    //int start=false;
    int sum=0;
    while(tmp!=1){
        sum=0;
        while(tmp!=0){
            sum+=pow((tmp%10),2);
            tmp=tmp/10;
        }
        tmp=sum;
        if(Nums.find(tmp)!=Nums.end()) {
        	Nums.insert(tmp);
			return false;
		}
    }
    return true;
}
int N[maxn];
int main(){
	int q,k;
	while(scanf("%d",&q)!=EOF){
		int t=1;
		for(int j=2;j<=6;j++){
			Nums.insert(j);
		}
		for(int i=1;t<=150000;i++){
			if(isGe(i)==true){
				N[t++]=i;
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d",&k);
			printf("%d\n",N[k]);
		}
	}
	return 0;
}
