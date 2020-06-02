#include<stdio.h>
int leap_year(int y){
	if((y%4==0&&y%100!=0)||y%400==0){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int y,m;
	while(scanf("%d%d",&y,&m)!=EOF){
		if(leap_year(y)==1){
			printf("Leap year,");
		}else{
			printf("Common year,");
		}
		if(m<=5&&m>=3){
			printf("Spring,");
			if(m==3||m==5){
				printf("31\n");
			}else{
				printf("30\n");
			}
		}else if(m<=8&&m>=6){
			printf("Summer,");
			if(m==7||m==8){
				printf("31\n");
			}else{
				printf("30\n");
			}
		}else if(m<=11&&m>=9){
			printf("Fall,");
			if(m==10){
				printf("31\n");
			}else{
				printf("30\n");
			}
		}else{
			printf("Winter,");
			if(m==1||m==12){
				printf("31\n");
			}else if(m==2){
				if(leap_year(y)==1){
					printf("29\n");
				}else{
					printf("28\n");
				}
			}
		}
	}
	return 0;
}
