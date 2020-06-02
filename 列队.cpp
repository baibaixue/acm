#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int main(){
	int s;
	while(scanf("%d",&s)!=EOF){
		vector<int>que;
		char a,b;
		
		int num=1;
		for(int i=1;i<=s;i++){
			getchar();
			scanf("%c",&a);
			getchar();
			scanf("%c",&b);
			if(a=='A'){
				if(b=='L'){
					que.insert(que.begin(),num);
					num++;
				}
				if(b=='R'){
					que.push_back(num);
					num++;
				}
			}
			if(a=='D'){
				if(b=='L'){
					int k;
					scanf("%d",&k);
					que.erase(que.begin(),que.begin()+k);
				}
				if(b=='R'){
					int k;
					scanf("%d",&k);
					for(int i=0;i<k;i++){
						que.pop_back();
					}
				}
			}
		}
		for(int i=0;i<que.size();i++){
			printf("%d\n",que[i]);
		}
	}
	return 0;
}
