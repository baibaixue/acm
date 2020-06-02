#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std; 
int main(){
	char name[15];
	scanf("%s",name);
		int k=0;
		getchar();
		char name2[15];
		char name14[15];
		while(name[0]!='.'){
		k++;
		if(k==2){
			for(int i=0;name[i]!='0';i++){
				name2[i]=name[i];
			}
		}if(k==14){
			for(int i=0;name[i]!='0';i++){
				name14[i]=name[i];
			}
		}
		memset(name,'0',sizeof(name));
		cin.getline(name,15);
	}
	if(k<2){
		printf("Momo... No one is for you ...\n");
	}else if(k>=2&&k<14){
		cout<<name2<<" is the only one for you..."<<endl;
	}else{
		cout<<name2<<" and "<<name14<<" are inviting you to dinner..."<<endl;
	}
	return 0;
}
