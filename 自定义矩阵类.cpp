/*�Զ��������,�Ӽ�������������ʵ����δ�ܳɹ�д��ģ���ǿ������ת����*/ 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;
template <class T>
class Matrix{
	template <class A,class B>
	friend Matrix<double> operator*(const A& num,const Matrix<B>& rhs);
	//�Ѻ�������������(����ʵ����
	public:
		Matrix<T>(){//���캯�� 
			row=0;
			col=0;
			mat=NULL;
		}
		Matrix<T>(const Matrix<T> &m){//���ƹ��캯�� 
			row=m.row;
			col=m.col;
			mat=new T[m.row*m.col+1];
			for(int i=0;i<m.row*m.col;i++){
				mat[i]=m.mat[i];
			}
		}	
		Matrix<T> operator+(const Matrix<T> &rhs)const;//��ͬ���͵������������ 
		Matrix<T> operator-(const Matrix<T> &rhs)const;//��ͬ���͵������������ 
		Matrix<T> operator-()const;//������ 
		Matrix<T> operator*(const Matrix<T> &rhs)const;//��������� 
		Matrix<T> operator^(const unsigned int n)const;//������ 
		Matrix<T>& operator=(const Matrix<T> &rhs);//��ֵ 
		T* operator[](const unsigned int& n);//�����±������ 
		Matrix<T> t()const;//ת�þ��� 
		bool operator==(const Matrix<T> &rhs)const;//�ж��������Ƿ���� 
		void get_matrix();//������� 
		void show_matrix();//������� 
		T& query(int a,int b)const;//���ʾ����a�е�b�е�Ԫ�� 
		~Matrix(){//���� 
			if(row!=0&&col!=0){
				delete []mat;
				mat=NULL;
				row=0;col=0;
			}
		}
	private:
		int row,col;//�У��� 
		T* mat;
		
}; 
template <class T>
void Matrix<T>::get_matrix(){//������� 
	cin>>row>>col;
	mat=new T[row*col+1]; 
	for(int i=0;i<row*col;i++){
		cin>>mat[i];
	}
}
template <class T>
void Matrix<T>::show_matrix(){//������� 
	for(int i=0;i<row*col;i++){
		cout<<mat[i];
		if((i+1)%col==0){
			cout<<"\n";
		}else{
			cout<<" ";
		}
	}
	cout<<endl;
}
template <class T>
T& Matrix<T>::query(int a,int b)const{//���ʾ���Ԫ�� 
	assert(a*b<=row*col);
	return mat[(a-1)*col+(b-1)];
}
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs)const{
	assert(row==rhs.row&&col==rhs.col);
	Matrix <T>temp(rhs);
	for(int i=0;i<row*col;i++){
		temp.mat[i]+=mat[i];
	}
	return temp;
}
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs)const{
	assert(row==rhs.row&&col==rhs.col);
	Matrix<T> temp(*this);
	for(int i=0;i<row*col;i++){
		temp.mat[i]-=rhs.mat[i];
	}
	return temp;
} 
template <class T>
Matrix<T> Matrix<T>::operator-()const{
	Matrix<T> temp(*this);
	for(int i=0;i<temp.row*temp.col;i++){
		temp.mat[i]*=(-1);
	}
	return temp;
}

