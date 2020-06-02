#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
struct people{
	int id;
	char num[105];
	bool operator >(const people& b){
		int lena=strlen(num);
		int lenb=strlen(b.num);
		if(lena!=lenb){
			//printf("%d %d\n",strlen(num),strlen(b.num));
			return lena>lenb;
		}
		for(int i=0;i<=lena;i++){
			//printf("num[%d]=%c\n",i,num[i]);
			//printf("b.num[%d]=%c\n",i,b.num[i]);
			if(num[i]-'0'>b.num[i]-'0'){
				return true;
			}
		}
		return false;
	}
}N[25];
//	bool operator >(struct people& a,struct people b){
//		if(strlen(a.num)>strlen(b.num)){
//			//printf("%d %d\n",strlen(a.num),strlen(b.num));
//			return true;
//		}else{
//			for(int i=0;i<strlen(a.num);i++){
//				//printf("a.num[%d]=%c\n",i,a.num[i]);
//				//printf("b.num[%d]=%c\n",i,b.num[i]);
//				if(a.num[i]-'0'>b.num[i]-'0'){
//					return true;
//				}
//			}
//		}
//		return false;
//	}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	int x=1;
	for(int i=1;i<=n;i++){
		N[i].id=i;
		scanf("%s",N[i].num);
		if(N[i]>N[x]){
			x=i;
		}
	}
	printf("%d\n",N[x].id);
	cout<<N[x].num;
	return 0;
}
