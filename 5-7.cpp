#include<cstdio>
#include<iostream>
using namespace std;
class Cat{
	public:
		Cat(int a=1){//���캯�� 
			n=a;
			numOfCats++;
		}
		static void getnumOfCats(){//��̬���� 
			cout<<"The num of cats is "<<numOfCats<<endl;
		}
	private:
		int n;
		static int numOfCats;//��̬��Ա 
};
int Cat::numOfCats=0;
int main(){
	Cat::getnumOfCats();
	Cat a;
	Cat::getnumOfCats();
	return 0; 
}
