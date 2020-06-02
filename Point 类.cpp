#include<cstdio>
#include<iostream>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
template <class T>
class Point{
	template<class A>
	friend ostream& operator<<(ostream& out,const Point<A>& p);
	template<class A>
	friend istream& operator>>(istream& in,Point<A>& p);
	public:
		Point(){
			x=0;
			y=0;
		}
		Point(T a,T b){
			x=a;
			y=b;
		}
		double get_distance(const Point<T>& rhs)const;
	private:
		T x,y;	
};
template <class T>
double Point<T>::get_distance(const Point<T>& rhs)const{
	return sqrt((x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y));
}
template <class T>
double get_area(const Point<T>& lhs,const Point<T>& mid,const Point<T>& rhs){
	double s;
	double a=1.0*lhs.get_distance(mid);
	double b=1.0*mid.get_distance(rhs);
	double c=1.0*rhs.get_distance(lhs);
	s=(a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

template <class A>
ostream& operator<<(ostream& out,const Point<A>& p){
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}
template <class A> 
istream& operator>>(istream& in,Point<A>& p){
	char c;
	in>>p.x>>c>>p.y;
	return in; 
}

int main(){
	Point<int> a(1,1);
	Point<int> b(1,2);
	Point<int> c(2,3);
	cout<<a<<b<<c<<endl;
	cout<<get_area(a,b,c)<<endl;
	cout<<a.get_distance(b)<<endl; 
	Point<double> p(1.2,3.4);
	Point<double> q(4.5,3.5);
	Point<double> r(2.2,3.5);
	cout<<a<<b<<c<<endl;
	cout<<get_area(p,q,r)<<endl; 
	 
}
