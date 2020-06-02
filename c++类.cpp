#include<cstdio>
#include<iostream>
using namespace std;
const int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//常量数组 
class Date{
	public:
		Date(){//无参数的构造函数 
			year=2007;
			month=1;
			day=1;
		}
		Date(int y,int m,int d){//函数重载 有参数的构造函数 
			year=y;
			month=m;
			day=d;
		}
		void set_time(){//读入用户数据 
			cout<<"请输入日期(eg:年 月 日):";
			cin>>year>>month>>day;
		} 
		void show_time(){//输出日期 
			cout<<"日期:"<<year<<"/"<<month<<"/"<<day<<endl;
		}
		int days();
		void next_day(Date& p);//引用类并对类中的私有数据进行修改 
		void weekend();//判断这一天是星期几 
		bool leap_year();//判断该年是否是闰年 
		void integration(Date& d);//将各功能整合在一起 
		~Date() {//析构函数
		cout<<"相应内存已被释放。"<<endl; 
		} 
	private:
		int year,month,day;//私有数据 
};
bool Date::leap_year(){
	if((year%4==0&&year%100!=0)||(year%400==0)){
		cout<<"这一年是闰年。"<<endl;
		return true;
	}
	cout<<"这一年是平年。"<<endl;
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
	cout<<"这一天是这一年的第"<<sum<<"天。"<<endl;
	return sum;
}
void Date::weekend(){
	int sum=0;
	int x=year%100;
	sum=(x-1)+(x-1)/4-(x-1)/100+(x-1)/400+days();
	sum=sum%7;
	cout<<"这一天是星期";
	switch(sum){
		case 0:cout<<"日。"<<endl;break; 
		case 1:cout<<"一。"<<endl;break; 
		case 2:cout<<"二。"<<endl;break; 
		case 3:cout<<"三。"<<endl;break; 
		case 4:cout<<"四。"<<endl;break; 
		case 5:cout<<"五。"<<endl;break; 
		case 6:cout<<"六。"<<endl;break; 
	}
	return ; 
}
void Date::next_day(Date& d){
	d.day++;
	if(d.day>month_day[d.month]){
		if(((d.year%4==0&&d.year%100!=0)||(d.year%400==0))&&d.month==2);
		else{
			d.day%=month_day[d.month];
			d.month++;
			if(d.month>12){
				d.month%=12;
				d.year++;
			}
		}
	}
	cout<<"下一天";
}   
void Date::integration(Date& d){
	show_time();//输出数据 
	weekend();//判断这一天是星期几
	next_day(d);
	show_time();//输出修改后的数据 
	cout<<"\n";
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
int main(){
	cout<<"默认数据:"<<endl; 
	Date t0;
	t0.integration(t0);
	
	cout<<"设置数据："<<endl;
	Date t1(2005,2,28);//设置数据 
	t1.integration(t1);

	cout<<"复制结果："; 
	Date t2(t1);//复制构造函数 复制修改后t1的数据 
	t2.integration(t2);

	cout<<"读入数据："<<endl; 
	Date t3;
	t3.set_time();//读入用户数据 
	t3.integration(t3);
	
	return 0;
} 
/*输出结果：
————————————————————————————————————————————
默认数据:
日期:2007/1/1
这一年是平年。
这一天是这一年的第1天。
这一天是星期一。
下一天日期:2007/1/2

设置数据：
日期:2005/2/28
这一年是平年。
这一天是这一年的第59天。
这一天是星期一。
下一天日期:2005/3/1

复制结果：日期:2005/3/1
这一年是平年。
这一天是这一年的第60天。
这一天是星期二。
下一天日期:2005/3/2

读入数据：
请输入日期(eg:年 月 日):2018 12 31
日期:2018/12/31
这一年是平年。
这一天是这一年的第365天。
这一天是星期一。
下一天日期:2019/1/1

相应内存已被释放。
相应内存已被释放。
相应内存已被释放。
相应内存已被释放。
——————————————————————————————————————————
*/ 
 
