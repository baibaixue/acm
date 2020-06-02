#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Fract{
	friend ostream& operator<<(ostream& out,const Fract& f);//��������� 
	friend istream& operator>>(istream& in,Fract& f);//���������� 
	public:
		Fract(){
			num=1;
			den=2; 
		};//Ĭ�ϲ������캯�� 
		Fract(int a,int b){//���캯�� 
			num=a;den=b;
		}
		bool is_fract();//�жϷ����Ƿ�Ϸ�
		Fract simply();//�������� 
		Fract(double r){//����ת����ʵ��ת��Ϊ���� 
			int a=(int)r;
			double b=r-a;
			int t=1;
			while(b!=0){
				r*=10;
				t*=10;
				a=(int)r;
				b=r-a;
				num=a;den=t;
			}
		}
		double transfer();//����ת��������ת��Ϊʵ�� 
		void show_Fract(){//������� 
			cout<<num<<"/"<<den<<endl;
		}
		Fract operator+(const Fract& rhs)const;//�� 
		Fract operator-(const Fract& rhs)const;//�� 
		Fract operator-()const;//�� 
		Fract operator*(const Fract& rhs)const;//��
		Fract operator/(const Fract& rhs)const;//�� 
		bool operator==(const Fract& rhs)const;//�Ƿ���� 
		bool operator!=(const Fract& rhs)const;//�Ƿ񲻵� 
		bool operator>=(const Fract& rhs)const;//�Ƿ���ڵ���
		bool operator<=(const Fract& rhs)const;//�Ƿ����С�� 
		Fract operator++();//ǰ������ 
		Fract operator++(int);//��������
		Fract operator--();//ǰ���Լ� 
		Fract operator--(int);//�����Լ� 
		~Fract(){}; //�������� 
	private:
		int num;//����
		int den;//��ĸ 
};
bool Fract::is_fract(){//�жϷ����Ƿ�Ϸ� 
	return den!=0;
}
double Fract::transfer(){//����ת��ΪС�� 
	return num*1.0/den;
}
Fract Fract::simply(){//������ 
	int temp=1;
	if(num*den<0){
		temp=-1;
	}
	num=abs(num);
	den=abs(den);
	int a=num;
	int b=den;
	int c;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return Fract(temp*(num/a),den/a);
}
ostream& operator<<(ostream& out,const Fract& f){//�Ѻ��� ����� 
	out<<f.num<<"/"<<f.den;
	return out;
}
istream& operator>>(istream& in,Fract& f){//�Ѻ��� ������ 
	char c;
	in>>f.num>>c>>f.den;
	return in;
}
Fract Fract::operator+(const Fract& rhs)const{//�� 
	Fract temp;
	temp.num=num*rhs.den+rhs.num*den;
	temp.den=den*rhs.den; 
	return temp.simply();
}
Fract Fract::operator-(const Fract& rhs)const{//��
	Fract temp;
	temp.num=num*rhs.den-rhs.num*den;
	temp.den=den*rhs.den; 
	return temp.simply();
}
Fract Fract::operator-()const{//�� 
	return Fract(-num,den);
}
Fract Fract::operator*(const Fract& rhs)const{//��
	Fract temp;
	temp.num=num*rhs.num;
	temp.den=den*rhs.den;
	return temp.simply(); 
}
Fract Fract::operator/(const Fract& rhs)const{//�� 
	Fract temp;
	temp.num=num*rhs.den;
	temp.den=den*rhs.num;
	return temp.simply(); 
}
bool Fract::operator==(const Fract& rhs)const{//�Ƿ���� 
	Fract temp;
	temp.num=rhs.num;temp.den;
	temp=temp.simply();
	return num==temp.num&&den==temp.den;
}
bool Fract::operator!=(const Fract& rhs)const{//�Ƿ���� 
	Fract temp;
	temp.num=rhs.num;temp.den;
	temp=temp.simply();
	return num!=temp.num||den!=temp.den;
}
bool Fract::operator>=(const Fract& rhs)const{//�Ƿ���ڵ��� 
	return (num*1.0/den)>=(rhs.num*1.0/rhs.den);
}
bool Fract::operator<=(const Fract& rhs)const{//�Ƿ�С�ڵ��� 
	return (num*1.0/den)<=(rhs.num*1.0/rhs.den);
}
Fract Fract::operator++(){//ǰ���Լ� 
	num+=den;
	return *this;
}
Fract Fract::operator++(int){//�����Լ� 
	Fract temp=*this;
	num+=den;
	return temp;
}
Fract Fract::operator--(){//ǰ���Լ� 
	num-=den;
	return *this;
} 
Fract Fract::operator--(int){//�����Լ� 
	Fract temp=*this;
	num-=den;
	return temp;
}
int main(){
	Fract f1;
	cout<<"��һ�飺\nf1=";
	f1.show_Fract();
	if(f1.is_fract()){
		cout<<setiosflags(ios::fixed)<<setprecision(2);//�����ʽ 
		cout<<"��Ϊ������ʽ��"<<f1.transfer()<<"\n"<<endl;
		 
		cout<<"��Ŀ���㣻�Լӡ��Լ�������"<<endl; 
		cout<<"f1++="<<f1++<<endl;
		cout<<"f1="<<f1<<endl;
		cout<<"++f1="<<++f1<<endl;
		cout<<"f1--="<<f1--<<"\n"<<"--f1="<<--f1<<endl;
		cout<<"-f1="<<-f1<<endl;
		
		cout<<"\n"<<"�Ӽ��˳���"<<endl; 
		Fract f2(f1);
		cout<<"f2="<<f2<<endl;
		cout<<"f1*0.75="<<f1*0.75<<endl;//��С������ת��Ϊ���� 
		cout<<"f2+f1="<<f2+f1<<endl;
		cout<<"f1-f2="<<f1-f2<<endl;
		cout<<"f1*f2="<<f1*f2<<endl;
		cout<<"f1/f2="<<f1/f2<<endl;
		
		cout<<"\n"<<"�Ƿ�����жϣ�"<<endl; 
		if(f1==f2){
			cout<<"f1==f2"<<endl;
		}
		Fract f3(f2+f1);
		cout<<"f3="<<f3<<endl;
		if(f3!=f1){
			cout<<"f3!=f1"<<endl;
		}
		if(f3>=f1){
			cout<<"f3>=f1"<<endl;
		}
	}else{
		cout<<"����������"<<endl; 
	}
	
	cout<<"\n"<<"�ڶ��飺\nf4=";
	Fract f4(1,0);
	f4.show_Fract();
	if(!f4.is_fract()){
		cout<<"����������"<<endl;//��ĸΪ�� 
	}
	
	Fract f5(4,10);
	cout<<"\n"<<"�����飺\nf5=";
	f5.show_Fract();
	cout<<"�����:f5="<<f5.simply()<<endl;
	Fract f6(1,10);
	cout<<"f6="<<f6<<"\n"<<"f5+f6="<<f5+f6<<endl;//��Ӻ���Ȼ�������ʽ 
	
	Fract f7,f8;
	cout<<"\n"<<"�����������������Կո������:"; 
	cin>>f7>>f8;
	if(f7.is_fract()){
		cout<<"f7="<<f7.simply()<<endl;
	}else if(!f7.is_fract()){
		cout<<"f7����Ƿ���"<<endl; 
	}
	if(f8.is_fract()){
		cout<<"f8="<<f8.simply()<<endl;
	}else if(!f8.is_fract()){
		cout<<"f8����Ƿ���"<<endl; 
	}
	return 0;
}
/*
------------------------------------------
��������
��һ�飺
f1=1/2
��Ϊ������ʽ��0.50

��Ŀ���㣻�Լӡ��Լ�������
f1++=1/2
f1=3/2
++f1=5/2
f1--=3/2
--f1=3/2
-f1=-1/2

�Ӽ��˳���
f2=1/2
f1*0.75=3/8
f2+f1=1/1
f1-f2=0/1
f1*f2=1/4
f1/f2=1/1

�Ƿ�����жϣ�
f1==f2
f3=1/1
f3!=f1
f3>=f1

�ڶ��飺
f4=1/0
����������

�����飺
f5=4/10
�����:f5=2/5
f6=1/10
f5+f6=1/2

�����������������Կո������:122/234 123/0
f7=61/117
f8����Ƿ���
--------------------------------------- 
*/ 
