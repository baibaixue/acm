//��ȫ����
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 10000
#define inf 0x3f3f3f3f
using namespace std;
int val[maxn];//��ֵ 
int wei[maxn];//����
int dp[maxn]; 
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		//ע���ʼ����Ҫ��ǡ��װ����������ô�ڳ�ʼ��ʱ����f[0]Ϊ0����f[1..V]����Ϊ-�ޡ�
		//�������ܹ���֤���ڵõ���dp[N]��һ��ǡ��װ�����������Ž⡣
		//�����û��Ҫ�����ѱ���װ�������ǽ���ϣ���۸����󣬳�ʼ��ʱӦ�ý�f[0..V]������Ϊ0��
		for(int i=0;i<m;i++){
			dp[i]=-inf;
		}
		dp[0]=0;
		for(int i=0;i<n;i++){
			for(int j=wei[i];j<=m;j++){
				dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
}
