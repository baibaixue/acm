#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct student{
	int p;
	int t;
	int scores;
	int id; 
}stu[110];
int cmp1(student a,student b){
	if(a.p==b.p){
		return a.t<b.t;
	}else{
		return a.p>b.p;
	}
}
int cmp2(student a,student b){
	return a.id<b.id;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n>=0){
		for(int i=0;i<n;i++){
			cin>>stu[i].p;
			int h,m,s;
			scanf("%d:%d:%d",&h,&m,&s);
			stu[i].t=h*3600+m*60+s;
			if(stu[i].p==5){
				stu[i].scores=100;
			}else if(stu[i].p==0){
				stu[i].scores=50;
			}
			stu[i].id=i;
		}
		int a=0,b=0,c=0,d=0;
		for(int i=0;i<n;i++){
			if(stu[i].p==5){
				stu[i].scores=100;
			}else if(stu[i].p==0){
				stu[i].scores=50;
			}else if(stu[i].p==4){
				a++;
				stu[i].scores=90;
			}else if(stu[i].p==3){
				b++;
				stu[i].scores=80;
			}else if(stu[i].p==2){
				c++;
				stu[i].scores=70;
			}else if(stu[i].p==1){
				d++;
				stu[i].scores=60;
			}
		}
		sort(stu,stu+n,cmp1);
		for(int i=0;i<n;i++){
			if(stu[i].p==4&&(a)/2>0){
				stu[i].scores+=5;
				a-=2;
			}else if(stu[i].p==3&&(b)/2>0){
				stu[i].scores+=5;
				b-=2;
			}else if(stu[i].p==2&&(c)/2>0){
				stu[i].scores+=5;
				c-=2;
			}else if(stu[i].p==1&&(d)/2>0){
				stu[i].scores+=5;
				d-=2;
			}
		}
		sort(stu,stu+n,cmp2);
		for(int i=0;i<n;i++){
			printf("%d\n",stu[i].scores);
		}
		printf("\n");
	}
	return 0;
} 
