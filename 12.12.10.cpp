#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#define maxn 100005
using namespace std; 
int address[maxn];
int ne_xt[maxn];
int num[maxn];
int fre[maxn];
int main(){
	int a,n,b;
	int A;
	int N;
	scanf("%d%d",&A,&N);
//	int B;
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&a,&n,&b);
			address[a]=n;
			ne_xt[n]=b;
			fre[n]=a;
//		if(b==-1){
//			B=a;
//		}
		//printf("adress[%05d]=%d\nnext[%d]=%05d\nfre[%d]=%05d\n",a,n,n,b,n,a);
	}
	int len=0;
	for(int i=0;A!=-1;i++){
		num[i]=address[A];
		A=ne_xt[address[A]];
		len++;
	}
	if(len%2==0){
		for(int i=0;i<len/2;i++){
			printf("%05d %d %05d\n",fre[num[len-i-1]],num[len-i-1],fre[num[i]]);
			if(len-i-2>=len/2)
				printf("%05d %d %05d\n",fre[num[i]],num[i],fre[num[len-i-2]]);
			else{
				printf("%05d %d -1\n",fre[num[i]],num[i]);
			}
		}
	}else{
		for(int i=0;i<len/2;i++){
			printf("%05d %d %05d\n",fre[num[len-i-1]],num[len-i-1],fre[num[i]]);
			printf("%05d %d %05d\n",fre[num[i]],num[i],fre[num[len-i-2]]);
		}
		printf("%05d %d -1\n",fre[num[len/2]],num[len/2]);
	}
	return 0;
}

