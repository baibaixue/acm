#include<cstdio>
const int mod=1e8+7;
long long n[10005];
int main(){
	n[0]=1;n[1]=1;n[2]=2;
	for(int i=3;i<=100;i++){
		n[i]=n[i-1];
		for(int j=i-2;j>=0;j-=2){
			n[i]+=n[j];
			n[i]%=mod;
		}
		printf("n[%d]=%lld\n",i,n[i]);
	}
}
