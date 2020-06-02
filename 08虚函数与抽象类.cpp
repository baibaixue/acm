/*T1���
(1,2)
5,6
5,6
(3,4)
T2���
Shape Test OK!
Draw A Triangle Here
Move shape
Shape Test OK!
Draw A Square Here
Move Square
*/


/*���һ������ʦ���ĳ�����HDUPerson*/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
/*����hduperson*/ 
class HDUPerson{
	public:
		HDUPerson(){//Ĭ�Ϲ��캯�� 
			name.clear();
			sex=0;
			age=0;
		}
		HDUPerson(string _name,bool _sex,unsigned int _age){//�������Ĺ��캯�� 
			name=_name;
			sex=_sex;
			age=_age;
		}
		virtual void IntroduceSelf();//�麯�� 
		virtual void GetCurrentNum()=0;//���麯�� 
		virtual ~HDUPerson(){
			cout<<"p"<<endl;
		}//�������� 
	private:
		string name;//���� 
		bool sex;//�Ա� 
		unsigned int age;//���� 
}; 
void HDUPerson::IntroduceSelf(){//�����е�introduceself���� 
	cout<<"������"<<name<<endl;
	if(sex==0){
		cout<<"�Ա���"<<endl; 
	}else{
		cout<<"�Ա�Ů"<<endl;
	}
	cout<<"���䣺"<<age<<endl; 
}
/*������ѧ��*/ 
class Student:public HDUPerson{ 
	public:
		Student()
		:HDUPerson(){
			course_num=0;
		}
		Student(string _name,bool _sex,unsigned int _age)
		:HDUPerson(_name,_sex,_age){
			course_num=0;
		}
		void IntroduceSelf();
		void GetCurrentNum();
		~Student(){
			cout<<"s"<<endl;
		}
	private:
		unsigned int course_num;
};
void Student::IntroduceSelf(){//�����������غ��introduceself���� 
	cout<<"ְλ��ѧ��"<<endl;
	HDUPerson::IntroduceSelf();
	cout<<"Ŀǰ��ѧ�γ�"<<course_num<<"��"<<endl; 
}
void Student::GetCurrentNum(){//����γ��� 
	cin>>course_num; 
}
/*��������ʦ*/ 
class Teacher:public HDUPerson{
	public:
		Teacher()
		:HDUPerson(){
			teaching_hours=0;
		}
		Teacher(string _name,bool _sex,unsigned int _age)
		:HDUPerson(_name,_sex,_age){
			teaching_hours=0; 
		}
		void IntroduceSelf();
		void GetCurrentNum();
		~Teacher(){
		cout<<"t"<<endl; 
		}
	private:
		unsigned int teaching_hours;
};
void Teacher::IntroduceSelf(){
	cout<<"ְλ����ʦ"<<endl;
	HDUPerson::IntroduceSelf();
	cout<<"Ŀǰÿ���ڿ�"<<teaching_hours<<"ѧʱ"<<endl; 
}
void Teacher::GetCurrentNum(){//����ѧʱ 
	cin>>teaching_hours;
}
/*����*/ 
int main(){
	Student a("Tom",0,18);
	Teacher b("Marry",1,31);
	HDUPerson* p;//����HDUPersonָ�� 
	p=&a;//ָ��ѧ������� 
	p->GetCurrentNum();
	p->IntroduceSelf(); 
	p=&b;//ָ����ʦ����� 
	p->GetCurrentNum();
	p->IntroduceSelf();
}
