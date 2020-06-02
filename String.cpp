#include "String.h"
using namespace std; 
node::node()
{
	c=' ';
	next=NULL;
}
node::node(node *_node,char _c)
{
	next=_node;
	c=_c;
}
node::~node(){
	
}
String::String()
{
	head = new node;
	tail = new node;
	head->c=' ';
	head->next=tail;
	tail->c=' ';
	tail->next=NULL;
	cur=head;
	len=0; 
}

String::String(String& _string)
{
	head = new node;
	tail = new node;
	head->c=' ';
	head->next=tail;
	tail->next=NULL;
	tail->c=' ';
	len=0;
	cur=head;
	_string.Reset();
	while((!_string.EndOfString())&&(!_string.IsEmpty())){
		node* temp = new node;
		temp->c=_string.Data();
		temp->next=cur->next;
		cur->next=temp;
		cur=cur->next;
		_string.Next();
		len++;
	}
	Reset();
}

String::String(const char* _string)
{
	head = new node;
	tail = new node;
	head->c=' ';
	head->next=tail;
	tail->next=NULL;
	tail->c=' ';
	node* p=head;
	cur=head;
	for(int i=0;i<strlen(_string);i++){
		node* temp = new node;
		temp->c=_string[i];
		temp->next=p->next; 
		p->next=temp;
		p=p->next;
	}
	len=strlen(_string);
	 
}

bool String::IsEmpty()
{
	if(len==0) return true;
	else return false;
}

int String::Length()
{
	return len;
}

void String::Next()
{
	cur=cur->next;
}

char String::Data()
{
	return cur->c;
}

void String::Clear()
{
	cur=head;
	if(!IsEmpty())
	{
		cur=head->next;
		head->next=tail;
		while(!EndOfString())
		{
			node* temp=cur;
			cur=cur->next;
			len--;
			delete temp;
		}
		cur=head;
	}
}

bool String::EndOfString()
{
	if(cur==tail) return true;
	else return false;
} 
 

void String::Reset()
{
	if(IsEmpty()) cur=head;
	else cur=head->next;
}

int String::Index(String& _ptr)
{
	Reset();
	_ptr.Reset();
	int pos=1;
	while(!EndOfString())
	{
		if(cur->c==_ptr.Data())	_ptr.Next();
		else _ptr.Reset();
		cur=cur->next;
		pos++;
		if(_ptr.EndOfString())	return pos-_ptr.Length();
	}
	return -1;
} 

bool String::MoveTo(unsigned int pos)
{
	if(Length()>=pos)
	{
		if(pos==0) cur=head;
		else{
			cur=head;
			for(int i=1;i<=pos;i++)
			{
				cur=cur->next;
			}
		}
		
		return true;
	}
	return false;
} 

String String::Insert_string(unsigned int pos,String& _ptr)
{
	assert(Length()>=pos);
	MoveTo(pos);
	_ptr.Reset();
	while(!_ptr.EndOfString())
	{
		node* p=new node;
		p->c=_ptr.Data();
		p->next=cur->next;
		cur->next=p;
		Next();
		_ptr.Next();
		len++;
	}
	return (*this);
}

String String::Del_string(String& _ptr)
{
	int pos=Index(_ptr);
	if(Index(_ptr)!=-1)
	{
		MoveTo(pos-1);
		node* p=cur;
		
		int size=_ptr.Length();
		while(size--)
		{
			node* temp=p->next;
			p->next=temp->next;
			delete temp;
			len--;
		}
		cur->next=p->next;
	}
	return (*this);
 } 
String::~String()
{
}
/*≤‚ ‘*/ 
int main()
{
	String str("hello world!");
	String ptr1(" world");
	String ptr2(" HDU");
	str.Del_string(ptr1);
	str.Insert_string(5,ptr2);
	str.Reset();
	while(!str.EndOfString())
	{
		printf("%c",str.Data());
		str.Next();
	}
	printf("\n%d\n",str.Length());
}
