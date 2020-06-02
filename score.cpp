#include <stdio.h>

int main()
{
	const int pass=60;
	int score;
	
	printf("请输入你的成绩：");
	scanf("%d",&score);
	printf("您的成绩是%d。\n",score);
	if (score>pass)
		printf("祝贺你，这个成绩及格了。\n");
	else
		printf("很遗憾，这个成绩没有及格。\n");
		
	printf("再见。");
	
	return 0; 
}
