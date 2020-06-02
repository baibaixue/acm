#include<cstdio>
#include<iostream>
using namespace std;
class Cat{
	public:
		Cat(int a=1){//构造函数 
			n=a;
			numOfCats++;
		}
		static void getnumOfCats(){//静态函数 
			cout<<"The num of cats is "<<numOfCats<<endl;
		}
	private:
		int n;
		static int numOfCats;//静态成员 
};
int Cat::numOfCats=0;
int main(){
	Cat::getnumOfCats();
	Cat a;
	Cat::getnumOfCats();
	return 0; 
}
