#include<cstdio>
#include<iostream>
using namespace std;
const double pi=3.1415;
class Circle{
	public:
		Circle();//���캯�� 
		void getArea();
		~Circle() {} 
	private:
		double radius;//˽�г�Ա�뾶 
}; 
Circle::Circle(){
	radius=2.0;//Ĭ�ϰ뾶Ϊ2.0 
}
inline void Circle::getArea(){
	cout<<"���ԼΪ��"<<pi*pi*radius<<endl;
}
int main(){
	Circle c;
	c.getArea();
	return 0;
}
/*��������
��������������������������������������������������������
���ԼΪ��19.738
��������������������������������������������������������
*/ 
 