template <class A,class B>
Matrix<double> operator*(const A& num,const Matrix<B>& rhs){//���� 
	Matrix<double> temp;
	temp.mat=new double[rhs.row*rhs.col+1];
	temp.row=rhs.row;
	temp.col=rhs.col;
	for(int i=0;i<rhs.row*rhs.col;i++){
		temp.mat[i]=rhs.mat[i]*num*1.0;
	}
	return temp;
}
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)const{
	assert(col==rhs.row);
	Matrix<T> temp;
	temp.mat=new T[row*rhs.col+1];
	temp.row=row;temp.col=rhs.col;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=rhs.col;j++){
			temp.query(i,j)=0; 
			for(int k=1;k<=col;k++){
				temp.query(i,j)+=query(i,k)*rhs.query(k,j);
			}
		}
	}
	return temp;
}
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs){
	if(rhs.mat!=mat){
		if(row==0||col==0){
			mat=new T[rhs.row*rhs.col+1];
			row=rhs.row;col=rhs.col;
			for(int i=0;i<row*col;i++){
				mat[i]=rhs.mat[i];
			}
			return *this;
		}else{
			delete []mat;
			mat=new T[rhs.row*rhs.col+1];
			row=rhs.row;col=rhs.col;
			for(int i=0;i<row*col;i++){
				mat[i]=rhs.mat[i];
			}
			return *this;
		}
	}else {
		return *this;
	} 
	
}
template <class T>
Matrix<T> Matrix<T>::operator^(const unsigned int n)const{
	assert(row==col);
	unsigned int k=n;
	Matrix<T> ans;
	ans.row=row;
	ans.col=col;
	ans.mat=new T[row*col+1];
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			ans.query(i,j)=0;
			ans.query(i,i)=1;
		}
	}
	Matrix<T> temp(*this);
	while(k!=0){
		if(k%2==1){
			ans=(ans*temp);
			k=k-1;
		}
		temp=temp*temp;
		k=k/2;
	}
	return temp;
}
template <class T>
bool Matrix<T>::operator==(const Matrix<T> &rhs)const{
	if(row==rhs.row&&col==rhs.col){
		for(int i=0;i<row*col;i++){
			if(mat[i]!=rhs.mat[i]){
				return false;
			}
			return true;
		}
	}
	return false;
}
template <class T>
Matrix<T> Matrix<T>::t()const{
	Matrix<T> temp;
	temp.mat=new T[row*col+1];
	temp.row=row;temp.col=col;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			temp.query(i,j)=query(j,i); 
		}
	}
	return temp;
}
template <class T>
T* Matrix<T>::operator[](const unsigned int& n){//�±���������� 
	return &mat[n*col];
}
/*����*/ 
int main(){
	Matrix <int>a;
	a.get_matrix();
	cout<<"a:"<<endl;
	a.show_matrix();
	Matrix <int>b;
	b.get_matrix();
	cout<<"b:"<<endl;
	b.show_matrix();
	cout<<"b�����һ�еڶ��е�Ԫ�أ�"<<b.query(1,2)<<endl; //����b(1,2)��Ԫ�� 
	cout<<"b[0][1]="<<b[0][1]<<endl; 
	Matrix<int> c;
	c.get_matrix();
	cout<<"c:"<<endl;
	c.show_matrix();
	cout<<"a+c:"<<endl;
	(a+c).show_matrix();//�ӷ� 
	cout<<"a-c:"<<endl;
	(a-c).show_matrix();//���� 
	Matrix<int> d(a*b);//�˷� /���ƹ��� 
	cout<<"d=(a*b)\n"<<"d:"<<endl;
	d.show_matrix();
	Matrix <double> e=(-0.3*d);//���� 
	cout<<"e=(-0.3*d)\n"<<"e:"<<endl; 
	(-0.3*d).show_matrix();
	Matrix<int> f(a^3);//�� 
	cout<<"f=(a^3)\n"<<"f:"<<endl; 
	f.show_matrix();
	Matrix<int> g=f;
	cout<<"g=e\n"<<"g:"<<endl;
	g.show_matrix(); 
	g=g;
	cout<<"g=g\n"<<"g:"<<endl; 
	g.show_matrix();
	cout<<"g.t()��"<<endl; 
	(g.t()).show_matrix();//ת�þ��� 
	if(f==g){
		cout<<"g==f"<<endl;
	}
}
/*--------������-------
2 2
1 2
3 4
a:
1 2
3 4

2 4
2 3 5 6
2 4 6 7
b:
2 3 5 6
2 4 6 7

b�����һ�еڶ��е�Ԫ�أ�3 
b[0][1]=3
2 2
1 5
5 2
c:
1 5
5 2

a+c:
2 7
8 6

a-c:
0 -3
-2 2

d=(a*b)
d:
6 11 17 20
14 25 39 46

e=(-0.3*d)
e:
-1.8 -3.3 -5.1 -6
-4.2 -7.5 -11.7 -13.8

f=(a^3)
f:
199 290
435 634

g=e
g:
199 290
435 634

g=g
g:
199 290
435 634

g.t()��
199 435
290 634

g==f
*/ 

