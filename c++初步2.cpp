#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
	string line;//�����ַ��� 
	while(getline(cin,line)){//�����ַ��� 
		int sum=0,x;
		stringstream ss(line);//�����ַ�����ss 
		while(ss>>x){//��ss��ֵ��x 
			sum+=x;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
