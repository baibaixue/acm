#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<iomanip>//格式控制 
using namespace std;
class Shape{
	public:
		Shape(){
			area=0;
		}
		virtual double getArea()=0;
		double area;
};
class Circle:public Shape{
	private:
		double r;
	public:
		Circle(){
			r=0;
		}
		Circle(double rr){
			r=rr;
		}
		double getArea();
		~Circle(){
		} ;
};
double Circle::getArea(){
	area=3.1416*r*r;
	return area;
}
class Rectangle:public Shape{
	private:
		double a,b;
	public:
		Rectangle(){
			a=0;b=0;
		}
		Rectangle(double aa,double bb){
			a=aa;b=bb;
		}
		double getArea();
};
double Rectangle::getArea(){
	area=a*b;
	return area;
}
class Triangle:public Shape{
	private:
		double a,b,c;
	public:
		Triangle(){
			a=0;b=0;c=0;
		}
		Triangle(double aa,double bb,double cc){
			a=aa;b=bb;c=cc;
		}
		double getArea();
}; 
double Triangle::getArea(){
	double p=(a+b+c)/2.0;
	area=sqrt(p*((p-a)+(p-b)+(p-c)));
	return area;
}
double TotalArea(vector<Shape*>& l){
	double sum=0;
	vector<Shape*>::iterator i;
	for(i=l.begin();i!=l.end();i++){
		sum+=(*i)->getArea();
		delete (*i);
	}
	return sum;
}
int main(){
	string s;
	vector<Shape*> l;
	while(cin>>s){
		if(s[0]=='c'){
			double r;
			cin>>r;
			Circle *x=new Circle(r);
			l.push_back(x);
		}else if(s[0]=='r'){
			double a,b;
			cin>>a>>b;
			Rectangle *x=new Rectangle(a,b);
			l.push_back(x);
		}else if(s[0]=='t'){
			double a,b,c;
			cin>>a>>b>>c;
			Triangle *x=new Triangle(a,b,c);
			l.push_back(x); 
		}
	}
	cout<<setiosflags(ios::fixed);//小数精度控制 
	cout<<setprecision(4)<<TotalArea(l)<<endl; 
}
