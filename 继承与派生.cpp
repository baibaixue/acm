/*p304 7-5*/
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
/*Shape��*/ 
class Shape{

	public:
		getArea(){}; 
};
/*Rectangle�� ������*/ 
class Rectangle:public Shape{
	public:
		Rectangle();
		Rectangle(double xx,double yy);
		Rectangle(const Rectangle& t);
		double getArea();
	private:
		double x,y; 
};
Rectangle::Rectangle(){
	x=0;y=0;
} 
Rectangle::Rectangle(double xx,double yy){
	x=xx;y=yy;
} 
Rectangle::Rectangle(const Rectangle& t){
	x=t.x;y=t.y;
} 
double Rectangle::getArea(){
	return x*y;
} 
/*Circle�� Բ��*/ 
class Circle:public Shape{
	public:
		Circle();
		Circle(double xx,double yy,double rr);
		Circle(const Circle& t);
		double getArea();
	private:
		double x,y;
		double r;
};
Circle::Circle(){
	x=0;y=0;r=0;
}
Circle::Circle(double xx,double yy,double rr){
	x=xx;y=yy;r=rr;
} 
Circle::Circle(const Circle& t){
	x=t.x;y=t.y;r=t.r;
} 
double Circle::getArea(){
	return 3.14*r*r;
}
/*Square�� ������*/ 
class Square:public Rectangle{
	public:
		Square();
		Square(double aa);
		Square(const Square& t);
	
};
Square::Square()
	:Rectangle()
	{
	}
Square::Square(double aa)
	:Rectangle(aa,aa)
	{
		 }
Square::Square(const Square& t)
	:Rectangle(t)
	{
	  } 
/*Cuboid�� ������*/
class Cuboid:public Rectangle{
	public:
		Cuboid();
		Cuboid(double xx,double yy,double zz);
		Cuboid(const Cuboid& t);
		double getVolum();
	private:
		double z;
};
Cuboid::Cuboid()
	:Rectangle()
	{
		z=0;
		}
Cuboid::Cuboid(double xx,double yy,double zz)
	:Rectangle(xx,yy)
	{
		z=zz;
		}
Cuboid::Cuboid(const Cuboid& t)
	:Rectangle(t)
	{
		z=t.z;
		} 
double Cuboid::getVolum(){
	return (*this).getArea()*z;
} 
/*Globe�� ��*/
class Globe:public Circle{
	public:
		Globe();
		Globe(double xx,double yy,double rr,double zz);
		Globe(const Globe& t);
		double getVolum();
	private:
		double z;
}; 
Globe::Globe(){
	z=0;
}
Globe::Globe(double xx,double yy,double rr,double zz)
	:Circle(xx,yy,rr)
	{
		z=zz;
		}
Globe::Globe(const Globe& t)
	:Circle(t)
	{
		z=t.z;
	 }
double Globe::getVolum(){
	return pow((*this).getArea()/3.14,1.5)*3.14*4.0/3.0;
}
/*Cube�� ������*/
class Cube:public Square{
	public:
		Cube();
		Cube(double aa);
		Cube(const Cube& t);
		double getVolum();
};
Cube::Cube(){}
Cube::Cube(double aa)
	:Square(aa){}
Cube::Cube(const Cube& t)
	:Square(t){}
double Cube::getVolum(){
	return pow((*this).getArea(),1.5);
}
/*����*/ 
int main(){
	/*������*/ 
	Square a0;//Ĭ�Ϲ��캯�� 
	cout<<a0.getArea()<<endl; 
	Square a1(5);//��ʼ�� 
	cout<<a1.getArea()<<endl;
	/*������*/ 
	Rectangle a2(2,5);
	cout<<a2.getArea()<<endl;
	/*Բ��*/ 
	Circle a3(2,4,2);
	cout<<a3.getArea()<<endl;
	/*������*/ 
	Cuboid a4(1,2,3);
	Cuboid a5(a4);//���ƹ��� 
	cout<<a5.getVolum()<<endl;
	/*��*/ 
	Globe a6(1,2,4,3);
	Globe a7(a6);
	cout<<a7.getVolum()<<endl;
	/*������*/ 
	Cube a8(3);
	//cout<<a8.getArea()<<endl;
	cout<<a8.getVolum()<<endl;
}
/*������
-----------------------
0
25
10
12.56
6
267.947
27
----------------------
*/ 
