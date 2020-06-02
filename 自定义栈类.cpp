/*自定义栈来实现正整数的四则混合运算（无括号）*/ 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cassert>
using namespace std;
template<class T>
/*栈类定义,先进后出*/ 
class Stack{
	public:
		Stack(){//构造函数
			list=NULL;
			top=-1;
		}
		Stack(const Stack<T>& s){//复制构造函数 
			list=new T[s.top+1];
			for(int i=0;i<=s.top;i++){
				list[i]=s.list[i];
			}
			//list[s.top+1]='\0';
			top=s.top;
		}
		T pop();//将栈顶元素弹出 
		void push(const T item);//将一个元素压入栈 
		void clear();//清空栈 
		T peek()const;//访问栈顶元素
		bool empty()const;//判断栈是否为空 
		unsigned int size()const;//栈中元素个数 
		~Stack();//析构函数 
	private:
		T* list;
		int top;
};
template<class T>
T Stack<T>::pop(){//弹出栈顶元素 
		assert(!empty());
		Stack<T> temp(*this);
		delete []list;
		list=new T[top];
		for(int i=0;i<top;i++){
			list[i]=temp.list[i];
		}
		//list[top]='\0';
		top--;
		return temp.list[top+1];
}
template<class T>
void Stack<T>::push(const T item){//将元素压入栈 
	if(!empty()){
		Stack<T> temp(*this);
		delete []list;
		list=new T[temp.top+2];
		for(int i=0;i<=temp.top;i++){
			list[i]=temp.list[i];
		}
		list[++top]=item;
		//list[top+1]='\0';
	}else{
		list=new T[1];
		list[++top]=item;
		//list[top+1]='\0';
	}
}
template<class T>
T Stack<T>::peek()const{//访问栈顶元素 
	assert(!empty());
	return list[top];
}
template<class T>
void Stack<T>::clear(){//清空栈 
	if(!empty()){
		delete []list;
		list=NULL; 
		top=-1;
	}
}
template<class T>
bool Stack<T>::empty()const{//判断栈是否为空 
	if(top==-1){
		return true;
	}
	return false;
}
template<class T>
unsigned int Stack<T>::size()const{
	return top+1;
}
template<class T>
Stack<T>::~Stack(){
	if(!empty()){
		delete []list;
		top=-1;
	}
}
/*计算器计算正整数的四则运算*/
class calculator{
	public:
		void run();//运行计算器 
		void clear();//清空计算器 
	private:
		Stack<int> s;//操作数栈 
		Stack<char> f;//操作符栈 
		bool getTwonums(int& num1,int& num2);//将两个操作数弹出栈
		bool getoperator(char& op);//将一个运算符弹出栈 
		void enter(int num);//将运算结果压入栈 
		void compute();//进行运算 
}; 
void  calculator::enter(int num){//将运算结果压入栈
	s.push(num);
}
bool calculator::getTwonums(int& num1,int& num2){//将两个操作数弹出栈
	if(!s.empty()){
		num1=s.pop();
		if(!s.empty()){
			num2=s.pop();
			return true;
		}
		else{
			cout<<"Missing operand."<<endl;
			return false;
		}
	}else{
		cout<<"Missing operand."<<endl;
		return false;
	}
}
bool calculator::getoperator(char& op){//将一个运算符弹出栈 
	if(!f.empty()){
		op=f.pop();
	}else{
		cout<<"Missing operator."<<endl;
	}
}
void calculator::compute(){//进行运算 
	int a,b;
	char op;
	if(getTwonums(a,b)&&getoperator(op)){
		if(op=='+'){
			enter(a+b);
		}
		if(op=='-'){
			enter(b-a);
		}if(op=='*'){
			enter(a*b);
		}if(op=='/'){
			if(a!=0){
				enter(b/a);
			}
			else{
				cout<<"error."<<b<<" can't be divide by 0."<<endl;
			}
		}
	}
	return ;
}
void calculator::clear(){//清空计算器 
	s.clear();
	f.clear();
} 
void calculator::run(){//运行计算器 
	string S;
	cin>>S;
	int num=0;
	for(int i=0;i<S.size();i++){
		if(S[i]<='9'&&S[i]>='0'){
			num=num*10+S[i]-'0';
			if(i!=S.size()&&!(S[i+1]<='9'&&S[i+1]>='0')){
				enter(num);
				num=0;
			}
		}
		if(S[i]=='+'||S[i]=='-'){
			if(!f.empty()){
				compute();
			}
			f.push(S[i]);
		}else if(S[i]=='*'||S[i]=='/'){
			if(!f.empty()&&!(f.peek()=='+'||f.peek()=='-')){
				compute();
			}
			f.push(S[i]);
		}
	}
	while(!f.empty()){
		compute();
	}
	cout<<"="<<s.peek()<<endl;
}
/*测试*/ 
int main(){
	/*栈测试*/ 
//	Stack<int> a;
//	a.push(2);
//	a.push(3);
//	a.push(4);
//	a.pop();
//	a.pop();
//	a.pop();
//	cout<<a.size()<<endl;
	int n=5; 
	calculator a;
	while(n--){
		a.run();
		a.clear();
	} 
}
/*-------输出结果-------
2+3*5
=17
3-2+5*2
=11
4/2+3*2
=8
6/3+2+2+2+1+4+5-6-7-8+9*10+3-9+10*10
=181
1/0
error.1 can't be divide by 0.
Assertion failed!

Program: C:\Users\Admin\Documents\.exe
File: C:\Users\Admin\Documents\自定义栈类.cpp, Line 67

Expression: !empty()
*/
