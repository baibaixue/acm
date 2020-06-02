#include<stdio.h>
#include<string.h>
int main(){
	int t;
	int cnt[20]; 
	while(scanf("%d",&t)!=EOF){
		scanf("%*c");
		while(t--){
			char c[200];
			memset(cnt,0,sizeof(cnt));
			gets(c);
			int len=strlen(c);
			char a;
			for(int i=0;i<len;i++){
				a=c[i];
				switch(a){
					case 'A':cnt[0]++;break;
					case 'B':cnt[1]++;break;
					case 'C':cnt[2]++;break;
					case 'D':cnt[3]++;break;
					case '1':cnt[4]++;break;
					case '2':cnt[5]++;break;
					case '3':cnt[6]++;break;
					case '4':cnt[7]++;break;
					case '5':cnt[8]++;break;
					case '6':cnt[9]++;break;
					case '7':cnt[10]++;break;
					case '8':cnt[11]++;break;
					case '9':cnt[12]++;break;
					case '0':cnt[13]++;break;
					case 'J':cnt[14]++;break;
					case 'Q':cnt[15]++;break;
					case 'K':cnt[16]++;break;
				}
			}
				cnt[4]=cnt[4]-cnt[13];
			for(int i=0;i<4;i++){
				if(cnt[i]==12){
					printf("%c",'A'+i);
				}
			}
			for(int j=4;j<13;j++){
				if(cnt[j]==3){
					printf("%c",'1'+j-4);
				}
			}
			if(cnt[13]==3){
				printf("10");
			}else if(cnt[14]==3){
				printf("J");
			}else if(cnt[15]==3){
				printf("Q");
			}else if(cnt[16]==3){
				printf("K");
			}
			printf("\n");
		}
	}
	return 0;
}
