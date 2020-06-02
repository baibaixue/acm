#include<cstdio>
#include<iostream>
using namespace std;
const int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//�������� 
class Date{
	public:
		Date(){//�޲����Ĺ��캯�� 
			year=2007;
			month=1;
			day=1;
		}
		Date(int y,int m,int d){//�������� �в����Ĺ��캯�� 
			year=y;
			month=m;
			day=d;
		}
		void set_time(){//�����û����� 
			cout<<"����������(eg:�� �� ��):";
			cin>>year>>month>>day;
		} 
		void show_time(){//������� 
			cout<<"����:"<<year<<"/"<<month<<"/"<<day<<endl;
		}
		int days();
		void next_day(Date& p);//�����ಢ�����е�˽�����ݽ����޸� 
		void weekend();//�ж���һ�������ڼ� 
		bool leap_year();//�жϸ����Ƿ������� 
		void integration(Date& d);//��������������һ�� 
		~Date() {//��������
		cout<<"��Ӧ�ڴ��ѱ��ͷš�"<<endl; 
		} 
	private:
		int year,month,day;//˽������ 
};
bool Date::leap_year(){
	if((year%4==0&&year%100!=0)||(year%400==0)){
		cout<<"��һ�������ꡣ"<<endl;
		return true;
	}
	cout<<"��һ����ƽ�ꡣ"<<endl;
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
	cout<<"��һ������һ��ĵ�"<<sum<<"�졣"<<endl;
	return sum;
}
void Date::weekend(){
	int sum=0;
	int x=year%100;
	sum=(x-1)+(x-1)/4-(x-1)/100+(x-1)/400+days();
	sum=sum%7;
	cout<<"��һ��������";
	switch(sum){
		case 0:cout<<"�ա�"<<endl;break; 
		case 1:cout<<"һ��"<<endl;break; 
		case 2:cout<<"����"<<endl;break; 
		case 3:cout<<"����"<<endl;break; 
		case 4:cout<<"�ġ�"<<endl;break; 
		case 5:cout<<"�塣"<<endl;break; 
		case 6:cout<<"����"<<endl;break; 
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
	cout<<"��һ��";
}   
void Date::integration(Date& d){
	show_time();//������� 
	weekend();//�ж���һ�������ڼ�
	next_day(d);
	show_time();//����޸ĺ������ 
	cout<<"\n";
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
int main(){
	cout<<"Ĭ������:"<<endl; 
	Date t0;
	t0.integration(t0);
	
	cout<<"�������ݣ�"<<endl;
	Date t1(2005,2,28);//�������� 
	t1.integration(t1);

	cout<<"���ƽ����"; 
	Date t2(t1);//���ƹ��캯�� �����޸ĺ�t1������ 
	t2.integration(t2);

	cout<<"�������ݣ�"<<endl; 
	Date t3;
	t3.set_time();//�����û����� 
	t3.integration(t3);
	
	return 0;
} 
/*��������
����������������������������������������������������������������������������������������
Ĭ������:
����:2007/1/1
��һ����ƽ�ꡣ
��һ������һ��ĵ�1�졣
��һ��������һ��
��һ������:2007/1/2

�������ݣ�
����:2005/2/28
��һ����ƽ�ꡣ
��һ������һ��ĵ�59�졣
��һ��������һ��
��һ������:2005/3/1

���ƽ��������:2005/3/1
��һ����ƽ�ꡣ
��һ������һ��ĵ�60�졣
��һ�������ڶ���
��һ������:2005/3/2

�������ݣ�
����������(eg:�� �� ��):2018 12 31
����:2018/12/31
��һ����ƽ�ꡣ
��һ������һ��ĵ�365�졣
��һ��������һ��
��һ������:2019/1/1

��Ӧ�ڴ��ѱ��ͷš�
��Ӧ�ڴ��ѱ��ͷš�
��Ӧ�ڴ��ѱ��ͷš�
��Ӧ�ڴ��ѱ��ͷš�
������������������������������������������������������������������������������������
*/ 
 
