#include<stdio.h>
#include<string.h>
char s[10010];
int b[10];

int main(){
	while(scanf("%s",s)!=EOF){
		memset(b,0,sizeof(b));
		int n=strlen(s);
		for(int i=0;i<n;i++){
			switch(s[i]){
				case '0': b[0]++;break;
				case '1': b[1]++;break;
				case '2': b[2]++;break;
				case '3': b[3]++;break;
				case '4': b[4]++;break;
				case '5': b[5]++;break;
				case '6': b[6]++;break;
				case '7': b[7]++;break;
				case '8': b[8]++;break;
				case '9': b[9]++;break;
			}
		}
		for(int i=0;i<10;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	return 0;
}
