#include<stdio.h>//�����//2018������ 
#define max 100020
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		long long int x[max];
		scanf("%d",&x[0]);
		for(int i=1;i<n;i++){
			scanf("%lld",&x[i]);
			x[i]=x[i]+x[i-1];
		}
		long long int c;
		while(m--){
			scanf("%lld",&c);
			if(x[n-1]<c){
				printf("%d\n",n);
				}
			else{
				int a=0,b=n-1;
				while(a<b){//���ַ� 
					v=a+(b-a)/2;
					if(x[v]==c){
						printf("%d\n",v);
						break;
					}
					else if(x[v]>c){
						b=v;
					}
					else{
						a=v+1;
					}
					//v+1=lower_bound(x,x+n,c)-x-1//��x����ĵ�һ��λ�õ���n��λ�ö��ַ���
					// ��һ������c���������ظ����ĵ�ַ�� 
					//�����ڷ������һ�����ĵ�ַ���صĵ�ַ��ȥ��ʼ��ַΪ�����±� 
					if(x[v]<c&&x[v+1]>=c){
						printf("%d\n",v+1);
						break;
					}
				}
			}
		}
	}
	return 0;
}
