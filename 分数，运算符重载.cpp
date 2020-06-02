#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Fract{
	friend ostream& operator<<(ostream& out,const Fract& f);//输出流重载 
	friend istream& operator>>(istream& in,Fract& f);//输入流重载 
	public:
		Fract(){
			num=1;
			den=2; 
		};//默认参数构造函数 
		Fract(int a,int b){//构造函数 
			num=a;den=b;
		}
		bool is_fract();//判断分数是否合法
		Fract simply();//分数化简 
		Fract(double r){//类型转化，实数转换为分数 
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
		double transfer();//类型转换，分数转换为实数 
		void show_Fract(){//输出分数 
			cout<<num<<"/"<<den<<endl;
		}
		Fract operator+(const Fract& rhs)const;//加 
		Fract operator-(const Fract& rhs)const;//减 
		Fract operator-()const;//负 
		Fract operator*(const Fract& rhs)const;//乘
		Fract operator/(const Fract& rhs)const;//除 
		bool operator==(const Fract& rhs)const;//是否相等 
		bool operator!=(const Fract& rhs)const;//是否不等 
		bool operator>=(const Fract& rhs)const;//是否大于等于
		bool operator<=(const Fract& rhs)const;//是否大于小于 
		Fract operator++();//前置自增 
		Fract operator++(int);//后置自增
		Fract operator--();//前置自减 
		Fract operator--(int);//后置自减 
		~Fract(){}; //析构函数 
	private:
		int num;//分子
		int den;//分母 
};
bool Fract::is_fract(){//判断分数是否合法 
	return den!=0;
}
double Fract::transfer(){//分数转化为小数 
	return num*1.0/den;
}
Fract Fract::simply(){//分数简化 
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
ostream& operator<<(ostream& out,const Fract& f){//友函数 输出流 
	out<<f.num<<"/"<<f.den;
	return out;
}
istream& operator>>(istream& in,Fract& f){//友函数 输入流 
	char c;
	in>>f.num>>c>>f.den;
	return in;
}
Fract Fract::operator+(const Fract& rhs)const{//加 
	Fract temp;
	temp.num=num*rhs.den+rhs.num*den;
	temp.den=den*rhs.den; 
	return temp.simply();
}
Fract Fract::operator-(const Fract& rhs)const{//减
	Fract temp;
	temp.num=num*rhs.den-rhs.num*den;
	temp.den=den*rhs.den; 
	return temp.simply();
}
Fract Fract::operator-()const{//负 
	return Fract(-num,den);
}
Fract Fract::operator*(const Fract& rhs)const{//乘
	Fract temp;
	temp.num=num*rhs.num;
	temp.den=den*rhs.den;
	return temp.simply(); 
}
Fract Fract::operator/(const Fract& rhs)const{//除 
	Fract temp;
	temp.num=num*rhs.den;
	temp.den=den*rhs.num;
	return temp.simply(); 
}
bool Fract::operator==(const Fract& rhs)const{//是否相等 
	Fract temp;
	temp.num=rhs.num;temp.den;
	temp=temp.simply();
	return num==temp.num&&den==temp.den;
}
bool Fract::operator!=(const Fract& rhs)const{//是否不相等 
	Fract temp;
	temp.num=rhs.num;temp.den;
	temp=temp.simply();
	return num!=temp.num||den!=temp.den;
}
bool Fract::operator>=(const Fract& rhs)const{//是否大于等于 
	return (num*1.0/den)>=(rhs.num*1.0/rhs.den);
}
bool Fract::operator<=(const Fract& rhs)const{//是否小于等于 
	return (num*1.0/den)<=(rhs.num*1.0/rhs.den);
}
Fract Fract::operator++(){//前置自加 
	num+=den;
	return *this;
}
Fract Fract::operator++(int){//后置自加 
	Fract temp=*this;
	num+=den;
	return temp;
}
Fract Fract::operator--(){//前置自减 
	num-=den;
	return *this;
} 
Fract Fract::operator--(int){//后置自减 
	Fract temp=*this;
	num-=den;
	return temp;
}
int main(){
	Fract f1;
	cout<<"第一组：\nf1=";
	f1.show_Fract();
	if(f1.is_fract()){
		cout<<setiosflags(ios::fixed)<<setprecision(2);//输出形式 
		cout<<"化为分数形式："<<f1.transfer()<<"\n"<<endl;
		 
		cout<<"单目运算；自加、自减、负："<<endl; 
		cout<<"f1++="<<f1++<<endl;
		cout<<"f1="<<f1<<endl;
		cout<<"++f1="<<++f1<<endl;
		cout<<"f1--="<<f1--<<"\n"<<"--f1="<<--f1<<endl;
		cout<<"-f1="<<-f1<<endl;
		
		cout<<"\n"<<"加减乘除："<<endl; 
		Fract f2(f1);
		cout<<"f2="<<f2<<endl;
		cout<<"f1*0.75="<<f1*0.75<<endl;//将小数类型转换为分数 
		cout<<"f2+f1="<<f2+f1<<endl;
		cout<<"f1-f2="<<f1-f2<<endl;
		cout<<"f1*f2="<<f1*f2<<endl;
		cout<<"f1/f2="<<f1/f2<<endl;
		
		cout<<"\n"<<"是否相等判断："<<endl; 
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
		cout<<"分数无意义"<<endl; 
	}
	
	cout<<"\n"<<"第二组：\nf4=";
	Fract f4(1,0);
	f4.show_Fract();
	if(!f4.is_fract()){
		cout<<"分数无意义"<<endl;//分母为零 
	}
	
	Fract f5(4,10);
	cout<<"\n"<<"第三组：\nf5=";
	f5.show_Fract();
	cout<<"化简后:f5="<<f5.simply()<<endl;
	Fract f6(1,10);
	cout<<"f6="<<f6<<"\n"<<"f5+f6="<<f5+f6<<endl;//相加后依然是最简形式 
	
	Fract f7,f8;
	cout<<"\n"<<"请输入两个分数（以空格隔开）:"; 
	cin>>f7>>f8;
	if(f7.is_fract()){
		cout<<"f7="<<f7.simply()<<endl;
	}else if(!f7.is_fract()){
		cout<<"f7输入非法！"<<endl; 
	}
	if(f8.is_fract()){
		cout<<"f8="<<f8.simply()<<endl;
	}else if(!f8.is_fract()){
		cout<<"f8输入非法！"<<endl; 
	}
	return 0;
}
/*
------------------------------------------
输出结果：
第一组：
f1=1/2
化为分数形式：0.50

单目运算；自加、自减、负：
f1++=1/2
f1=3/2
++f1=5/2
f1--=3/2
--f1=3/2
-f1=-1/2

加减乘除：
f2=1/2
f1*0.75=3/8
f2+f1=1/1
f1-f2=0/1
f1*f2=1/4
f1/f2=1/1

是否相等判断：
f1==f2
f3=1/1
f3!=f1
f3>=f1

第二组：
f4=1/0
分数无意义

第三组：
f5=4/10
化简后:f5=2/5
f6=1/10
f5+f6=1/2

请输入两个分数（以空格隔开）:122/234 123/0
f7=61/117
f8输入非法！
--------------------------------------- 
*/ 
