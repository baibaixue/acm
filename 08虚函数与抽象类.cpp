/*T1输出
(1,2)
5,6
5,6
(3,4)
T2输出
Shape Test OK!
Draw A Triangle Here
Move shape
Shape Test OK!
Draw A Square Here
Move Square
*/


/*设计一个杭电师生的抽象类HDUPerson*/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
/*基类hduperson*/ 
class HDUPerson{
	public:
		HDUPerson(){//默认构造函数 
			name.clear();
			sex=0;
			age=0;
		}
		HDUPerson(string _name,bool _sex,unsigned int _age){//带参数的构造函数 
			name=_name;
			sex=_sex;
			age=_age;
		}
		virtual void IntroduceSelf();//虚函数 
		virtual void GetCurrentNum()=0;//纯虚函数 
		virtual ~HDUPerson(){
			cout<<"p"<<endl;
		}//析构函数 
	private:
		string name;//姓名 
		bool sex;//性别 
		unsigned int age;//年龄 
}; 
void HDUPerson::IntroduceSelf(){//基类中的introduceself函数 
	cout<<"姓名："<<name<<endl;
	if(sex==0){
		cout<<"性别：男"<<endl; 
	}else{
		cout<<"性别：女"<<endl;
	}
	cout<<"年龄："<<age<<endl; 
}
/*派生类学生*/ 
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
void Student::IntroduceSelf(){//派生类中重载后的introduceself函数 
	cout<<"职位：学生"<<endl;
	HDUPerson::IntroduceSelf();
	cout<<"目前在学课程"<<course_num<<"门"<<endl; 
}
void Student::GetCurrentNum(){//读入课程数 
	cin>>course_num; 
}
/*派生类老师*/ 
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
	cout<<"职位：教师"<<endl;
	HDUPerson::IntroduceSelf();
	cout<<"目前每周授课"<<teaching_hours<<"学时"<<endl; 
}
void Teacher::GetCurrentNum(){//读入学时 
	cin>>teaching_hours;
}
/*测试*/ 
int main(){
	Student a("Tom",0,18);
	Teacher b("Marry",1,31);
	HDUPerson* p;//基类HDUPerson指针 
	p=&a;//指向学生类对象 
	p->GetCurrentNum();
	p->IntroduceSelf(); 
	p=&b;//指向老师类对象 
	p->GetCurrentNum();
	p->IntroduceSelf();
}
