#include<stdio.h>//11月26号  白雪 闰年判断及元旦星期 
#include<math.h>
int is_year(int y,int* p){
	*p=(int)fabs((y-1996)*365+(y-1996)/4+2)%7;
	if((y%4==0&&y%100!=0)||y%400==0){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int year;
	scanf("%d",&year);
	int week=0;
	int* p;
	p=&week;
	int ans=is_year(year,p);
	if(ans==1){
		printf("是闰年\n"); 
		week=week-1;
	}else{
		printf("不是闰年\n");
	} 
	switch(week){
		case 1:printf("星期一\n");break;
		case 2:printf("星期二\n");break;
		case 3:printf("星期三\n");break;
		case 4:printf("星期四\n");break;
		case 5:printf("星期五\n");break;
		case 6:printf("星期六\n");break;
		case 0:printf("星期天\n");break;
	} 
} 
