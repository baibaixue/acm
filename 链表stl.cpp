/*����һ��Ӣ�ľ��ӣ�����������Ӣ�ĵ��ʼ���Ƶ���η��������С� 
����ͳ�Ʋ����Ǵ�Сд 
���մ�Ƶ�Ӹߵ��Ͷ������������ 
*/ 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;
//���ṹ�� 
struct node{
	string str;
	int times;
};
string str;
string ptr;
//���ҵ��� 
bool in_link(node a){
	if(a.str==ptr){
		return true;
	}
	return false;
}
//���ڳ���Ƶ�ʽ������� 
bool cmp(node a,node b){
	return a.times>b.times;
}
int main(){
	list<node> words;
	getline(cin,str);
	ptr.clear(); 
	list<node>::iterator p;
	for(int i=0;i<str.length();i++){
		if(str[i]<='z'&&str[i]>='a'){
			ptr+=str[i];
		}else if(str[i]<='Z'&&str[i]>='A'){
			ptr+=str[i]-'A'+'a';
		}else if(!ptr.empty()){
			p=find_if(words.begin(),words.end(),in_link);
			if(p!=words.end()){
				p->times++;
			}else{
				node temp;
				temp.str=ptr;
				temp.times=1;
				words.push_back(temp); 
			}
			ptr.clear();
		}
	}
	words.sort(cmp); 
	for(p=words.begin();p!=words.end();p++){
		cout<<p->str<<" "<<p->times<<endl; 
	}
}
