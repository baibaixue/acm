#include <iostream>
using namespace std;
class Base {
public:
Base(int i, int j){ a  =  i; b  =  j; }
	void  Move(int  x, int  y){ a +=  x; b += y; }
	virtual void Show( )
	{ cout << "("<< a << "," << b << ")" << endl; }
private:
	int	a, b;
};
class Derived: public Base {
public:
	Derived( int i, int j, int k, int l ): Base( i, j ), x(k), y(l) { }
	void  Show( ) { cout << x << "," << y << endl; }
	void  func( ){ 
		Base::Show( ); 
	}
private:
	int	x, y;
};
int  main( )
{
	Base  b( 1, 2 );
	Base  *pB = &b;
	pB->Show( );
	Derived d( 3, 4, 5, 6 );
	Derived *pD = &d;
	pB = pD;
	pB->Show( );
	pD->Show( );
	pD->func( );
}


