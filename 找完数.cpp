#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num;
bool is_wan(int a){
	int sum=0;
	for(int i=1;i<a;i++){
		if(a%i==0){
			sum+=i;
		}
	}
	if(a==sum){
		return true;
	}else{
		return false;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		num.push_back(n);
	}
	vector<int>::iterator p;
	p=find_if(num.begin(),num.end(),is_wan);
	int x=count_if(num.begin(),num.end(),is_wan);
	cout<<x<<endl;
	if(p==num.end()){
		cout<<"none"<<endl;
	}else{
		cout<<p-num.begin()+1<<" "<<*p<<endl; 
	}
}
