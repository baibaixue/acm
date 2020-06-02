#include<iostream>//输入输出流 
#include<algorithm> //常用算法库，如min 
using namespace std;//上两种函数储存在std空间中，该句把函数导入默认空间供程序使用 
const int maxn=100+10;
int A[maxn];
void swap2(int& a,int& b){
	int t=a;a=b;b=t;
}
int main(){
	int a,b;
	while(/*std::*/cin>>a>>b){//输入流，依次输入a,b的值 
		/*std::*/cout<</*std::*/min(a,b)<<"\n";//输出流，输出a,b中的最小值和回车 
		swap2(a,b);
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
} 
