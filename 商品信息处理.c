#include<stdio.h>

#include<stdlib.h>

struct book

{

	char name[1000];

	float price;

	struct book *next;

 } ;

void print(struct book *head)

 {

 	struct book *p=head;

 	while(p!=NULL){

 		printf("%s %.2f\n",p->name,p->price);

 		p=p->next;

	 }

 }

struct book *insert(struct book *head)

 {

 	struct book *p,*pnew,*pold;

 	pnew=(struct book *)malloc(sizeof(struct book));

 	scanf("%s%f",pnew->name,&pnew->price);

 	p=head;if(pnew->price<head->price){

 		pnew->next=head;

		 head=pnew;

	 }

	 else{ 

	 while(p!=NULL&&pnew->price>p->price)

	 pold=p;

	 p=p->next=pnew;

	 }

	return head;

 }

 int main()

 {

 	struct book *insert(struct book *head);

 	void print(struct book *head);

 	struct book *head;

 	int i=1,c;

	head=(struct book *)malloc(sizeof(struct book));

	scanf("%s%f",head->name,&head->price);

	head->next=NULL;

	while(scanf("%s%f",head->name,&head->price)!=EOF)

	{i++;

	head=insert(head);}

	print(head);

	return 0;

 }
