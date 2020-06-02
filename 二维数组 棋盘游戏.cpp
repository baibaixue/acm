#include <stdio.h>
int main() 
{
	const  int size=3;
	int board[size][size];
	int playerx;
	int playero;
	int i,j;
	int result =-1;//-1 无人赢，1 playerx赢， 0 playero赢。
	//读入矩阵  
	for (i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%d",&board[i][j]);
		}
	}
	//检查行
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
	//检查列
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
	//检查对角线
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
		printf("无人赢，");
	}else if(result==1){
		printf("x玩家赢。");
	}else{
		printf("o玩家赢。");
		
	}
	return 0;
}
