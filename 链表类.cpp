/*����һ��Ӣ�ľ��ӣ�����������Ӣ�ĵ������η��������У�
����ÿ������һ�������ʾ��data�浥�ʳ��ִ���������ͳ�Ʋ�����
��Сд����Ƶ�ģ�������һ���ַ������������浱ǰ�ַ�����*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*�����*/ 
template <class T>
class Node{ 
	public:
		T data;//���� (�浱ǰָ����ַ����ĳ��ִ�����
		string str;//�浱ǰ�ַ��� 
		Node<T> *next;//��ǰ����ǰһ����� 
		Node<T> *pre;//��ǰ���ĺ�һ����� 
		Node();//���캯�� 
		Node(const T& data,const string& ss,Node<T> *next,Node<T> *pre);//���캯�� 
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
/*������*/
template <class T>
class LinkedList{
	public:
		LinkedList();//���캯��
		LinkedList(const LinkedList<T>& L);//���ƹ��캯��
		LinkedList<T>& operator=(const LinkedList<T>& L);//���ظ�ֵ�����
		int length()const;//����������
		bool empty()const;//�ж������Ƿ�Ϊ��
		void reset();//��ʼ���α�λ��
		void next();//ʹ�α��Ƶ���һ��λ��
		bool endOfList()const;//�α��Ƿ񵽴���β
		int currpos()const;//���ص�ǰ�α�λ��
		void insert_front(const string& ss,const T& item);//����ͷ������
		void insert_rear(const string& ss,const T& item);//����β������
		void insert_before(const string& ss,const T& item);//��ǰλ��ǰ������
		void insert_after(const string& ss,const T& item);//��ǰλ�ú������
		void delete_Front();//ɾ��ͷ���
		void delete_now();//ɾ����ǰ���
		T& Data();//���ص�ǰ����Ա���ݵ����� 
		string& GetStr();//�õ���ǰ������ַ��� 
		//int find(string& ss)const;
		void clear();//�������
		~LinkedList();//�������� 
	private:
		Node<T> *front;//��ͷָ��
		Node<T> *rear;//��βָ�� 
		Node<T> *currPtr;//��ǰ����λ�õ�ָ��
		int size;//����Ĵ�С
		int position;//��ǰԪ���ڱ��е�λ�����
}; 
template <class T>
LinkedList<T>::LinkedList(){//��ʼ������ֻ�б�ͷ��βָ�� 
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
	if(L.front==(*this).front){//��ֹ������������� 
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
int LinkedList<T>::length()const{//������ 
	return size;
}
template <class T>
bool LinkedList<T>::empty()const{//�ж������Ƿ�Ϊ�� 
	if(length()==0){
		return true;
	}else{
		return false;
	}
}
template <class T>
bool LinkedList<T>::endOfList()const{//�жϵ�ǰָ���Ƿ�ﵽ����β 
	if(position>=size){
		return true;
	}
	else{
		return false;
	}
}
template <class T>
int LinkedList<T>::currpos()const{//���ص�ǰָ������λ�� 
	return position;
}
template <class T>
T& LinkedList<T>::Data(){//��ǰֵ 
	return currPtr->data; 
}
template <class T>
string& LinkedList<T>::GetStr(){//�õ���ǰ�ַ��� 
	return currPtr->str;
}
//template <class T>
//int LinkedList<T>::find(string& ss)const{//�ҵ���Ӧ�ַ��� 
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
void LinkedList<T>::clear(){//������� 
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
void LinkedList<T>::reset(){//�����α� 
	currPtr=front->next;
	position=0;
}
template <class T>
void LinkedList<T>::next(){//�α����һλ 
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
LinkedList<T>::~LinkedList(){//�������� 
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
/*��ȡһ���ַ����������ʷ������,�����ִ�Сд��data���浥�ʳ��ִ���*/ 
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
/*LinkedListģ�����*/ 
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
/*����������
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
��������
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
t 2 ����дTת��ΪСд�� 
th 2  (�����Ŷ����� T-th�����Ϊ t 2 th 2) 
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
