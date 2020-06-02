#include<cstdio>
int main(){
	int num[12];
	for(int i=0;i<12;i++){
		scanf("%d",&num[i]);
	}
	int money=0;
	int buget=0;
	int no=0;
	for(int i=0;i<12;i++){
		money+=300;
		if(num[i]>money){
			no=1;
			printf("-%d\n",i+1);
			break;
		}else{
			money=money-num[i];
			if(money>=100){
				buget+=money/100*100;
				money=money-money/100*100;
			}
		}
	}
	if(no==0){
		printf("%d\n",(int)(buget*1.2+money));
	} 
	return 0;
}
