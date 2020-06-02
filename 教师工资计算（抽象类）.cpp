#include<iostream>
#include<cmath>
using namespace std;
class Point
{
	double X,Y;
public:
	Point(double x,double y){X=x;Y=y;}
	friend class Distance;
};
class Distance
{
public:
	double Dis(Point& p1,Point& p2);
};
double Distance::Dis(Point& p1,Point& p2)
{
	double t;
	t=sqrt((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y));
	return t;
}
int main(){
	Point p(10,10),q(20,20);
	Distance d;
	cout<<d.Dis(p,q)<<endl;
}

