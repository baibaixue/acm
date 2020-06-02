#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1000+10
using namespace std;
int c[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>c[i];
		}
		sort(c,c+n);
		cout<<c[0];
		for(int i=1;i<n;i++){
			cout<<" "<<c[i];
		}
		cout<<"\n";
	} 
	return 0;
}
