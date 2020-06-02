#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std; 
struct student{
	string name;
	int age;
	double score;
};
bool cmp(student a,student b){
	if(a.score==b.score){
		if(a.age==b.age){
			return a.name<b.name;
		}
		else{
			return a.age<b.age;
		}
	}else{
		return a.score>b.score;
	}
}
int main(){
	int N;
	student num[105];
	while(scanf("%d",&N)!=EOF){
		getchar();
		for(int i=0;i<N;i++){
			cin>>num[i].name>>num[i].age>>num[i].score;
		}
		sort(num,num+N,cmp);
		for(int i=0;i<N;i++){
			cout<<num[i].name;
			printf(" %d %.2f\n",num[i].age,num[i].score);
		}
	}
}
