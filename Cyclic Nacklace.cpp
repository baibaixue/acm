#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
char str[maxn];
int Next[maxn];
int len;
int length;
void GetNext(){
	Next[0]=-1;
	int i=0;
	int j=-1;
	for(int i=1;i<len;i++){
		while(j>-1&&str[j+1]!=str[i]){
			j=Next[j];
		}
		if(str[j+1]==str[i]){
			j=j+1;
		}
		Next[i]=j;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		//memset(str,0,sizeof(str));
		memset(Next,0,sizeof(Next));
		scanf("%s",str);
		len=strlen(str);
		length=0;
		GetNext();
		int ans;
		ans=len-Next[len-1]-1;
		if(len==1){
			printf("1\n");
		}else{
			if(ans==len){
				printf("%d\n",len);
			}else if(len%ans==0){
				printf("0\n");
			}else{
				printf("%d\n",ans-len%ans);
			}
		}
	}
	return 0;
}
