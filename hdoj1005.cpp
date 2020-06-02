#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10010 
using namespace std;
struct shop{
	int price[55];
	string name;
}num[maxn];
int search(int l,int r,string s){
	int m;
	while(l<=r){
		if(num[m].name==s){
			return m;
		}else if(num[m].name<s){
			l=m+1;
		}else if(num[m].name>s){
			r=m-1;
		}
	}
	return 0;
}
int cmp(shop a,shop b){
	return a.name<b.name;
}
//int cmp2(shop a,shop b,int* day){
//	return a.price[day]<a.price[day];
//}
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			string na;
			scanf("%s",na);
			strcpy(num[i].name,na);
		}
		sort(num+1,num+1+n,cmp);
		scanf("%d",&m);
		for(int i=1;i<=n;i++){
			num[i].price[0]=0;
		}
		for(int i=1;i<=m;i++){
			int a;
			string str;
			scanf("%d%s",&a,str);
			num[search(1,n,str)].price[i]=num[search(1,n,str)].price[i-1]+a;
			//int* day;
			//day=&i;
			//sort(num+1,num+1+n,cmp2);
			int mem=search(1,n,'memory');
			int rank=1;
			for(int j=1;j<=n;j++){
				if(num[j].price[i]>num[mem].price[i]){
					rank++;
				}
			}
			printf("%d\n",rank);
		}
	}
	return 0;
} 
