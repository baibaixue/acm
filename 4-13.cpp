#include<cstdio>
#include<iostream>
using namespace std;
const double pi=3.1415;
class Circle{
	public:
		Circle();//构造函数 
		void getArea();
		~Circle() {} 
	private:
		double radius;//私有成员半径 
}; 
Circle::Circle(){
	radius=2.0;//默认半径为2.0 
}
inline void Circle::getArea(){
	cout<<"面积约为："<<pi*pi*radius<<endl;
}
int main(){
	Circle c;
	c.getArea();
	return 0;
}
/*输出结果：
————————————————————————————
面积约为：19.738
————————————————————————————
*/ 
 
