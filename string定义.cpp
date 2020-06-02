#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
class String{
	public:
		String(){//默认构造函数 
			buf=NULL;
		}
		String(const char* s){//构造函数 
			buf=new char[strlen(s)+1];
			strcpy(buf,s);
		}
		String(const String& rhs){//复制构造函数 
			buf=new char[strlen(rhs.buf)+1];
			strcpy(buf,rhs.buf);
		}
		String(const String& rhs,unsigned int pos,unsigned int n){//将对象rhs中的串从位置pos开始取n个字符初始化String类的对象 
			buf=new char[n+1];
			memcpy(buf,rhs.buf+pos,n);
		}
		String(const char* s,unsigned int n){//用指针s所指向的字符串中的前n个字符初始化为String类的对象
			buf=new char[n+1];
			memcpy(buf,s,n);
		}
		String(unsigned int n,char c){//将参数中的字符重复n次，用来初始化String类的对象 
			buf=new char[n+1];
			for(int i=0;i<n;i++){
				buf[i]=c;
			}
			buf[n]='\0';
		} 
		operator char*(){//类型转换，Sring类型转换为char*类型 
			return buf;
		}
		String operator+(const String& rhs)const;//两个字符串相加 
		String& operator=(const String& rhs);//字符串赋值 
		String& operator+=(const String& rhs);//字符串自加 
		bool operator ==(const String& rhs)const;//判断两个字符串是否相等 
		bool operator !=(const String& rhs)const;//判断两个字符串是否不等 
		bool operator <(const String& rhs)const;//判断两个字符串的大小关系 
		bool operator >(const String& rhs)const;//判断两个字符串的大小关系 
		char& operator[](unsigned int n)const;//下标运算符重载 
		String append(const char* s);//将字符串s添加在本串末尾
		String assign(const char* s);//赋值,将s所指向的字符串赋值给本对象
		int compare(const String& str)const;//比较本串与str中串的大小，
											//当本串<str时返回负数；
											//当本串>str时返回正数；
											//当两串相等时，返回0
		String& insert(unsigned int p0,const char* s);
		//将s所指向的字符串插入在本串中位置p0之前
		String substr(unsigned int pos,unsigned int n)const;
		//取子串，去本串中位值pos开始的n个字符，构成新的string类对象作为返回值
		int find(const String& str)const;
		//查找并返回str在本串中第一次出现的位置
		unsigned int length()const;
		//返回串的长度（字符个数）
		void swap(String& str);
		//将本串与str中的字符串进行交换
		~String(){
			if(buf!=NULL){
				delete []buf;
			}
		}
	private:
		char* buf;
};
String String::operator+(const String& rhs)const{//两个字符串相加
	String temp;
	temp.buf=new char[strlen(buf)+strlen(rhs.buf)+1];
	strcpy(temp.buf,buf);
	strcat(temp.buf,rhs.buf);
	temp.buf[strlen(buf)+strlen(rhs.buf)]='\0';
	return temp;
}
String& String::operator=(const String& rhs){//字符串赋值 
	if(buf!=NULL){
		delete []buf;
	}
	buf=new char[strlen(rhs.buf)+1];
	strcpy(buf,rhs.buf);
	return *this;
}
String& String::operator+=(const String& rhs){//字符串自加
	String temp(*this);
	*this=temp+rhs;
	return *this;
}
bool String::operator ==(const String& rhs)const{//判断两个字符串是否相等 
	return strcmp(buf,rhs.buf)==0;
}
bool String::operator !=(const String& rhs)const{//判断两个字符串是否不等 
	return strcmp(buf,rhs.buf)!=0;
}
bool String::operator <(const String& rhs)const{//判断两个字符串的大小关系 
	return strcmp(buf,rhs.buf)<0; 
}
bool String::operator >(const String& rhs)const{//判断两个字符串的大小关系 
	return strcmp(buf,rhs.buf)>0;
}
char& String::operator[](unsigned int n)const{//下标运算符重载 
	return buf[n];
}
String String::append(const char* s){//将字符串s添加在本串末尾
	*this=*this+s;
	return *this;
}
String String::assign(const char* s){//赋值,将s所指向的字符串赋值给本对象
	*this=s;
	return *this; 
}
int String::compare(const String& str)const{//比较本串与str中串的大小
	int a=strcmp(buf,str.buf);
	if(a==0){
		return 0;
	}else if(a>0){
		return 1;
	}else{
		return -1;
	}
}
String& String::insert(unsigned int p0,const char* s){//将s所指向的字符串插入在本串中位置p0之前
	String temp;
	temp=new char[strlen(buf)+strlen(s)+1];
	memcpy(temp,buf,p0);
	memcpy(temp+p0,s,strlen(s));
	memcpy(temp+p0+strlen(s),buf+p0+1,strlen(buf)-p0);
	*this=temp; 
	return *this;
}
String String::substr(unsigned int pos,unsigned int n)const{//取子串，去本串中位值pos开始的n个字符，构成新的string类对象作为返回值
	String temp;
	temp.buf=new char[n+1];
	memcpy(temp.buf,buf+pos,n);
	temp.buf[n]='\0';
	return temp;
}
int String::find(const String& str)const{//查找并返回str在本串中第一次出现的位置
	if(strlen(buf)<strlen(str.buf)){
		return -1;
	}
	int i,j;
	for(i=0;i<strlen(buf);i++){
		for(j=0;j<strlen(str.buf);j++){
			if(buf[i+j]!=str.buf[j]){
				break;
			}
		}
		if(j==strlen(str.buf)){
			return i;
		}
	}
	return -1;
}
unsigned int String::length()const{//返回串的长度（字符个数）
	if(buf==NULL){
		return 0;
	}else{
		return strlen(buf);
	}
}
void String::swap(String& str){//将本串与str中的字符串进行交换
	String temp;
	temp=str;
	str=*this;
	*this=temp;
}
int main(){
	cout<<"-------构造字符串-------"<<endl;
	String s1("abcdefgh");
	cout<<"s1="<<s1<<endl;
	String s2(s1) ;
	cout<<"s2(s1)="<<s2<<"\t"<<"(复制s1)"<<endl;
	String s3(3,'a');
	cout<<"s3(3,'a')="<<s3<<"\t"<<"(将字符a复制3次)"<<endl;
	String s4(s1,3,4);
	cout<<"s4(s1,3,4)="<<s4<<"\t"<<"(将s1从下表为3开始的四个字符赋值)"<<endl; 
	String s5(s1,5);
	cout<<"s5(s1,5)="<<s5<<"\t"<<"(将s1的前5个字符赋值)"<<endl;
	cout<<"-------运算符重载(加，赋值，自加)-------"<<endl;
	String s6=s1+s3;
	cout<<"(s6=s1+s3)="<<s6<<"\t"<<"(将s1+s3的值赋给s6)"<<endl;
	String s7=s1;
	s7+=s3;
	cout<<"s7=s1\ts7+=s3\ts7="<<s7<<"\t"<<"(将s1赋值给s7并令s7自加s3)"<<endl;
	cout<<"------运算符重载(判断大小)--------"<<endl; 
	if(s6==s7){
		cout<<"s6==s7"<<endl;
	}if(s1!=s6){
		cout<<"s1!=s6"<<endl;
	}
	if(s3<s1){
		cout<<"s3<s1"<<endl;
	}
	if(s6>s1){
		cout<<"s6>s1"<<endl;
	}
	cout<<"------下标运算符-------"<<endl;
	cout<<"s1[2]="<<s1[2]<<endl;
	cout<<"------相关函数---------"<<endl;
	cout<<"s1.append(\"asdsafa\")="<<s1.append("asdsafa")<<"\t"<<"(在s1后加上字符串)"<<endl;
	cout<<"s1.assign(\"abcdefgh\")="<<s1.assign("abcdefgh")<<"\t"<<"(给s1赋值)"<<endl;
	cout<<"s1.compare(s2)="<<s1.compare(s2)<<endl;
	cout<<"s1.compare(s3)="<<s1.compare(s3)<<endl;
	cout<<"s1.compare(s6)="<<s1.compare(s6)<<endl;
	cout<<"s1.insert(3,\"aaa11\")="<<s1.insert(3,"aaa11")<<"\t"<<"(在s1下标为3的元素之前插入aaa11)"<<endl;
	cout<<"s1.substr(4,6)="<<s1.substr(4,6)<<"\t"<<"(在s1下标为4的元素后取长度为6的子串)"<<endl;
	cout<<"s1.find(s3)="<<s1.find(s3)<<"\t"<<"(查找并返回aaa在本串中第一次出现的位置,找不到返回-1)"<<endl; 
	cout<<"s1.lengeh()="<<s1.length()<<"\t"<<"(s1的字符串长度)"<<endl;
	cout<<"s1="<<s1<<"\t"<<"s2="<<s2<<endl;
	s1.swap(s2);
	cout<<"s1.swap(s2)"<<"\t"<<"(交换s1,s2的值)"<<endl;
	cout<<"s1="<<s1<<"\t"<<"s2="<<s2<<endl;
}
/*-----------输出结果---------
 -------构造字符串-------
s1=abcdefgh
s2(s1)=abcdefgh (复制s1)
s3(3,'a')=aaa   (将字符a复制3次)
s4(s1,3,4)=defg (将s1从下表为3开始的四个字符赋值)
s5(s1,5)=abcde  (将s1的前5个字符赋值)
-------运算符重载(加，赋值，自加)-------
(s6=s1+s3)=abcdefghaaa  (将s1+s3的值赋给s6)
s7=s1   s7+=s3  s7=abcdefghaaa  (将s1赋值给s7并令s7自加s3)
------运算符重载(判断大小)--------
s6==s7
s1!=s6
s3<s1
s6>s1
------下标运算符-------
s1[2]=c
------相关函数---------
s1.append("asdsafa")=abcdefghasdsafa    (在s1后加上字符串)
s1.assign("abcdefgh")=abcdefgh  (给s1赋值)
s1.compare(s2)=0
s1.compare(s3)=1
s1.compare(s6)=-1
s1.insert(3,"aaa11")=abcaaa11efgh       (在s1下标为3的元素之前插入aaa11)
s1.substr(4,6)=aa11ef   (在s1下标为4的元素后取长度为6的子串)
s1.find(s3)=3   (查找并返回aaa在本串中第一次出现的位置,找不到返回-1)
s1.lengeh()=12  (s1的字符串长度)
s1=abcaaa11efgh s2=abcdefgh
s1.swap(s2)     (交换s1,s2的值)
s1=abcdefgh     s2=abcaaa11efgh
----------------------*/ 
