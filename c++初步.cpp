#include<iostream>//��������� 
#include<algorithm> //�����㷨�⣬��min 
using namespace std;//�����ֺ���������std�ռ��У��þ�Ѻ�������Ĭ�Ͽռ乩����ʹ�� 
const int maxn=100+10;
int A[maxn];
void swap2(int& a,int& b){
	int t=a;a=b;b=t;
}
int main(){
	int a,b;
	while(/*std::*/cin>>a>>b){//����������������a,b��ֵ 
		/*std::*/cout<</*std::*/min(a,b)<<"\n";//����������a,b�е���Сֵ�ͻس� 
		swap2(a,b);
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
} 
