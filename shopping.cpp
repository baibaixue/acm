#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 10005
using namespace std;
int shop[maxn];
map<string,int> name;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		getchar();
		char s[35];
		char s2[]="memory";
		int a;
		for(int i=0;i<n;i++){
			cin.getline(s,35);
			name[s]=i;
			//printf("%d\n",name[s]);
			if(strcmp(s,s2)==0){
				a=name[s];
			}
		}
		memset(shop,0,sizeof(shop));
		int day;
		scanf("%d",&day);
		for(int i=0;i<day;i++){
			for(int j=0;j<n;j++){
				int price;
				char ss[35];
				scanf("%d",&price);
				getchar();
				cin.getline(ss,35);
				shop[name[ss]]+=price;
				//printf("%d,",name[ss]);
			//	printf("%d\n",shop[name[ss]]);
			}
			int count=0; 
			for(int j=0;j<n;j++){
				if(shop[j]>shop[a]){
					count++;
				}
			}
			printf("%d\n",count+1);
		}
	}
	return 0;
}
