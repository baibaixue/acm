#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2058;
long long last[maxn],dp[2][maxn],a[maxn],b[maxn];
int main(){
	int n,k,j;
	while(scanf("%d%d",&n,&k)==2){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			b[i]=(a[i]-a[i-1])*(a[i]-a[i-1]);//��ֵ 
		}
		memset(last,0,sizeof(last));
		for(int i=1;i<=k;i++){//k�ΰ��˼���b[i]��ȡk�� 
			for(int j=2*i-1;j<n;j++){//��ʣ�µ���Ʒ
				dp[1][j]=last[j-1]+b[j];//1Ϊȡ��һ����ֵ 
				if(j==2*i-1){// ��ʼ���������ͬ 
					dp[0][j]=dp[1][j];
				}
				else{//�ҳ����벻�������������Сֵ ����1 
					if(dp[0][j-1]<dp[1][j-1]){
						dp[0][j]=dp[0][j-1];
					}
					else{
						dp[0][j]=dp[1][j-1];
					}
				}
			}
			for(int j=2*i-1;j<n;j++){
				last[j]=dp[0][j];//������ѭ����������Сֵ����last 
			}
		}
		long long max=dp[1][k*2-1];//��ʣ��k*2-1��������������ֵ 
		for(int i=k*2;i<n;i++){//������k�κ�ʣ�����Ʒֻ�п�����2*k-1 
			if(dp[1][i]<max){//��n֮�䣨֮ǰδ�õ���Ʒֱ�������� 
				max=dp[1][i];//���ֵΪ����k*2����Ʒ����Сֵ 
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}
