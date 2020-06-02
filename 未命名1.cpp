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
	cout<<"������"<<endl;
	return 1;
	}
	else{
	cout<<"��ƽ��"<<endl;
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
	cout<<"�Ǹ���ĵ�"<<days<<"��"<<endl;
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
        case 0: setDate(y,m,d); cout << "������һ" << endl; break;  
        case 1: setDate(y,m,d); cout << "�����ڶ�" << endl; break;  
        case 2: setDate(y,m,d); cout << "��������" << endl; break;  
        case 3: setDate(y,m,d); cout << "��������" << endl; break;  
        case 4: setDate(y,m,d); cout << "��������" << endl; break;  
        case 5: setDate(y,m,d); cout << "��������" << endl; break;  
        case 6: setDate(y,m,d); cout << "��������" << endl; break;  
    }  
}  
void Date::nextDate(int y,int m,int d){
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
    if(d<a[m])  {
	d=d+1;
	cout<<"��һ����"<<y<<"/"<<m<<"/"<<d<<endl;
	}
    else{
    	d=1;
		if(m<12) {
		m=m+1;
		cout<<"��һ����"<<y<<"/"<<m<<"/"<<d<<endl;
		}
		else{
			m=1;
			y+=1;
			cout<<"��һ����"<<y<<"/"<<m<<"/"<<d<<endl;
		}
	} 	
}

inline void Date::showDate(){
   cout<<year<<"/"<<month<<"/"<<day<<endl;
}

int main()
{
	int year,month,day;
	cout << "�������� �� ��" << endl;  
    cin >> year >> month >> day ;
    //Date setDate(year,month,day);//���﾿�����л���û�в������������ô��� 
    Date c/*(setDate)*/;//setDateֻ��һ���ຯ�� ���ƺ������Ƶ�������� 
/*	c.checkDate(year,month,day);
    c.showDate();
    c.isLeap(year);
    c.days(year,month,day);
    c.WeekDay(year,month,day);
    c.nextDate(year,month,day);*///c���������ģ���û�ж���Ϳ�ʼ�ÿ϶����� 
    return 0;
}
