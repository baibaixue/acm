#include<cstdio> 
#include<string.h>
using namespace std;
int main(){
	char c;
	while(scanf("%c",&c)!=EOF){
		int g=0,p=0,l=0,t=0;
			if(c=='G'||c=='g'){
				g++;
			}if(c=='P'||c=='p'){
				p++;
			}if(c=='L'||c=='l'){
				l++;
			}if(c=='T'||c=='t'){
				t++;
			}
		for(;;){
			scanf("%c",&c);
			if(c=='\n'){
				break;
			}if(c=='G'||c=='g'){
				g++;
			}if(c=='P'||c=='p'){
				p++;
			}if(c=='L'||c=='l'){
				l++;
			}if(c=='T'||c=='t'){
				t++;
			}	
		}
		while(g!=0||p!=0||l!=0||t!=0){
			if(g!=0){
				printf("G");
				g--;
			}if(p!=0){
				printf("P");
				p--;
			}if(l!=0){
				printf("L");
				l--;
			}if(t!=0){
				printf("T");
				t--;
			}
		}
		printf("\n");
	}
	return 0;
}
