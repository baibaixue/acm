#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct student{
	char name[10];
	int r;
}boy[30],girl[30];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
			int k;
			int b=1,g=1;
			int rank=1;
			int num=n;
		while(num--){
			//char names[10];
			//memset(names,0,sizeof(names));
			scanf("%d%*c",&k);
			if(k==0){
				//scanf("%s",names);
				scanf("%s",girl[g].name);
				//strcpy(names,girl[g].name);
				//cout<<girl[g].name;
				girl[g].r=rank++;
				g++;
			}else{
				scanf("%s",boy[b].name);
			//cout<<boy[b].name;
				//scanf("%s",s);
				//strcpy(names,boy[b].name);
				boy[b].r=rank++;
				b++;
			}
		}
		g=1,b=1;
		int g1=n/2,b1=n/2;
		for(int i=1;i<=n/2;i++){
			if(girl[g].r==i){
				cout<<girl[g].name<<" ";
				cout<<boy[b1].name<<"\n";
				g++;
				b1--;
			}
			if(boy[b].r==i){
				cout<<boy[b].name<<" ";
				cout<<girl[g1].name<<"\n";
				b++;
				g1--;
			}
		}
	}
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int n;
//    int i, j;
//    int sex[50];
//    char name[50][20];
//    int arr[50] = {0};
//
//    scanf("%d", &n);
//
//    if(n < 0 || n > 50)
//        exit(0);
//
//    for(i = 0; i < n; i++)
//    {
//        scanf("%d", &sex[i]);
//        scanf("%s", name[i]);
//    }
//
//    for(i = 0; i < n; i++)//从左边遍历
//    {
//        for(j = n-1; j >= 0; j--)//从右边找最靠右的、复合标准的人
//        {
//            if(arr[i] == 0 && arr[j] == 0 && sex[i] != sex[j])//找出符合条件的人，没被输出过，并且性别不同
//            {
//                printf("%s %s\n", name[i], name[j]);
//                arr[i] = 1;
//                arr[j] = 1;
//            }
//        }
//    }
//
//    return 0;
//}
