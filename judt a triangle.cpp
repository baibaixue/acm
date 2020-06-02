#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int t;
		if(c<b){
			t=b;b=c;c=t;
		}
		if(a>b){
			t=a;a=b;b=t;
		}
		if(b>c){
			t=b;b=c;c=t;
		}
		if(a==b||b==c){
			printf("perfect");
		}else if(a*a+b*b==c*c){
			printf("good");
		}else{
			printf("just a triangle");
		}
		printf("\n");
	}
	return 0;
}
