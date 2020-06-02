#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int idex[15];
int x[10]={0,0,0,0,0,0,0,0,0,0};
int arr[10];
int num[15];
int main(){
	while(scanf("%1d",&num[0])!=EOF){
		for(int i=1;i<11;i++){
			scanf("%1d",&num[i]);
		}
		for(int i=0;i<11;i++){
			int c=num[i];
			x[c]=1;
		}
		int a=0;
		for(int i=9;i>=0;i--){
			if(x[i]==1){
				arr[a++]=i;
			}
		}
		int b=0;
		for(int i=0;i<11;i++){
			for(int j=0;j<a;j++){
				if(num[i]==arr[j]){
					idex[b++]=j;
				}
			}
		}
		printf("int[] arr = new int[]{");
		for(int i=0;i<a-1;i++){
			printf("%d,",arr[i]);
		}
		printf("%d};\n",arr[a-1]);
		printf("int[] index = new int[]{");
		for(int i=0;i<b-1;i++){
			printf("%d,",idex[i]);
		}
		printf("%d};\n",idex[b-1]);
	}
	return 0;
}
