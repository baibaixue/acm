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
		String();//构造函数 
		void Reset();//当前标记位置重置 
		String(String& _string);//复制构造函数 
		String(const char* _string);
		String Insert_string(unsigned int pos,String& _ptr);//在pos位置之后插入_ptr子串 
		String Del_string(String& _ptr);//删去主串中第一个出现的子串_ptr 
		int Index(String& _ptr);//返回子串_ptr的下标如果找不到返回-1 
		bool MoveTo(unsigned int pos);//将标记位置移至pos位置 
		bool IsEmpty();//串是否为空 
		bool EndOfString();//标记是否到达串尾 
		int Length();//返回串的长度 
		void Next();//当前标记后移 
		char Data();//返回当前数据 
		void Clear();//清空串 
		~String();	//析构 
	private:
		node* head;
		node* tail;
		node* cur;
		int len;
};

