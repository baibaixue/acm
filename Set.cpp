#include<cstdio>
#include<iostream>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
template <class T>
class Set{
	template <class A>
	friend ostream& operator<<(ostream& out,const Set<A> s);
	public:
		Set(){
			list=NULL;
			len=0;
		}
		Set(const Set<T>& s){
			list=new T[s.len+1];
			for(int i=0;i<s.len;i++){
				list[i]=s.list[i];
			}
			len=s.len;
		}
		int length()const;
		T insert(T item);
		bool search(T item)const;
		bool eras(T item);
		Set<T> operator+(const Set<T> rhs)const;
		Set<T> operator*(const Set<T> rhs)const;
		Set<T> operator-(const Set<T> rhs)const;
		~Set(){
			if(len=0){
				delete []list;
				list=NULL;
				len=0;
			}
		}
	private:
		T* list;
		int len;
}; 
template <class T>
int Set<T>::length()const{
	return len;
}
template <class T>
bool Set<T>::search(T item)const{
	for(int i=0;i<len;i++){
		if(list[i]==item){
			return true;
		}
	}
	return false;
}
template <class T>
T Set<T>::insert(T item){
	Set<T> temp(*this);
	if((*this).search(item)==true){
		return item;
	}
	if(len!=0){
		delete []list;
		list=NULL;
		len=0;
	}
	list=new T[temp.len+2];
	len=temp.len+1;
	for(int i=0;i<temp.len;i++){
		list[i]=temp.list[i];
	}
	list[temp.len]=item;
	sort(list,list+len);
	return item;
}
template<class T>
bool Set<T>::eras(T item){
	if((*this).search(item)==false){
		return true;
	}else{
		Set<T> temp(*this);
		if(len!=0){
			delete []list;
			list=NULL;
			len=0;
		}
		list=new T[temp.len];
		for(int i=0;i<temp.len;i++){
			if(temp.list[i]==item){
				continue;
			}
			(*this).insert(item);
		}
	}
}
template <class T>
Set<T> Set<T>::operator+(const Set<T> rhs)const{
	Set<T> temp;
	for(int i=0;i<len;i++){
		temp.insert(list[i]);
	}
	for(int i=0;i<rhs.len;i++){
		temp.insert(rhs.list[i]);
	}
	return temp;
}
template<class T>
Set<T> Set<T>::operator*(const Set<T> rhs)const{
	Set<T> temp;
	for(int i=0;i<len;i++){
		if(rhs.search(list[i])==true){
			temp.insert(list[i]);
		}
	} 
	return temp;
}
template<class T>
Set<T> Set<T>::operator-(const Set<T> rhs)const{
	Set<T> temp(*this);
	for(int i=0;i<len;i++){
		if(rhs.search(temp.list[i])==true){
			temp.eras(temp.list[i]); 
		}
	}
	return temp;
}
template <class A>
ostream& operator<<(ostream& out,const Set<A> s){
	for(int i=0;i<s.len;i++){
		out<<s.list[i]<<" ";
	}
	return out;
}
int main(){
	Set<int> a;
	a.insert(4);
	a.insert(2);
	a.insert(3);
	a.insert(2);
	Set<int> b;
	b.insert(2);
	cout<<a+b<<endl;
}
