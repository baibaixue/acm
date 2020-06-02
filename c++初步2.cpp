#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
	string line;//定义字符串 
	while(getline(cin,line)){//输入字符串 
		int sum=0,x;
		stringstream ss(line);//定义字符串流ss 
		while(ss>>x){//将ss赋值给x 
			sum+=x;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
