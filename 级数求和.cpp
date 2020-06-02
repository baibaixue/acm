#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int k;
	scanf("%d",&k);
	double sum=0;
	int ans;
	for(int i=1;;i++){
		sum+=1.0/i;
		if(sum>k){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
