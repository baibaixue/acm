#include<iostream>//�߾��ȼӷ�
#include<cstring>
#define MAX 1004
using namespace std;
int main(){
	int a_length,b_length;//a,b�ĳ���
	int len,x,t=0;//len��sum���鳤�ȣ�x�ǽ�λ
	int i[MAX],j[MAX];//ת�����������
	char a[MAX],b[MAX];//Ϊ�˺�����ѽ
	int sum[MAX];//��ӽ������
	int testnumber;//�м����������
	cin>>testnumber;
	for(int p=1;p<=testnumber;p++){
		memset(i,0,sizeof(i));
		memset(j,0,sizeof(j));
		memset(sum,0,sizeof(sum));
	//	memset(a,0,sizeof(a));
	//	memset(b,0,sizeof(b));
		if(t>0) cout<<endl;
		cin>>a; cin>>b;
		a_length=strlen(a);
		b_length=strlen(b);
		
		for(int k=0;k<a_length;k++)
			i[a_length-k]=a[k]-48;
		for(int k=0;k<b_length;k++)
			j[b_length-k]=b[k]-48;
	
		len=0;
		x=0;
		
		while(len<=a_length||len<=b_length){
			sum[len]=i[len]+j[len]+x;
			x=sum[len]/10;
			sum[len]=sum[len]%10;
			len++;
		}
		
		sum[len]=x;
		if(x==0) len--;
		if(sum[len]) t++;	
		cout<<"Case "<<p<<":"<<endl;
		for(int jj=0;jj<a_length;jj++) cout<<a[jj];
		cout<<" "<<"+"<<" ";
		for(int jj=0;jj<b_length;jj++) cout<<b[jj];
		cout<<" "<<"="<<" ";
		for(int jj=len;jj>0;jj--) cout<<sum[jj];
		cout<<endl;
	}
	return 0;
 
}
