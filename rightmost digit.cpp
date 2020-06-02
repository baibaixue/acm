#include<stdio.h>
int main(){
	long long int n;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		switch(n%10){
			case 0:printf("0");break;
			case 1:printf("1");break;
			case 4:printf("6");break;
			case 5:printf("5");break;
			case 6:printf("6");break;
			case 9:printf("9");break;
			case 2:if((n/10)%2==0) printf("4"); else printf("6");break;
			case 3:if((n/10)%2==0) printf("7"); else printf("3");break;
			case 7:if((n/10)%2==0) printf("3"); else printf("7");break;
			case 8:if((n/10)%2==0) printf("6"); else printf("4");break;
		}
		printf("\n");
	}
	return 0;
}
