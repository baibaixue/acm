/*�Զ���set��,set�ص㣺ÿ��Ԫ�ض�����ͬ��Ԫ�ذ���һ��˳������*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert> 
#include<iterator>
using namespace std;
template <class T>
class Set{
	public:
		Set(){//���캯��
			list=NULL;
			len=0;
		} 
		Set(Set<T>& s){//���ƹ��캯�� 
			list=new T[s.len];
			for(int i=0;i<s.len;i++){
				list[i]=s.list[i];
			}
			len=s.len;
		}
		T* begin()const;//����ָ���һ��Ԫ�صĵ����� 
		T* end()const;//����ָ�����һ��Ԫ�صĵ����� 
		void insert(const T item);//����һ��Ԫ�� 
		void clear();//���Ԫ�� 
		bool empty();//�жϼ����Ƿ�Ϊ�� 
		unsigned int count(const T item)const;//���ؼ�����ĳ��Ԫ�صĸ��� 
		unsigned int size()const;//���ؼ�����Ԫ�ص���Ŀ 
		bool erase(T item);//ɾ�������е�Ԫ��
		int find(const T item);//����һ��ָ�򱻲鵽��Ԫ�ص��±꣬δ�ҵ��򷵻�-1 
		~Set(){
			if(!empty()){
				delete []list;
				len=0;
			}
		}
	private:
		T* list;
		int len;
};
template <class T>
T* Set<T>::begin()const{
	return &list[0];
}
template <class T>
T* Set<T>::end()const{
	return &list[len-1];
}
template <class T>
bool Set<T>::empty(){
	return len==0;
}
template <class T>
void Set<T>::insert(const T item){
	if(find(item)==-1){
		if(!empty()){
			Set<T> temp(*this);
			delete []list;
			list=new T[len+1];
			for(int i=0;i<len;i++){
				list[i]=temp.list[i];
			}
			list[len]=item;
			len++;
			sort(list,list+len);
		} 
		else{
			list=new T[1];
			len=1;
			list[0]=item;
		}
	}
} 
template <class T>
void Set<T>::clear(){
	if(len!=0){
		delete []list;
		len=0;
	}
}
template <class T>
unsigned int Set<T>::count(const T item)const{
	for(int i=0;i<len;i++){
		if(list[i]==item){
			return 1;
		}
	}
	return 0;
}
template <class T>
unsigned int Set<T>::size()const{
	return len;
}
template <class T>
bool Set<T>::erase(T item){
	Set<T> temp(*this);
	assert(!empty());
	delete []list;
	len=0;
	int is_ok=0;
	for(int i=0;i<temp.len;i++){
		if(temp.list[i]==item){
			is_ok=1;
			continue;
		}
		insert(temp.list[i]);
	}
	if(is_ok==1){
		return true;
	}else{
		return false;
	}
}
template <class T>
int Set<T>::find(const T item){
	for(int i=0;i<len;i++){
		if(list[i]==item){
			return i;
		}
	}
	return -1;
}
/*����*/ 
int main(){
	Set<int> a;
	a.insert(2);
	a.insert(4);
	a.insert(3);
	a.insert(8);
	a.insert(5);
	a.insert(3);
	for(int* i=a.begin();i<=a.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;
	if(a.erase(4)){
		for(int* i=a.begin();i<=a.end();i++){
			cout<<*i<<" ";
		}
	}
	cout<<endl;
	cout<<a.find(5)<<endl;
	cout<<a.count(4)<<endl;
	cout<<a.empty()<<endl;
	a.clear();
	cout<<a.empty()<<endl;
} 
/*--------������--------
2 3 4 5 8
2 3 5 8
2
0
0
1
*/ 
