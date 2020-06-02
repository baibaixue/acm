//哈夫曼编/译码器
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
struct node{
	char data;
	int frequence;
	node* lchild;
	node* rchild;
	node* parents;
}; 
struct Node{
	node* n;
	string p;
	int depth;
};
bool cmp(node* a,node* b){
	return a->frequence < b->frequence;
}
class Huffman{
	public:
		Huffman();
		void Build();
		string Encoding(char data);
		string Decoding(string code);
		void Print(string text);
		void Tree_Printing();
		void Clear();
		~Huffman();
	private:
		node* root;
};
node* Initialization(char data,int fre,node* lchild,node* rchild,node* parents){//初始化一棵树 
	node* root=root=new node;
	root->data=data;
	root->frequence=fre;
	root->lchild=lchild;
	root->rchild=rchild;
	root->parents=parents;
	return root;
}
Huffman::Huffman(){
	root=new node;
	root->parents=NULL;
	root->lchild=NULL;
	root->rchild=NULL;
} 
void Huffman::Build(){//建树 
	vector<node*> list;
	list.push_back(Initialization(' ',186,NULL,NULL,NULL));
	int fre[26]={64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
	for(int i=0;i<26;i++){
		list.push_back(Initialization('A'+i,fre[i],NULL,NULL,NULL));
	}
	sort(list.begin(),list.end(),cmp);
	
	while(list.size()!=1){
		node* temp=Initialization('*',list[0]->frequence+list[1]->frequence,list[0],list[1],NULL);
		list.push_back(temp);
		list[0]->parents=temp;
		list[1]->parents=temp;
		list.erase(list.begin(),list.begin()+2);
		sort(list.begin(),list.end(),cmp);
	}
	root=list[0];
}
void Huffman::Tree_Printing(){//输出哈夫曼树的凹入表 
	stack<Node> S;
	Node temp;
	temp.n=root;
	temp.depth=0;
	temp.p='r';
	S.push(temp);
	
	while(!S.empty()){
		Node Root;
		Node Lchild;
		Node Rchild;
		Root=S.top();
		S.pop();
		if(Root.n->lchild!=NULL){
			Lchild.n=Root.n->lchild;
			Lchild.depth=Root.depth+1;
			Lchild.p='0';
			S.push(Lchild);
		}
		if(Root.n->rchild!=NULL){
			Rchild.n=Root.n->rchild;
			Rchild.depth=Root.depth+1;
			Rchild.p='1';
			S.push(Rchild);
		}
		for(int i=0;i<Root.depth;i++){
			printf("	|");
		}
		cout<<Root.n->data<<":"<<Root.n->frequence<<"("<<Root.p<<")";
		printf("\n") ;
	}	
	/*
	queue<node*> Q;
	node* null_node=new node;
	null_node->data='\\';
	null_node->lchild=NULL;
	null_node->rchild=NULL;
	Q.push(root);
	node* temp;
	int leafe_node=0;
	for(int count = 0; ;count++){
		
		if(leafe_node==27){
			break;
		}
		for(int i=0;i<pow(2,count);i++){
			temp=Q.front();
			if(temp->lchild==NULL){
				Q.push(null_node);
			}else{
				Q.push(temp->lchild);
			}
			if(temp->rchild==NULL){
				Q.push(null_node);
			}else{
				Q.push(temp->rchild);
			}
			if(temp->data!='*'&&temp->data!='\\'){
				printf("'%c' ",temp->data);leafe_node++;
			}
			else if(temp->data=='*'){
				printf("*");
			}else{
				printf(" ");
			}
			Q.pop();
		}
		printf("\n");
	}
	*/
}
string Huffman::Encoding(char data){//编码单个字符 
	string code;
	stack<Node> S;
	Node now;
	now.n=root;
	now.p="";
	S.push(now);
	while(!S.empty()){
		now=S.top();
		if(now.n->data==data){
			code=now.p;
			break;
		}
		S.pop();
		Node next;
		if(now.n->lchild!=NULL){
			next.n=now.n->lchild;
			next.p=now.p+'0';
			S.push(next);
		}
		if(now.n->rchild!=NULL){
			next.n=now.n->rchild;
			next.p=now.p+'1';
			S.push(next); 
		}
	}
	return code;	
}
void Huffman::Print(string text){//编码文本并输出 
	for(int i=0;i<text.length();i++){
		cout<<Encoding(char(text[i]));
	}
	cout<<endl;
}
string Huffman::Decoding(string code){//译码 
	node* temp=root;
	string text;
	for(int i=0;i<code.length();i++){
		char c=code[i];
		if(temp->lchild!=NULL&&temp->rchild!=NULL){
			if(c=='1'){
				temp=temp->rchild;
			}else if(c=='0'){
				temp=temp->lchild;
			}
			if(temp->lchild==NULL||temp->rchild==NULL){
				text+=temp->data;
				temp=root;
			}
		}
	}
	return text;
} 
void Huffman::Clear(){//清空哈夫曼树 
	
	queue<node*> Q;
	if(root->rchild !=NULL){
		Q.push(root->rchild);
	} 
	if(root->lchild !=NULL){
		Q.push(root->lchild);
	}
	root->lchild=NULL;
	root->rchild=NULL;
	root->parents=NULL;
	root->data='*';
	root->frequence=0;
	while(!Q.empty()){
		if(Q.front()->lchild!=NULL){
			Q.push(Q.front()->lchild);
		}
		if(Q.front()->rchild!=NULL){
			Q.push(Q.front()->rchild);
		}
		delete Q.front();
		Q.pop();
	}

}
Huffman::~Huffman(){
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty()){
		if(Q.front()->lchild!=NULL){
			Q.push(Q.front()->lchild);
		}
		if(Q.front()->rchild!=NULL){
			Q.push(Q.front()->rchild);
		}
		delete Q.front();
		Q.pop();
	}
} 
int main(){
	Huffman tree;
	tree.Build();
	cout<<"哈夫曼树凹入表："<<endl; 
	tree.Tree_Printing();
	cout<<"各个字符的哈夫曼编码："<<endl; 
	char a='A';
	for(int i=0;i<26;i++){
		cout<<(char)(a+i)<<":"<<tree.Encoding(a+i)<<endl;
	}
	cout<<" :"<<tree.Encoding(' ')<<endl;
	cout<<"编译文本："<<endl; 
	string text="THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
	cout<<"'THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG':"<<endl; 
	tree.Print(text);
	cout<<"解译编码："<<endl; 
	string code;
	cin>>code;
	cout<<tree.Decoding(code)<<endl;
	
}
