#include<stdio.h>//11��26��  ��ѩ �����жϼ�Ԫ������ 
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
		printf("������\n"); 
		week=week-1;
	}else{
		printf("��������\n");
	} 
	switch(week){
		case 1:printf("����һ\n");break;
		case 2:printf("���ڶ�\n");break;
		case 3:printf("������\n");break;
		case 4:printf("������\n");break;
		case 5:printf("������\n");break;
		case 6:printf("������\n");break;
		case 0:printf("������\n");break;
	} 
} 
