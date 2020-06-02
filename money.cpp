#include <stdio.h>

int main()
{
	int x;
	printf("您的目的金额：");
	scanf("%d",&x);
	//int exit=0;
	int one,two,five;
	for(one=0;one<=10*x;one++){
		for(two=0;two<=x*10/2;two++){
			for(five=0;five<=x*10/5;five++){
				if(one+two*2+five*5==x*10){
					printf("%d个一角钱和%d个二角钱和%d个五角钱共%d元\n",one,two,five);
					//exit=1;
					//break;
					goto out;
					
				}
			}//if(exit) break;
		}//if(exit) break;
		
	}
	out:
	return 0;
}
