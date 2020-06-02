#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char yuan[150];
char secret[150];
char article[150];
char ans[150];
int A[30];
int B[30];
int main(){
	scanf("%s",secret);
	scanf("%s",yuan);
	scanf("%s",article);
	for(int i=0;i<30;i++){
		A[i]=-1;
		B[i]=-1;
	}
	int failed=0;
	int len=strlen(secret);
	for(int i=0;i<len;i++){
		if((secret[i]<='Z'&&secret[i]>='A')||(yuan[i]<='Z'&&yuan[i]>='A')){
			int a=(int)(secret[i]-'A');
			int b=(int)(yuan[i]-'A');
			if((A[a]==-1&&B[b]==-1)||(A[a]==b&&B[b]==a)){
				A[a]=b;
				B[b]=a;
			}else{
				failed=1;
				break;
			}
		}else{
			failed=1;
		}
	}
	for(int i=0;i<26;i++){
		if(A[i]==-1){
			failed=1;
			break;
		}
	}
	int L=strlen(article);
	for(int i=0;i<L;i++){
		int c=(int)(article[i]-'A');
		if(A[c]!=-1){
			ans[i]=(char)(A[c]+'A');
		}else{
			failed=1;
		}
	}
	if(failed==1){
		printf("Failed\n"); 
	}else{
		printf("%s",ans);
		printf("\n");
	}
	return 0;
}
