#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;


class node
{
	public:
		node* next;
		char c;
		node();
		node(node *_node,char _c);
		~node();
};

class String
{
	public:	
		String();//���캯�� 
		void Reset();//��ǰ���λ������ 
		String(String& _string);//���ƹ��캯�� 
		String(const char* _string);
		String Insert_string(unsigned int pos,String& _ptr);//��posλ��֮�����_ptr�Ӵ� 
		String Del_string(String& _ptr);//ɾȥ�����е�һ�����ֵ��Ӵ�_ptr 
		int Index(String& _ptr);//�����Ӵ�_ptr���±�����Ҳ�������-1 
		bool MoveTo(unsigned int pos);//�����λ������posλ�� 
		bool IsEmpty();//���Ƿ�Ϊ�� 
		bool EndOfString();//����Ƿ񵽴ﴮβ 
		int Length();//���ش��ĳ��� 
		void Next();//��ǰ��Ǻ��� 
		char Data();//���ص�ǰ���� 
		void Clear();//��մ� 
		~String();	//���� 
	private:
		node* head;
		node* tail;
		node* cur;
		int len;
};

