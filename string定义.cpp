#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
class String{
	public:
		String(){//Ĭ�Ϲ��캯�� 
			buf=NULL;
		}
		String(const char* s){//���캯�� 
			buf=new char[strlen(s)+1];
			strcpy(buf,s);
		}
		String(const String& rhs){//���ƹ��캯�� 
			buf=new char[strlen(rhs.buf)+1];
			strcpy(buf,rhs.buf);
		}
		String(const String& rhs,unsigned int pos,unsigned int n){//������rhs�еĴ���λ��pos��ʼȡn���ַ���ʼ��String��Ķ��� 
			buf=new char[n+1];
			memcpy(buf,rhs.buf+pos,n);
		}
		String(const char* s,unsigned int n){//��ָ��s��ָ����ַ����е�ǰn���ַ���ʼ��ΪString��Ķ���
			buf=new char[n+1];
			memcpy(buf,s,n);
		}
		String(unsigned int n,char c){//�������е��ַ��ظ�n�Σ�������ʼ��String��Ķ��� 
			buf=new char[n+1];
			for(int i=0;i<n;i++){
				buf[i]=c;
			}
			buf[n]='\0';
		} 
		operator char*(){//����ת����Sring����ת��Ϊchar*���� 
			return buf;
		}
		String operator+(const String& rhs)const;//�����ַ������ 
		String& operator=(const String& rhs);//�ַ�����ֵ 
		String& operator+=(const String& rhs);//�ַ����Լ� 
		bool operator ==(const String& rhs)const;//�ж������ַ����Ƿ���� 
		bool operator !=(const String& rhs)const;//�ж������ַ����Ƿ񲻵� 
		bool operator <(const String& rhs)const;//�ж������ַ����Ĵ�С��ϵ 
		bool operator >(const String& rhs)const;//�ж������ַ����Ĵ�С��ϵ 
		char& operator[](unsigned int n)const;//�±���������� 
		String append(const char* s);//���ַ���s����ڱ���ĩβ
		String assign(const char* s);//��ֵ,��s��ָ����ַ�����ֵ��������
		int compare(const String& str)const;//�Ƚϱ�����str�д��Ĵ�С��
											//������<strʱ���ظ�����
											//������>strʱ����������
											//���������ʱ������0
		String& insert(unsigned int p0,const char* s);
		//��s��ָ����ַ��������ڱ�����λ��p0֮ǰ
		String substr(unsigned int pos,unsigned int n)const;
		//ȡ�Ӵ���ȥ������λֵpos��ʼ��n���ַ��������µ�string�������Ϊ����ֵ
		int find(const String& str)const;
		//���Ҳ�����str�ڱ����е�һ�γ��ֵ�λ��
		unsigned int length()const;
		//���ش��ĳ��ȣ��ַ�������
		void swap(String& str);
		//��������str�е��ַ������н���
		~String(){
			if(buf!=NULL){
				delete []buf;
			}
		}
	private:
		char* buf;
};
String String::operator+(const String& rhs)const{//�����ַ������
	String temp;
	temp.buf=new char[strlen(buf)+strlen(rhs.buf)+1];
	strcpy(temp.buf,buf);
	strcat(temp.buf,rhs.buf);
	temp.buf[strlen(buf)+strlen(rhs.buf)]='\0';
	return temp;
}
String& String::operator=(const String& rhs){//�ַ�����ֵ 
	if(buf!=NULL){
		delete []buf;
	}
	buf=new char[strlen(rhs.buf)+1];
	strcpy(buf,rhs.buf);
	return *this;
}
String& String::operator+=(const String& rhs){//�ַ����Լ�
	String temp(*this);
	*this=temp+rhs;
	return *this;
}
bool String::operator ==(const String& rhs)const{//�ж������ַ����Ƿ���� 
	return strcmp(buf,rhs.buf)==0;
}
bool String::operator !=(const String& rhs)const{//�ж������ַ����Ƿ񲻵� 
	return strcmp(buf,rhs.buf)!=0;
}
bool String::operator <(const String& rhs)const{//�ж������ַ����Ĵ�С��ϵ 
	return strcmp(buf,rhs.buf)<0; 
}
bool String::operator >(const String& rhs)const{//�ж������ַ����Ĵ�С��ϵ 
	return strcmp(buf,rhs.buf)>0;
}
char& String::operator[](unsigned int n)const{//�±���������� 
	return buf[n];
}
String String::append(const char* s){//���ַ���s����ڱ���ĩβ
	*this=*this+s;
	return *this;
}
String String::assign(const char* s){//��ֵ,��s��ָ����ַ�����ֵ��������
	*this=s;
	return *this; 
}
int String::compare(const String& str)const{//�Ƚϱ�����str�д��Ĵ�С
	int a=strcmp(buf,str.buf);
	if(a==0){
		return 0;
	}else if(a>0){
		return 1;
	}else{
		return -1;
	}
}
String& String::insert(unsigned int p0,const char* s){//��s��ָ����ַ��������ڱ�����λ��p0֮ǰ
	String temp;
	temp=new char[strlen(buf)+strlen(s)+1];
	memcpy(temp,buf,p0);
	memcpy(temp+p0,s,strlen(s));
	memcpy(temp+p0+strlen(s),buf+p0+1,strlen(buf)-p0);
	*this=temp; 
	return *this;
}
String String::substr(unsigned int pos,unsigned int n)const{//ȡ�Ӵ���ȥ������λֵpos��ʼ��n���ַ��������µ�string�������Ϊ����ֵ
	String temp;
	temp.buf=new char[n+1];
	memcpy(temp.buf,buf+pos,n);
	temp.buf[n]='\0';
	return temp;
}
int String::find(const String& str)const{//���Ҳ�����str�ڱ����е�һ�γ��ֵ�λ��
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
unsigned int String::length()const{//���ش��ĳ��ȣ��ַ�������
	if(buf==NULL){
		return 0;
	}else{
		return strlen(buf);
	}
}
void String::swap(String& str){//��������str�е��ַ������н���
	String temp;
	temp=str;
	str=*this;
	*this=temp;
}
int main(){
	cout<<"-------�����ַ���-------"<<endl;
	String s1("abcdefgh");
	cout<<"s1="<<s1<<endl;
	String s2(s1) ;
	cout<<"s2(s1)="<<s2<<"\t"<<"(����s1)"<<endl;
	String s3(3,'a');
	cout<<"s3(3,'a')="<<s3<<"\t"<<"(���ַ�a����3��)"<<endl;
	String s4(s1,3,4);
	cout<<"s4(s1,3,4)="<<s4<<"\t"<<"(��s1���±�Ϊ3��ʼ���ĸ��ַ���ֵ)"<<endl; 
	String s5(s1,5);
	cout<<"s5(s1,5)="<<s5<<"\t"<<"(��s1��ǰ5���ַ���ֵ)"<<endl;
	cout<<"-------���������(�ӣ���ֵ���Լ�)-------"<<endl;
	String s6=s1+s3;
	cout<<"(s6=s1+s3)="<<s6<<"\t"<<"(��s1+s3��ֵ����s6)"<<endl;
	String s7=s1;
	s7+=s3;
	cout<<"s7=s1\ts7+=s3\ts7="<<s7<<"\t"<<"(��s1��ֵ��s7����s7�Լ�s3)"<<endl;
	cout<<"------���������(�жϴ�С)--------"<<endl; 
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
	cout<<"------�±������-------"<<endl;
	cout<<"s1[2]="<<s1[2]<<endl;
	cout<<"------��غ���---------"<<endl;
	cout<<"s1.append(\"asdsafa\")="<<s1.append("asdsafa")<<"\t"<<"(��s1������ַ���)"<<endl;
	cout<<"s1.assign(\"abcdefgh\")="<<s1.assign("abcdefgh")<<"\t"<<"(��s1��ֵ)"<<endl;
	cout<<"s1.compare(s2)="<<s1.compare(s2)<<endl;
	cout<<"s1.compare(s3)="<<s1.compare(s3)<<endl;
	cout<<"s1.compare(s6)="<<s1.compare(s6)<<endl;
	cout<<"s1.insert(3,\"aaa11\")="<<s1.insert(3,"aaa11")<<"\t"<<"(��s1�±�Ϊ3��Ԫ��֮ǰ����aaa11)"<<endl;
	cout<<"s1.substr(4,6)="<<s1.substr(4,6)<<"\t"<<"(��s1�±�Ϊ4��Ԫ�غ�ȡ����Ϊ6���Ӵ�)"<<endl;
	cout<<"s1.find(s3)="<<s1.find(s3)<<"\t"<<"(���Ҳ�����aaa�ڱ����е�һ�γ��ֵ�λ��,�Ҳ�������-1)"<<endl; 
	cout<<"s1.lengeh()="<<s1.length()<<"\t"<<"(s1���ַ�������)"<<endl;
	cout<<"s1="<<s1<<"\t"<<"s2="<<s2<<endl;
	s1.swap(s2);
	cout<<"s1.swap(s2)"<<"\t"<<"(����s1,s2��ֵ)"<<endl;
	cout<<"s1="<<s1<<"\t"<<"s2="<<s2<<endl;
}
/*-----------������---------
 -------�����ַ���-------
s1=abcdefgh
s2(s1)=abcdefgh (����s1)
s3(3,'a')=aaa   (���ַ�a����3��)
s4(s1,3,4)=defg (��s1���±�Ϊ3��ʼ���ĸ��ַ���ֵ)
s5(s1,5)=abcde  (��s1��ǰ5���ַ���ֵ)
-------���������(�ӣ���ֵ���Լ�)-------
(s6=s1+s3)=abcdefghaaa  (��s1+s3��ֵ����s6)
s7=s1   s7+=s3  s7=abcdefghaaa  (��s1��ֵ��s7����s7�Լ�s3)
------���������(�жϴ�С)--------
s6==s7
s1!=s6
s3<s1
s6>s1
------�±������-------
s1[2]=c
------��غ���---------
s1.append("asdsafa")=abcdefghasdsafa    (��s1������ַ���)
s1.assign("abcdefgh")=abcdefgh  (��s1��ֵ)
s1.compare(s2)=0
s1.compare(s3)=1
s1.compare(s6)=-1
s1.insert(3,"aaa11")=abcaaa11efgh       (��s1�±�Ϊ3��Ԫ��֮ǰ����aaa11)
s1.substr(4,6)=aa11ef   (��s1�±�Ϊ4��Ԫ�غ�ȡ����Ϊ6���Ӵ�)
s1.find(s3)=3   (���Ҳ�����aaa�ڱ����е�һ�γ��ֵ�λ��,�Ҳ�������-1)
s1.lengeh()=12  (s1���ַ�������)
s1=abcaaa11efgh s2=abcdefgh
s1.swap(s2)     (����s1,s2��ֵ)
s1=abcdefgh     s2=abcaaa11efgh
----------------------*/ 
