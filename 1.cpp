#include<stdio.h>
int GRID_SIZE = 6;
int grid[10][10];
int main(){
	
	for(int r=0;r<GRID_SIZE;++r){
		for(int c=0;c<GRID_SIZE;++c){
			grid[r][c]=1;
		//	if(r==0) grid[r][c]=0;
		//	if(c==0) grid[r][c]=0;
		//	if(r==GRID_SIZE-1) grid[r][c]=0;
		//	if(c==GRID_SIZE-1) grid[r][c]=0;
		}
	}
	for(int i=0;i<GRID_SIZE;++i){
		grid[i][0]=0;
		grid[i][GRID_SIZE-1]=0;
		grid[0][i]=0;
		grid[GRID_SIZE-1][i]=0;
	}
	
	for(int r=0;r<GRID_SIZE;++r){
		for(int c=0;c<GRID_SIZE;++c ){
			printf("%d ",grid[r][c]);
		}
		printf("\n");
	}
	return 0;
}
