#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
//int w(long long a,long long b,long long c){
//	int ans;
//	if(a<=0||b<=0||c<=0){
//		return 1;
//	}else if(a>20||b>20||c>20){
//		ans=w(20,20,20);
//		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans);
//		return ans;
//	}else if(a<b&&b<c){
//		ans=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
//		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans);
//		return ans;
//	}else{
//		ans=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
//		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans);
//		return ans;
//	}
//}
int w[25][25][25];
int main(){
	long long a,b,c;
	memset(w,0,sizeof(w));
	for(int i=0;i<=20;i++){
		for(int j=0;j<=20;j++){
			w[0][i][j]=1;
			w[i][0][j]=1;
			w[i][j][0]=1;
		}
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++){
			for(int k=1;k<=20;k++){
				if(i<b&&b<c){
					w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
				}else{
					w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
				}
			}
		} 
	}
	while(1){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1){
			break;
		}else{
			int ans;
			if(a<=0||b<=0||c<=0){
				ans=1;
			}else if(a>20||b>20||c>20){
				ans=w[20][20][20];
			}else{
				ans=w[(int)a][(int)b][(int)c];
			}
			printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans);
		}
	}
}
