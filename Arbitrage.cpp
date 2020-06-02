#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#define maxn 300
using namespace std;
double dis[maxn][maxn];
int H[35];
double trans[maxn][maxn];
int hash(char *Tword){
	int a=0;
	int A=strlen(Tword);
	for(int i=0;i<min(5,A);i++){
		if(Tword[i]>='A'&&Tword[i]<='Z'){
			a+=(int)(Tword[i]-'A');
		}if(Tword[i]>='a'&&word[i]<='z'){
			a+=(int)(Tword[i]-'a');
		}
	}
//	while(trans[a][a]==1&&){
//		a++;
//	}
//	trans[a][a]=1;
	return a;
}
int main(){
	int t=1;
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(trans,0,sizeof(trans));
		memset(dis,0,sizeof(dis));
		for(int i=0;i<n;i++){
			char word[maxn];
			scanf("%s",word);
			H[i]=hash(word);
			dis[H[i]][H[i]]=1;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			char l_word[maxn];
			char n_word[maxn];
			double x;
			scanf("%s%lf%s",l_word,&x,n_word);
			memset(trans,0,sizeof(trans));
			dis[hash(l_word)][hash(n_word)]=x;
			
		}
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				for(int k=0;k<n;k++){
					dis[H[i]][H[j]]=max(dis[H[i]][H[k]]*dis[H[k]][H[j]],dis[H[i]][H[j]]);
				}
			}
		}
		int ok=0;
		for(int i=0;i<n;i++){
			if(dis[H[i]][H[i]]>1){
				ok=1;
				printf("Case %d: Yes\n",t);
				break;
			}
		}
		if(ok==0){
			printf("Case %d: No\n",t);
		}
		t++;
	}
	return 0;
}
