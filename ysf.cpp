#include<cstdio>
#include<iostream>
using namespace std;
/*ԭ�汾*/ 
int ysf(int n,int m){//n��������m��ÿ��m���˱�һ���� 
	int f=0;
	for(int i=0;i<n;i++){
		f=(f+m)%(i+1); 
	}
	return f+1;
} 
/*�Ż��汾*/
int Ysf(int n,int m){
	if(m<n){
		int res=Ysf(n-n/m,m);
		if(res<n%m){
			res=res+n-n%m;
		}else{
			res=res+(res-n%m)/(m-1)+m*(int)(n/m)-n;
		}
		return res;
	}else{
		return ysf(n,m);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",Ysf(n,m));
} 
