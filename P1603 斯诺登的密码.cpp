#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char letter[21][30]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"eleven"},{"twelve"},{"thirteen"},{"fourteen"},{"fifteen"},{"sixteen"},{"seventeen"},{"eighteen"},{"nineteen"},{"twenty"}};

char s[7][100];
int num[100];
int main(){
	memset(num,0,sizeof(num));
	for(int i=0;i<6;i++){
		scanf("%s",s[i]);
		getchar();
	}
	int l=strlen(s[5]);
	if(s[5][l-1]=='.'){
		s[5][l-1]='\0';
	}
	if(s[0][0]<='Z'&&s[0][0]>='A'){
		s[0][0]=s[0][0]+32; 
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<21;j++){
			if(strcmp(s[i],letter[j])==0){
				num[(j*j%100)]++;
				break;
			}
		}
			if(strcmp(s[i],"a")==0||strcmp(s[i],"first")==0||strcmp(s[i],"another")==0){
				num[1]++;
			}if(strcmp(s[i],"both")==0||strcmp(s[i],"second")==0){
				num[4]++;
			}if(strcmp(s[i],"third")==0){
				num[9]++;
			}
	}
	long long sum=0;
	for(int i=0;i<100;i++){
		while(num[i]!=0){
			sum=sum*100+i;
			num[i]--;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
