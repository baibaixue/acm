#include <stdio.h>

int main()
{
	const int pass=60;
	int score;
	
	printf("��������ĳɼ���");
	scanf("%d",&score);
	printf("���ĳɼ���%d��\n",score);
	if (score>pass)
		printf("ף���㣬����ɼ������ˡ�\n");
	else
		printf("���ź�������ɼ�û�м���\n");
		
	printf("�ټ���");
	
	return 0; 
}
