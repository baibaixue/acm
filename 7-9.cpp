#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include <functional>
using namespace std;
struct q{
	long long int x[10020];
	int t;//ÿ���������Ԫ�ظ��� 
}num[55];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i].t); 
			for(int j=0;j<num[i].t;j++){
				scanf("%lld",&num[i].x[j]);//��ȡÿ�����������Ԫ�� 
			}
			sort(num[i].x,num[i].x+num[i].t);//���� 
		}
		int k;
		scanf("%d",&k);//k�β�ѯ 
		for(int i=0;i<k;i++){
			int a,b;
			scanf("%d%d",&a,&b);//Ҫ��ѯ���������ϵ���� 
			int c=0,t=0;
			sort(num[a].x,num[a].x+num[a].t);
			sort(num[b].x,num[b].x+num[b].t);
			if(num[a].t==1){
				t++;
			}else if(num[a].t>1){
				for(int i=0;i<num[a].t;i++){
					if(num[a].x[i]!=num[a].x[i+1]){
						t++;
					}
				}
			}
			if(num[b].t==1){
				t++;
			}else if(num[a].t>1){
				for(int i=0;i<num[b].t;i++){
					if(num[b].x[i]!=num[b].x[i+1]){
						t++;
					}
				}
			}
			//t=unique(num[a].x,num[a].x+num[a].t)-num[a].x+unique(num[b].x,num[b].x+num[b].t)-num[b].x;
			//a,b���ϸ��Բ��ظ���Ԫ��֮�� 
			cout<<"t="<<t<<endl; 
			if(binary_search(num[b].x,num[b].x+num[b].t,num[a].x[0]))
			c++;//��һ��Ԫ���Ƿ��ڽ����� 
			for(int i=1;i<num[a].t;i++){
				if(binary_search(num[b].x,num[b].x+num[b].t,num[a].x[i])&&num[a].x[i]!=num[a].x[i-1]){
					c++;//�ӵڶ���Ԫ�ؿ�ʼ���Һ�ǰһ��Ԫ�ز����ʱ���ж��Ƿ��ڽ����� 
				}
			}
			t=t-c;//t-����Ԫ�ظ���Ϊ����Ԫ�ظ��� 
			cout<<"c="<<c<<endl;
			cout<<"t="<<t<<endl;
			double ans=c*1.0/t*100;//���������� 
			printf("%.2f%\n",ans);
		}
		return 0;
	}
}

