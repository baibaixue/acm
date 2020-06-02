#include<iostream>
using namespace std;

struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){/*this->x=x;this->y=y;*/	}//this为指向当前对象的指针 
}; 
point operator + (const point&A,const point&B){//定义+操作符在a+b中调用 //定义结构体的加法、 
	return point(A.x+B.x,A.y+B.y);
}
ostream& operator<<(ostream &out,const point& p){//定义<<操作符在cout << a+b中调用 //定义结构体流的输出方式 
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}
int main(){
	point a,b(1,2);
	a.x=3;
	cout<<a+b<<"\n";
	return 0;
}
