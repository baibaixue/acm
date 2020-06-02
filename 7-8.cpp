#include<cstdio>
#include<cmath>
#include<ctype.h>
struct id{
	char t[20];
}num[120];
char m[]={'1','0','X','9','8','7','6','5','4','3','2'};
double x[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",num[i].t);
		}
		int k=0;
		for(int i=0;i<n;i++){
			int sum=0;
			int l=0;
			for(int j=0;j<17;j++){
				if(isalpha(num[i].t[j])){
					l=1;
					break;
				}
				sum+=((int)(num[i].t[j]-'0')*x[j]);
			}
			sum=sum%11;
			if(m[sum]!=num[i].t[17]||l==1){
				for(int j=0;j<18;j++){
					printf("%c",num[i].t[j]);
					k=1;
				}
				printf("\n");
			}
		}
		if(k==0){
			printf("All passed\n");
		}
	}
	return 0;
} 
