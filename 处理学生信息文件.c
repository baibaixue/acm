#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
	char num[100];
	int A,B,C;
	char s[100];
}stu[100];
void name_sort(struct student *stu,int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(strcmp(stu[j].s,stu[j+1].s)>0){
				temp=stu[j+1];
				stu[j+1]=stu[j];
				stu[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%s %s %d %d %d\n",stu[i].s,stu[i].num,stu[i].A,stu[i].B,stu[i].C);
	}
}
int main(){
	//printf("Haos 170820 87 87 78\nLili 170101 80 90 85\nMinGW 170107 90 78 95\nMingh 178008 80 90 100\nSunj 170117 87 78 80\nZhaoq 170103 65 78 65\n");
	int len=0;
	while(scanf("%s",stu[len].s)!=EOF){
		getchar();
		scanf("%s",stu[len].num);
		scanf("%d%d%d",&stu[len].A,&stu[len].B,&stu[len].C);
		getchar();
		len++;
	}
	name_sort(stu,len);
	return 0;
}
