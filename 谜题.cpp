#include<stdio.h>
int main(){
	char a[5][5]={{'T','R','G','S','J'},{'X','D','O','K','I'},{'M',' ','V','L','M'},{'W','P','A','B','E'},{'U','Q','H','C','F'}};
		for(int i1=0;i1<5;i1++){
			for(int i2=0;i2<5;i2++){
				printf("%c ",a[i1][i2]);
			}
			printf("\n");
		}
		int i=10;
	while(i--){
		char c,t;
		int x=2,y=1;
		do{
			scanf("%c",&c);
			if(c!='0'){
				switch(c){
					case 'A':if(x-1>=0){t=a[x][y];a[x][y]=a[x-1][y];a[x-1][y]=t;x--;	break;	}else {printf("This puzzle has no final configuration.\n");	break;	}
					case 'B':if(x+1<5){t=a[x][y];a[x][y]=a[x+1][y];a[x+1][y]=t;x++;	break;	}else {printf("This puzzle has no final configuration.\n");	break;	}
					case 'R':if(y+1<5){t=a[x][y];a[x][y]=a[x][y+1];a[x][y+1]=t;y++;	break;	}else {printf("This puzzle has no final configuration.\n");	break;	}
					case 'L':if(y-1>=0){t=a[x][y];a[x][y]=a[x][y-1];a[x][y-1]=t;y--;	break;	}else {printf("This puzzle has no final configuration.\n");	break;	}
				}
			}
		}while(c!='0');
		for(int i1=0;i1<5;i1++){
			for(int i2=0;i2<5;i2++){
				printf("%c ",a[i1][i2]);
			}
			printf("\n");
		}
	}
	return 0;
} 
