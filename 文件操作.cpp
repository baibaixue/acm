/*��ȡһƪӢ�ģ�����������Ӣ�ĵ��ʼ���Ƶ���η��������С�
����ͳ�Ʋ����Ǵ�Сд
���մ�Ƶ�Ӹߵ��Ͷ������������ ��д��һ���µ��ļ�
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iterator>
#include<list>
#include<iostream>
#include<fstream>
using namespace std;
//���ṹ�� 
struct node {
	string str;
	int times;
};
string str;
string ptr;
//���ҵ��� 
bool in_link(node a) {
	if (a.str == ptr) {
		return true;
	}
	return false;
}
//���ڳ���Ƶ�ʽ������� 
bool cmp(node a, node b) {
	return a.times > b.times;
}
int main() {
	ifstream in;
	ofstream out;
	char filename[100];
	cout << "please input the file name:";
	cin.getline(filename,100,'\n');
	in.open(filename, ios::in);
	out.open("D:\\words.txt", ios::out);
	list<node> words;
	if (in==NULL) {
		cout << "file could not be found." << endl;
		exit(0);
	}
	list<node>::iterator p;
	while (getline(in,str)) {
		ptr.clear();
		for (int i = 0; i < str.length(); i++) {
			if (str[i] <= 'z'&&str[i] >= 'a') {
				ptr += str[i];
			}
			else if (str[i] <= 'Z'&&str[i] >= 'A') {
				ptr += str[i] - 'A' + 'a';
			}
			else if (!ptr.empty()) {
				p = find_if(words.begin(), words.end(), in_link);
				if (p != words.end()) {
					p->times++;
				}
				else {
					node temp;
					temp.str = ptr;
					temp.times = 1;
					words.push_back(temp);
				}
				ptr.clear();
			}
		}
	}
	words.sort(cmp);
	for (p = words.begin(); p != words.end(); p++) {
		out << p->str << " " << p->times << endl;
	}
	cout<<"The words are departed from this article!"<<endl;
	in.close();
	out.close();
}
