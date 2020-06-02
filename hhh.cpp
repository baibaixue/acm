#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define len (int)strlen(s)
#define len1 (int)strlen(s1)
#define len2 (int)strlen(s2)
#define INF 0x3f3f3f
#define ll long long
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

template<class T>
class Complex{
	template <class U>
    friend ostream& operator<<(ostream& out,const Complex<U>& rhs);
public:
    Complex(){
        rea=0;ima=0;
    }
    Complex(T x,T y){
        rea=x;ima=y;
    }
    Complex(T x){
        rea=x;ima=0;
    }
    Complex& operator= (const Complex rhs);
    operator T() {
        return (T)rea;
    }
    Complex operator+(const Complex& rhs)const;
private:
    T rea,ima;
};

template<class U>
ostream& operator<<(ostream& out,const Complex<U>& rhs){
    out<<rhs.rea<<"+"<<rhs.ima<<"i";
    return out;
}

template<class T>
Complex<T>& Complex<T>:: operator=(const Complex<T> rhs){
    rea=rhs.rea;ima=rhs.ima;
    return *this;
}

template<class T>
Complex<T> Complex<T>:: operator+(const Complex<T>& rhs)const{
    Complex tmp;
    tmp.rea=rea+rhs.rea;
    tmp.ima=ima+rhs.ima;
    return tmp;
}

int main(){
    Complex<int>c1(2,3),c2;
    c2=c1;
    printf("%lf\n",(double)c2);
    Complex<double>c3;
    c3=(double)c1+c2;
    printf("%d\n",(int)c3);
    cout<<c3<<endl;
}
