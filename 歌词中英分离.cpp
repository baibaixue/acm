/*��ȡһ����Ӣ����ļ������ļ��е�Ӣ�ĸ�ʺ����ĸ�ʷ��뿪��
�ֱ�д�������ļ���*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<list>
#include<iterator>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	char filename[100];
	list<string> linesc;
	list<string> linese;
	string line;
	cout << "please input the file name:";
	cin.getline(filename,100,'\n');
	in.open(filename,ios::in);
	if (in==NULL) {
		cout << "file could not be found." << endl;
		exit(0);
	}
	list<string>::iterator p;
	while(getline(in,line,'\n')){
		bool is_english=true;
		for(int i=0;i<line.length();i++){
			if(line[i]<0){
				is_english=false;
				break;
			}
		}
		if(is_english==true){
			linese.push_back(line); 
		}else{
			linesc.push_back(line); 
		}
	}
	out.open("D:\\song english.txt",ios::out);
	for(p=linese.begin();p!=linese.end();p++){
		out<<*p<<endl;
	}
	out.close();
	out.open("D:\\song chinese.txt",ios::out);
	for(p=linesc.begin();p!=linesc.end();p++){
		out<<*p<<endl;
	}
	out.close();
	in.close();
}
