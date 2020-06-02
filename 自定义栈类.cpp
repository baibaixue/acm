/*�Զ���ջ��ʵ�������������������㣨�����ţ�*/ 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cassert>
using namespace std;
template<class T>
/*ջ�ඨ��,�Ƚ����*/ 
class Stack{
	public:
		Stack(){//���캯��
			list=NULL;
			top=-1;
		}
		Stack(const Stack<T>& s){//���ƹ��캯�� 
			list=new T[s.top+1];
			for(int i=0;i<=s.top;i++){
				list[i]=s.list[i];
			}
			//list[s.top+1]='\0';
			top=s.top;
		}
		T pop();//��ջ��Ԫ�ص��� 
		void push(const T item);//��һ��Ԫ��ѹ��ջ 
		void clear();//���ջ 
		T peek()const;//����ջ��Ԫ��
		bool empty()const;//�ж�ջ�Ƿ�Ϊ�� 
		unsigned int size()const;//ջ��Ԫ�ظ��� 
		~Stack();//�������� 
	private:
		T* list;
		int top;
};
template<class T>
T Stack<T>::pop(){//����ջ��Ԫ�� 
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
void Stack<T>::push(const T item){//��Ԫ��ѹ��ջ 
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
T Stack<T>::peek()const{//����ջ��Ԫ�� 
	assert(!empty());
	return list[top];
}
template<class T>
void Stack<T>::clear(){//���ջ 
	if(!empty()){
		delete []list;
		list=NULL; 
		top=-1;
	}
}
template<class T>
bool Stack<T>::empty()const{//�ж�ջ�Ƿ�Ϊ�� 
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
/*��������������������������*/
class calculator{
	public:
		void run();//���м����� 
		void clear();//��ռ����� 
	private:
		Stack<int> s;//������ջ 
		Stack<char> f;//������ջ 
		bool getTwonums(int& num1,int& num2);//����������������ջ
		bool getoperator(char& op);//��һ�����������ջ 
		void enter(int num);//��������ѹ��ջ 
		void compute();//�������� 
}; 
void  calculator::enter(int num){//��������ѹ��ջ
	s.push(num);
}
bool calculator::getTwonums(int& num1,int& num2){//����������������ջ
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
bool calculator::getoperator(char& op){//��һ�����������ջ 
	if(!f.empty()){
		op=f.pop();
	}else{
		cout<<"Missing operator."<<endl;
	}
}
void calculator::compute(){//�������� 
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
void calculator::clear(){//��ռ����� 
	s.clear();
	f.clear();
} 
void calculator::run(){//���м����� 
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
/*����*/ 
int main(){
	/*ջ����*/ 
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
/*-------������-------
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
File: C:\Users\Admin\Documents\�Զ���ջ��.cpp, Line 67

Expression: !empty()
*/
