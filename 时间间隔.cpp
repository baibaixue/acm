#include<cstdio>
#include<iostream>
using namespace std;
const int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Date{
	public:
		Date(int y,int m,int d){
			year=y;
			month=m;
			day=d;
		}
		void show_time(){//输出日期 
			cout<<"日期:"<<year<<"/"<<month<<"/"<<day<<endl;
		}
		int days();
		bool leap_year();//判断该年是否是闰年 
	private:
		int year,month,day;//私有数据 
};
bool Date::leap_year(){
	if((year%4==0&&year%100!=0)||(year%400==0)){
		return true;
	}
	return false;
}
bool is_leap_year(int year){
	if((year%4==0&&year%100!=0)||(year%400==0)){
		return true;
	}
	return false;
}
int Date::days(){
	int sum=0;
	for(int i=0;i<month;i++){
		sum+=month_day[i];
	}
	sum+=day;
	if(leap_year()==1&&month>2){
		sum++;
	}
	return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int y,m,d;
		scanf("%d-%d-%d",&y,&m,&d);
		Date a(y,m,d);
		int h,min,s;
		scanf("%d:%d:%d",&h,&min,&s);
		int ds=0;
		for(int i=y;i<2050;i++){
			if(is_leap_year(i)){
				ds+=366;
			}else{
				ds+=365;
			}
		}
		ds-=a.days();
		int ans=((ds%100)*24*3600)%100+(24*3600-h*3600-min*60-s);
		printf("%d\n",ans%100);
	}
}
