#include<cstdio>
using namespace std;
double num[15];
int f(int n){
	int ans=1;
	while(n!=0){
		ans*=n;
		n--;
	}
	return ans;
}
int main(){
	num[0]=1;
	for(int i=1;i<=9;i++){
		num[i]=num[i-1]+1.0/f(i);
	}
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(int i=3;i<=9;i++){
		printf("%d %.9lf\n",i,num[i]);
	}
}
