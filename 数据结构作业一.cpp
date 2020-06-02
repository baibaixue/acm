//���ݽṹ��ҵ ��ѭ����������ʵ��Լɪ������
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
		Node<T> *next;//��ǰ����ǰһ����� 
		//Node<T> *pre;//��ǰ���ĺ�һ����� 
		Node();//���캯�� 
		Node(const T& data,Node<T> *next);//���캯�� 
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
/*ѭ��������*/
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
		void last();//ʹ�α��Ƶ���һ��λ�� 
		bool endOfList()const;//�α��Ƿ񵽴���β
		bool headOfList()const;//�α��Ƿ���ͷ�ڵ� 
		void insert_front(const T& item);//����ͷ������
		void insert_rear(const T& item);//����β������
		void insert_before(const T& item);//��ǰλ��ǰ������
		void insert_after(const T& item);//��ǰλ�ú������
		void delete_Front();//ɾ��ͷ���
		void delete_now();//ɾ����ǰ���
		T& Data();//���ص�ǰ����Ա���ݵ����� 
		void clear();//�������
		~LinkedList();//�������� 
	private:
		Node<T> *front;//��ͷָ��
		Node<T> *rear;//��βָ�� 
		Node<T> *currPtr;//��ǰ����λ�õ�ָ��
		int size;//����Ĵ�С
}; 
template <class T>
LinkedList<T>::LinkedList(){//��ʼ������ֻ�б�ͷ��βָ�� 
	front=new Node<T>;
	rear=new Node<T>;
	front->next=rear;
	rear->next=front;//  rear -> next = NULL��ѭ������ 
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
	if(L.front==(*this).front){//��ֹ������������� 
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
T& LinkedList<T>::Data(){//��ǰֵ 
	return currPtr->data; 
}

template <class T>
void LinkedList<T>::clear(){//������� 
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
void LinkedList<T>::reset(){//�����α� 
	currPtr=front;
}
template <class T>
void LinkedList<T>::next(){//�α����һλ 
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
LinkedList<T>::~LinkedList(){//�������� 
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
	while (scanf("%d%d",&m,&n)!=EOF)//n������ �� m��ʼ���� 
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











