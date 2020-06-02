#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<string.h>
#include<string>
#define maxn 505
using namespace std;
int rank_boy[maxn][maxn];//��������������Ů�� 
int rank_girl[maxn][maxn];//Ů����������ϲ���̶� 
int matchboy[maxn];//����Ŀǰƥ�� 
int matchgirl[maxn];//Ů����ƥ�� 
string boy[maxn];//��Ӧ��ŵ����������� 
string girl[maxn];//��Ӧ��ŵ�Ů�������� 
map<string,int> boy_name;//�������ֱ�� 
map<string,int> girl_name;//Ů�����ֱ�� 
int Rank[maxn];
int n;
void match(){
	for(int i=1;i<=n;i++){
		Rank[i]=1;
	}
	while(1){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(matchboy[i]==0){
				int g=rank_boy[i][Rank[i]++];
				if(matchgirl[g]==0){
					matchboy[i]=g;
					matchgirl[g]=i;
				}else{
					int pre=matchgirl[g];
					if(rank_girl[g][pre]<rank_girl[g][i]){
						matchboy[pre]=0;
						matchgirl[g]=i;
						matchboy[i]=g;
					}
					
				}
				flag=1;
			}	
		} 
		if(flag==0){
			break;
		}
	}
} 
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(matchboy,0,sizeof(matchboy));
		memset(matchgirl,0,sizeof(matchgirl));
		boy_name.clear();girl_name.clear();
		//boy[].clear();girl[].clear();
		int pos=1;
		string s;
		for(int i=1;i<=n;i++){
			cin>>s;
			boy_name[s]=i;
			boy[i]=s;
			for(int j=1;j<=n;j++){
				string s;
				cin>>s;
				int temp=girl_name[s];
				if(temp==0){
					girl_name[s]=pos;
					girl[pos]=s;
					rank_boy[i][j]=pos;
					girl[pos]=s;
					pos++;
				}else{
					rank_boy[i][j]=temp;
					girl[temp]=s;
				}
			}
		}
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			int x=girl_name[s];
			for(int j=1;j<=n;j++){
				cin>>s;
				int y=boy_name[s];
				rank_girl[x][y]=n-j-1;
			}
		}
		match();
		for(int i=1;i<=n;i++){
			cout<<boy[i]<<" "<<girl[matchboy[i]]<<endl;
		}
		printf("\n");
	}
}
