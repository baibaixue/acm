#include<cstdio> 
char n[55];
int main(){
	while(scanf("%c",&n[0])!=EOF){
		char c;
		int count=1;
		int two=0;
		for(;;){
			scanf("%c",&c);
			if(c=='\n'){
				break;
			}if(c=='2'){
				two++;
			}
			n[count++]=c;
		}
		double ans;
		int k=0;
		if(n[0]=='-'){
			k=1;
			count--;
		}else if(n[0]=='2'){
			two++;
		}
			ans=two/(count*1.0);
			if(k==1){
				ans=ans*1.5;
			}if((n[count+k-1]-'0')%2==0){
				ans=ans*2.0;
			}
			printf("%.2f%\n",ans*100);
		}
	return 0;
}
