#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(0));
	int number=rand()%100+1;
	int count=1;
	int a;
	printf("�������һ��100���ڵ������������°ɣ�\n");
	scanf("%d",&a);
	while (a!=number){
		if (a>number){
			printf("���µ������ˡ�\n");
		}
		else{
			printf("���µ���С�ˡ�\n");
		}
		count++;
		scanf("%d",&a);
	}
	printf("��ϲ���µ�����������������%d����������%d�Ρ�\n",number,count);
	return 0;
}
