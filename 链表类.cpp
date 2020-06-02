/*输入一个英文句子，将句中所有英文单词依次放在链表中，
并将每个单词一行输出显示，data存单词出现次数，单词统计不考虑
大小写（设计的模板中添加一个字符串变量用来存当前字符串）*/
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
		string str;//存当前字符串 
		Node<T> *next;//当前结点的前一个结点 
		Node<T> *pre;//当前结点的后一个结点 
		Node();//构造函数 
		Node(const T& data,const string& ss,Node<T> *next,Node<T> *pre);//构造函数 
};
template <class T>
Node<T>::Node(){
	data=0;
	str.clear();
	pre=NULL;
	next=NULL;
}
template <class T> 
Node<T>::Node(const T& data,const string& ss,Node<T> *next,Node<T> *pre){
	data=data;
	str=ss;
	pre=pre;
	next=next;
} 
/*链表类*/
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
		bool endOfList()const;//游标是否到达链尾
		int currpos()const;//返回当前游标位置
		void insert_front(const string& ss,const T& item);//链表头插入结点
		void insert_rear(const string& ss,const T& item);//链表尾插入结点
		void insert_before(const string& ss,const T& item);//当前位置前插入结点
		void insert_after(const string& ss,const T& item);//当前位置后插入结点
		void delete_Front();//删除头结点
		void delete_now();//删除当前结点
		T& Data();//返回当前结点成员数据的引用 
		string& GetStr();//得到当前储存的字符串 
		//int find(string& ss)const;
		void clear();//清空链表
		~LinkedList();//析构函数 
	private:
		Node<T> *front;//表头指针
		Node<T> *rear;//表尾指针 
		Node<T> *currPtr;//表当前遍历位置的指针
		int size;//链表的大小
		int position;//当前元素在表中的位置序号
}; 
template <class T>
LinkedList<T>::LinkedList(){//初始化链表只有表头表尾指针 
	front=new Node<T>;
	rear=new Node<T>;
	front->next=rear;
	front->pre=NULL;
	rear->next=NULL;
	rear->pre=front;
	currPtr=new Node<T>;
	currPtr->pre=NULL;
	currPtr->next=front;
	size=0;
	position=0;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L){
	front=new Node<T>;
	rear=new Node<T>;
	front->pre=NULL;
	front->next=rear;
	rear->pre=front;
	rear->next=NULL;
	size=0;
	Node<T> *temp=L.front;
	while(temp->next!=L.rear){
		Node<T> *p=new Node<T>;
		p->data=temp->next->data;
		p->str=temp->next->str;
		p->pre=rear->pre;
		rear->pre->next=p;
		rear->pre=p;
		p->next=rear;
		size++;
		temp=temp->next;
	}
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L){
	if(L.front==(*this).front){//防止自身与自身相等 
		return *this;
	}
	else{
		clear();
		Node<T> *temp=L.front;
		while(temp->next!=L.rear){
			Node<T> *p=new Node<T>;
			p->data=temp->next->data;
			p->str=temp->next->str;
			p->pre=rear->pre;
			rear->pre->next=p;
			rear->pre=p;
			p->next=rear;
			size++;
			temp=temp->next;
		}
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
	if(position>=size){
		return true;
	}
	else{
		return false;
	}
}
template <class T>
int LinkedList<T>::currpos()const{//返回当前指针所在位置 
	return position;
}
template <class T>
T& LinkedList<T>::Data(){//当前值 
	return currPtr->data; 
}
template <class T>
string& LinkedList<T>::GetStr(){//得到当前字符串 
	return currPtr->str;
}
//template <class T>
//int LinkedList<T>::find(string& ss)const{//找到对应字符串 
//	reset();
//	while(!endOfList()){
//		if(ss==GetStr()){
//			return position;
//		}else{
//			next();
//		}
//	}
//	return -1;
//}
template <class T>
void LinkedList<T>::clear(){//清空链表 
	if(empty()){
		return ;
	}
	Node<T> *p=front->next;
	while(p!=rear){
		Node<T> *temp=p;
		p=p->next;
		delete temp;
	}
	front->next=rear;
	front->pre=NULL;
	rear->pre=front;
	rear->next=NULL;
	reset();
	size=0;
} 
template <class T>
void LinkedList<T>::reset(){//重置游标 
	currPtr=front->next;
	position=0;
}
template <class T>
void LinkedList<T>::next(){//游标后移一位 
	position++;
	currPtr=currPtr->next; 
} 
template <class T>
void LinkedList<T>::insert_front(const string& ss,const T& item){
	Node<T> *temp=new Node<T>;
	temp->data=item;
	temp->str=ss;
	temp->next=front->next;
	temp->pre=front;
	front->next->pre=temp;
	front->next=temp;
	size++;
	reset();
} 
template <class T>
void LinkedList<T>::insert_rear(const string& ss,const T& item){
	Node<T> *temp=new Node<T>;
	temp->data=item;
	temp->str=ss;
	temp->next=rear;
	temp->pre=rear->pre;
	rear->pre->next=temp;
	rear->pre=temp;
	size++;
	reset();
} 
template <class T>
void LinkedList<T>::insert_after(const string& ss,const T& item){
	Node<T> *temp=new Node<T>;
	temp->data=item;
	temp->str=ss;
	temp->next=currPtr->next;
	temp->pre=currPtr;
	currPtr->next->pre=temp;
	currPtr->next=temp;
	size++;
} 
template <class T>
void LinkedList<T>::insert_before(const string& ss,const T& item){
	Node<T> *temp=new Node<T>;
	temp->data=item;
	temp->str=ss;
	temp->next=currPtr;
	temp->pre=currPtr->pre;
	currPtr->pre->next=temp;
	currPtr->pre=temp;
	size++;
	position++;
} 
template <class T>
void LinkedList<T>::delete_Front(){
	if(empty()){
		cout<<"empty!"<<endl;
		return ;
	}else{
		Node<T> *temp=front->next;
		front->next=temp->next;
		temp->next->pre=front;
		size--;
		delete temp;
		reset();
		return ;
	}
}

template <class T>
void LinkedList<T>::delete_now(){
	if(empty()){
		cout<<"empty!"<<endl;
	}
	else{
		currPtr=currPtr->next;
		Node<T> *temp=currPtr->pre;
		temp->pre->next=currPtr;
		currPtr->pre=temp->pre;
		delete temp;
		size--;
	}
}
template <class T>
LinkedList<T>::~LinkedList(){//析构函数 
	if(empty()){
		delete front;
		delete rear;
		front=NULL;
		rear=NULL;
		return ;
	}else{
		while(front->next!=NULL){
			Node<T> *temp=front;
			front=front->next;
			delete temp;
		}
		delete front;
		front=NULL;
		return ;
	}
}
int main(){
/*读取一行字符串，将单词分离出来,不区分大小写，data储存单词出现次数*/ 
	LinkedList<int> words;
	string str;
	getline(cin,str);
	string ptr;
	ptr.clear(); 
	for(int i=0;i<str.length();i++){
		if(str[i]<='z'&&str[i]>='a'){
			ptr+=str[i];
		}else if(str[i]<='Z'&&str[i]>='A'){
			ptr+=str[i]-'A'+'a';
		}else if(!ptr.empty()){
			words.reset();
			while(!words.endOfList()){
				if(words.GetStr()==ptr){
					words.Data()++;
					break;
				}
				words.next();
			}
			if(words.currpos()==words.length()){
				words.insert_rear(ptr,1); 
			}
			ptr.clear();
		}
	}
	words.reset();
	while(!words.endOfList()){
		cout<<words.GetStr()<<" "<<words.Data()<<endl;
		words.next();
	}
/*LinkedList模板测试*/ 
//	LinkedList<int>l;
//	l.insert_front("2",2);
//	l.insert_rear("5",5);
//	l.insert_rear("7",7);
//	l.insert_front("8",8);
//	l.reset();
//	while(!l.endOfList()){
//		printf("%d\n",l.Data());
//		if(l.Data()==2){
//			l.insert_after("3",3);
//		}
//		if(l.Data()==5){
//			l.insert_before("10",10); 
//		}
//		if(l.Data()==7){
//			l.delete_now();
//		} 
//		l.next();
//	}
//	printf("\n");
//	cout<<l.currpos()<<endl;
//	cout<<l.empty()<<endl;
//	cout<<l.endOfList()<<endl;
//	cout<<l.length()<<endl;
//	printf("\n");
//	l.delete_Front();
//	l.reset();
//	while(!l.endOfList()){
//		printf("%d\n",l.Data());
//		l.next();
//	}
//	printf("\n");
//	LinkedList<int>l2=l;
//	l2.reset();
//	while(!l2.endOfList()){
//		printf("%d\n",l2.Data());
//		l2.next();
//	}
//	printf("\n");
//	l2.insert_rear("100",100);
//	l2.reset();
//	while(!l2.endOfList()){
//		printf("%d\n",l2.Data());
//		l2.next();
//	}
//	printf("\n");
//	l2=l2;
//	l2.reset();
//	while(!l2.endOfList()){
//		printf("%d\n",l2.Data());
//		l2.next();
//	}
}
/*测试样例：
The doggie found a bone in an ancient maze,
which fascinated him a lot.However, when he
picked it up,the maze began to shake,and the
doggie could feel the ground sinking.He realized
that the bone was a trap,and he tried desperately
to get out of this maze.The maze was a rectangle
with sizes N by M. There was a door in the maze.
At the beginning,the door was closed and it would
open at the T-th second for a short period of time
(less than 1 second). Therefore the doggie had to
arrive at the door on exactly the T-th second. In
every second, he could move one block to one of 
the upper, lower, left and right neighboring blocks. 
Once he entered a block, the ground of this block would
start to sink and disappear in the next second. He could
not stay at one block for more than one second, nor could
he move into a visited block.Can the poor doggie survive?
Please help him. 
输出结果：
the 17
doggie 4
found 1
a 8
bone 2
in 4
an 1
ancient 1
maze 5
which 1
fascinated 1
him 2
lot 1
however 1
when 1
he 7
picked 1
it 2
up 1
began 1
to 5
shake 1
and 5
could 4
feel 1
ground 2
sinking 1
realized 1
that 1
was 4
trap 1
tried 1
desperately 1
get 1
out 1
of 4
this 2
rectangle 1
with 1
sizes 1
n 1
by 1
m 1
there 1
door 3
at 4
beginning 1
closed 1
would 2
open 1
t 2 （大写T转换为小写） 
th 2  (标点符号都不记 T-th处理后为 t 2 th 2) 
second 6
for 2
short 1
period 1
time 1
less 1
than 2
therefore 1
had 1
arrive 1
on 1
exactly 1
every 1
move 2
one 4
block 5
upper 1
lower 1
left 1
right 1
neighboring 1
blocks 1
once 1
entered 1
start 1
sink 1
disappear 1
next 1
not 1
stay 1
more 1
nor 1
into 1
visited 1
can 1
poor 1
survive 1
please 1
help 1
*/ 
