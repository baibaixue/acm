#include <stdio.h>
int main() 
{
	const  int size=3;
	int board[size][size];
	int playerx;
	int playero;
	int i,j;
	int result =-1;//-1 ����Ӯ��1 playerxӮ�� 0 playeroӮ��
	//�������  
	for (i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%d",&board[i][j]);
		}
	}
	//�����
	for (i=0;i<size&&result==-1;i++){
	 	playero=playerx=0;
	 	for (j=0;j<size;j++){
	 		if(board[i][j]==1){
	 			playerx++;
			 }else{
			 	playero++;
			 }
		 }
	 if(playerx=size){
	 	result=1;
	 }else if(playero=size){
	 	result=0;
	 }
	 } 
	//�����
	if (result=-1){
		for (j=0;j<size&&result==-1;j++){
		playero=playerx=0;
		for (i=0;i<size;i++){
			if(board[i][j]==1){
				playerx++;
			}else{
				playero++;
			}
		}
	 
	if(playerx=size){
		result=1;
	}else if(playero=size){
		result=0;
		}
	}
}
	//���Խ���
	if(result=-1){
		playero=playerx=0;
		for(i=0;i<size;i++){
			if(board[i][i]==1){
				playerx++;
			}else {
				playero++;
			}
		}
		if(playerx=size){
		result=1;
	}else if(playero=size){
		result=0;
		}
	}
	
	if(result=-1){
		playero=playerx=0;
		for(i=0;i<size;i++){
			if(board[i][size-i-1]==1){
				playerx++;
			}else {
				playero++;
			}
		}
		if(playerx=size){
		result=1;
	}else if(playero=size){
		result=0;
		}
	}
	if(result==-1){
		printf("����Ӯ��");
	}else if(result==1){
		printf("x���Ӯ��");
	}else{
		printf("o���Ӯ��");
		
	}
	return 0;
}
