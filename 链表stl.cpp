/*输入一个英文句子，将句中所有英文单词及词频依次放入链表中。 
单词统计不考虑大小写 
按照词频从高到低对链表进行排序 
*/ 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;
//结点结构体 
struct node{
	string str;
	int times;
};
string str;
string ptr;
//查找单词 
bool in_link(node a){
	if(a.str==ptr){
		return true;
	}
	return false;
}
//对于出现频率进行排序 
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
