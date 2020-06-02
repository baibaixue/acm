#include <iostream>
using namespace std;
class Date{
	public:
		void setDate(int newY=0,int newM=0,int newD=0){
			year=newY;
	        month=newM;
	        day=newD;
		};
		Date(Date& c);
		//int getY() {return year;}
		//int getM() {return month;}
		//int getD() {return day;}
		void showDate();
		bool checkDate(int y,int m,int d);
		bool isLeap(int year);
		void days(int y,int m,int d); 
		void WeekDay(int newY,int newM,int newD);
		void nextDate(int y,int m,int d);
		~Date(){}
	private:
		int year, month, day;
}; 

Date::Date(Date& c){
	year=c.year;
	month=c.month;
	day=c.day;
}

bool Date::checkDate(int y,int m,int d){
	{
		if(month<0||month>12||day>31||day<0||year<0||year>9999){
			return 0;}
      if( month==2 ){
    if(isLeap(year)==1){
     if(day>29){
          return 0;}
        }
		else{
         if(day>28){
         return 0;}
    }
       }
if(month==4||month==6||month==9||month==11){
		if(day>30){
			return 0;}
    }
		return 1;}
           }
bool Date::isLeap(int year){
	if((year%4==0&&year%100!=0)||year%400==0)	{
	cout<<"是闰年"<<endl;
	return 1;
	}
	else{
	cout<<"是平年"<<endl;
   return 0;
   	} 
}

void Date::days(int y,int m,int d){
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i,days=0;
	if(((year%4==0&&year%100!=0)||year%400==0) &&m>2){
		for(i=0;i<m;i++){ 
	days+=a[i];
	}
    days=days+d+1; 
	} 
	else{
			for(i=0;i<m;i++){ 
	days+=a[i];
	}
    days=days+d; 
	}
	cout<<"是该年的第"<<days<<"天"<<endl;
}
void Date::WeekDay(int y, int m, int d)  
{  
    if(m==1||m==2) 
    {  
        m+=12;  
        y--;  
    }  
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
    switch(Week)  
    {  
        case 0: setDate(y,m,d); cout << "是星期一" << endl; break;  
        case 1: setDate(y,m,d); cout << "是星期二" << endl; break;  
        case 2: setDate(y,m,d); cout << "是星期三" << endl; break;  
        case 3: setDate(y,m,d); cout << "是星期四" << endl; break;  
        case 4: setDate(y,m,d); cout << "是星期五" << endl; break;  
        case 5: setDate(y,m,d); cout << "是星期六" << endl; break;  
        case 6: setDate(y,m,d); cout << "是星期日" << endl; break;  
    }  
}  
void Date::nextDate(int y,int m,int d){
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
    if(d<a[m])  {
	d=d+1;
	cout<<"下一天是"<<y<<"/"<<m<<"/"<<d<<endl;
	}
    else{
    	d=1;
		if(m<12) {
		m=m+1;
		cout<<"下一天是"<<y<<"/"<<m<<"/"<<d<<endl;
		}
		else{
			m=1;
			y+=1;
			cout<<"下一天是"<<y<<"/"<<m<<"/"<<d<<endl;
		}
	} 	
}

inline void Date::showDate(){
   cout<<year<<"/"<<month<<"/"<<day<<endl;
}

int main()
{
	int year,month,day;
	cout << "请输入年 月 日" << endl;  
    cin >> year >> month >> day ;
    //Date setDate(year,month,day);//这里究竟是有还是没有参数？函数调用错了 
    Date c/*(setDate)*/;//setDate只是一个类函数 复制函数复制的是类对象 
/*	c.checkDate(year,month,day);
    c.showDate();
    c.isLeap(year);
    c.days(year,month,day);
    c.WeekDay(year,month,day);
    c.nextDate(year,month,day);*///c是哪里来的，你没有定义就开始用肯定报错 
    return 0;
}
