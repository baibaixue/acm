#include <stdio.h>

int main()
{
	// ��ʼ��
	int prince;
	int bill;
	// ��ȡ����Ʊ�� 
	printf("�������");
	scanf("%d",&prince);
	printf("������Ʊ�棺");
	scanf("%d",&bill);
	//��������
	if (bill>=prince){
		printf("Ӧ��������%d\n",bill-prince);
	} else{
		printf("���Ǯ������\n");
	}
}
