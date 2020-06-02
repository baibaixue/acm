//数据结构作业 用循环单向链表实现约瑟夫问题
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*结点类*/ 
template <class T>
class Node{ 
	public:
		T data;//数据 (存当前指向的字符串的出现次数）
		Node<T> *next;//当前结点的前一个结点 
		//Node<T> *pre;//当前结点的后一个结点 
		Node();//构造函数 
		Node(const T& data,Node<T> *next);//构造函数 
};
template <class T>
Node<T>::Node(){
	data=0;
	next=NULL;
}
template <class T> 
Node<T>::Node(const T& data,Node<T> *next){
	data=data;
	next=next;
} 
/*循环链表类*/
template <class T>
class LinkedList{
	public:
		LinkedList();//构造函数
		LinkedList(const LinkedList<T>& L);//复制构造函数
		LinkedList<T>& operator=(const LinkedList<T>& L);//重载赋值运算符
		int length()const;//返回链表长度
		bool empty()const;//判断链表是否为空
		void reset();//初始化游标位置
		void next();//使游标移到下一个位置
		void last();//使游标移到上一个位置 
		bool endOfList()const;//游标是否到达链尾
		bool headOfList()const;//游标是否在头节点 
		void insert_front(const T& item);//链表头插入结点
		void insert_rear(const T& item);//链表尾插入结点
		void insert_before(const T& item);//当前位置前插入结点
		void insert_after(const T& item);//当前位置后插入结点
		void delete_Front();//删除头结点
		void delete_now();//删除当前结点
		T& Data();//返回当前结点成员数据的引用 
		void clear();//清空链表
		~LinkedList();//析构函数 
	private:
		Node<T> *front;//表头指针
		Node<T> *rear;//表尾指针 
		Node<T> *currPtr;//表当前遍历位置的指针
		int size;//链表的大小
}; 
template <class T>
LinkedList<T>::LinkedList(){//初始化链表只有表头表尾指针 
	front=new Node<T>;
	rear=new Node<T>;
	front->next=rear;
	rear->next=front;//  rear -> next = NULL非循环链表 
	currPtr=new Node<T>;
	reset();
	size=0;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L){
	front=new Node<T>;
	rear=new Node<T>;
	front->next=rear;
	rear->next=front;
	currPtr=new Node<T>;
	reset();
	size=0;
	Node<T> *temp=L.front->next;
	Node<T> *now=front;
	while(temp->next!=L.rear){
		Node<T> *p=new Node<T>;
		p->data=temp->data;
		p->next=now->next;
		now->next=p;
		size++;
		temp=temp->next;
		now=now->next;
	}
	delete temp;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L){
	if(L.front==(*this).front){//防止自身与自身相等 
		return *this;
	}
	else{
		clear();
		Node<T> *temp=L.front->next;
		Node<T> *now=front;
		while(temp->next!=L.rear){
			Node<T> *p=new Node<T>;
			p->data=temp->data;
			p->next=now->next;
			now->next=p;
			size++;
			temp=temp->next;
			now=now->next;
		}
		delete temp;
	}
}
template <class T>
int LinkedList<T>::length()const{//链表长度 
	return size;
}
template <class T>
bool LinkedList<T>::empty()const{//判断链表是否为空 
	if(length()==0){
		return true;
	}else{
		return false;
	}
}
template <class T>
bool LinkedList<T>::endOfList()const{//判断当前指针是否达到链表尾 
	if(currPtr==rear){
		return true;
	}
	else{
		return false;
	}
}
template <class T>
bool LinkedList<T>::headOfList()const{
	if(currPtr==front){
		return true;
	}else {
		return false;
	}
}
template <class T>
T& LinkedList<T>::Data(){//当前值 
	return currPtr->data; 
}

template <class T>
void LinkedList<T>::clear(){//清空链表 
	if(empty()){
		return ;
	}
	reset();
	Node<T> *p=front->next;
	while(p!=rear){
		Node<T> *temp=p;
		p=p->next;
		delete temp;
	}
	front->next=rear;
	rear->next=front;
	size=0;
} 
template <class T>
void LinkedList<T>::reset(){//重置游标 
	currPtr=front;
}
template <class T>
void LinkedList<T>::next(){//游标后移一位 
	currPtr=currPtr->next; 
} 
template<class T>
void LinkedList<T>::last(){
	Node<T> *p=front->next;
	while(p->next!=currPtr){
		p=p->next; 
	}
	currPtr=p;
} 
template <class T>
void LinkedList<T>::insert_front(const T& item){
	Node<T> *p=new Node<T>;
	p->data=item;
	p->next=front->next;
	front->next=p;
	size++;
} 
template <class T>
void LinkedList<T>::insert_rear(const T& item){
	Node<T> *p=new Node<T>;
	Node<T> *temp=front->next;
	while(temp->next!=rear){
		temp=temp->next;
	}
	p->data=item;
	p->next=rear;
	temp->next=p;
	size++;
} 
template <class T>
void LinkedList<T>::insert_after(const T& item){
	if(endOfList())
	{
		next();
	}
	Node<T> *p=new Node<T>;
	p->data=item;
	p->next=currPtr->next;
	currPtr->next=p;
	size++;
} 
template <class T>
void LinkedList<T>::insert_before(const T& item){
	if(headOfList())
	{
		next();
	}
	last();
	insert_after(item);
	next();next();
	size++;
} 
template <class T>
void LinkedList<T>::delete_Front(){
	if(empty()){
		cout<<"empty!"<<endl;
		return ;
	}else{
		reset();
		Node<T> *temp=front->next;
		front->next=temp->next;
		size--;
		delete temp;
		return ;
	}
}

template <class T>
void LinkedList<T>::delete_now(){
	if(empty()){
		cout<<"empty!"<<endl;
	}
	else{
		last();
		Node<T> *temp=currPtr->next;
		currPtr->next=temp->next;
		delete temp;
		size--;
	}
}
template <class T>
LinkedList<T>::~LinkedList(){//析构函数 
	if(empty()){
		delete front;
		delete rear;
		return ;
	}else{
		while(front->next!=rear){
			Node<T> *temp=front;
			front=front->next;
			delete temp;
		}
		delete rear;
		return ;
	}
} 

int main()
{
	int m,n;
	LinkedList<int> L;
	int code[1000];
	while (scanf("%d%d",&m,&n)!=EOF)//n总人数 ， m初始报数 
	{
		for (int i=1 ;i<=n;i++){
			scanf("%d",&code[i]);
			L.insert_after(i);
			L.next();
		} 
		L.reset() ; 
		while (!L.empty()){
			int count = m%L.length();
			for(int i=0;i<count;i++){
				L.next();
				while(L.endOfList()||L.headOfList()) L.next() ;
			}
			while(L.endOfList()||L.headOfList()) L.next() ; 
			m=code[L.Data()]; 
			printf("%d ",L.Data());
			L.delete_now();
			while(!L.empty()&&(L.endOfList()||L.headOfList())) L.last() ;
		}
		printf("\n");
	}
 } 











