#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int score[20];
struct student{
	string s;
	int m;
	int scores; 
}stu[10000];
bool cmp(const student &a,const student &b){
	if(a.scores!=b.scores){
		return a.scores>b.scores;
	}else{
		return a.s<b.s;
	}
}
//int cmps(student a,student b){
//	int lena=strlen(a.s);
//	int lenb=strlen(b.s);
//	for(int i=0;i<min(lena,lenb);i++){
//		if(a.s[i]<b.s[i]){
//			return 1;
//		}
//		return -1;
//	}
//}
int main(){
	int N,M,G;
	while(scanf("%d",&N)!=EOF&&N){
		scanf("%d%d",&M,&G);
		for(int i=0;i<M;i++){
			scanf("%d",&score[i]);
		}
		int n=0;
		for(int i=0;i<N;i++){
			cin>>stu[i].s;
			//scanf("%s",stu[i].s);
			scanf("%d",&stu[i].m);
			stu[i].scores=0;
			for(int j=0;j<stu[i].m;j++){
				int t;
				scanf("%d",&t);
				stu[i].scores+=score[t-1];
			}
			if(stu[i].scores>=G){
				n++;
			}
		}
		printf("%d\n",n);
		sort(stu,stu+N,cmp);
//		sort(stu,stu+N,cmps);
//		for(int i=0;i<N;i++){
//			printf("stu[%d].s=%s stu[%d].m=%d stu[%d].scores=%d\n",i,stu[i].s,i,stu[i].m,i,stu[i].scores);
//		}
		for(int i=0;i<n;i++){
			cout <<stu[i].s<<" "<<stu[i].scores<<"\n"; 
			//printf("%s %d\n",stu[i].s,stu[i].scores);
		}
	}
	return 0;
}
