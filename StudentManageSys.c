#include<stdio.h>
#include<stdlib.h>
#include"StudentManageSys.h"
#include<string.h>
#include<conio.h>
#include<windows.h>
void Initialize(){
	StudentList.front = (struct Node*)malloc(sizeof(struct Node));
	StudentList.rear = (struct Node*)malloc(sizeof(struct Node));
    StudentList.front-> next = StudentList.rear;
    StudentList.rear -> next = NULL;
    StudentList.currPtr = NULL;
    StudentList.size = 0;
}

int Isempty(){
        if(StudentList.front == NULL) return 1;
        else return 0;
}
void Insert(struct Student stu){
        struct Node *newnode;
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode==NULL){
                printf("����ռ�ʧ�ܣ�\n");
                exit(1);
        }else{
                StudentList.size += 1;
                strcpy(newnode->data.sno,stu.sno);
                strcpy(newnode->data.sname,stu.sname);
                strcpy(newnode->data.sclass,stu.sclass);
                newnode->data.sage = stu.sage;

                if(StudentList.size == 1){
                        StudentList.front = newnode;
                        newnode->next = StudentList.rear;
                }else{
                        StudentList.currPtr = StudentList.front;
                        while(StudentList.currPtr->next != StudentList.rear){
                                StudentList.currPtr = StudentList.currPtr->next;
                        }
                        newnode->next = StudentList.currPtr->next;
                        StudentList.currPtr->next = newnode;
                }
        }
}
int Delete (char *Sno){
    struct Node *student = Search(Sno);
    if(student == NULL){
        printf("�Ҳ�����ѧ����\n");
        return 0;
    }else{
            StudentList.currPtr = StudentList.front;
            if(StudentList.currPtr == student){
            	StudentList.front = StudentList.front->next;
			}else{
				while(StudentList.currPtr->next != student){
                    StudentList.currPtr = StudentList.currPtr->next;
            	}
            	StudentList.currPtr->next = student->next;
			}
            free(student);
            return 1;
    }
}

struct Node* Search(char *Sno){
    if(Isempty()) return NULL;
    else{
        StudentList.currPtr = StudentList.front;
        while(StudentList.currPtr != StudentList.rear){
            if(strcmp(StudentList.currPtr->data.sno,Sno)==0){
                    return StudentList.currPtr;
            }
            StudentList.currPtr = StudentList.currPtr->next;
        }
        return NULL;
    }
}

int Modify(char *Sno,struct Student stu){
        struct Node *student = Search(Sno);
        if(student == NULL){
                return 0;
        }else{
                strcpy(student->data.sno,stu.sno);
                strcpy(student->data.sname,stu.sname);
                strcpy(student->data.sclass,stu.sclass);
                student->data.sage = stu.sage;
                return 1;
        }
} 
void Print(){
        StudentList.currPtr = StudentList.front;
        while(StudentList.currPtr != StudentList.rear){
                printf("ѧ�ţ�%s\t������%s\t���䣺%d\t�༶��%s\n",
                                StudentList.currPtr->data.sno,
                                StudentList.currPtr->data.sname,
                                StudentList.currPtr->data.sage,
                                StudentList.currPtr->data.sclass);
                StudentList.currPtr = StudentList.currPtr->next;
        }
}

void Menu(){

        CLEAR();
        HIDE_CURSOR();

         printf("\t\tѧ������ϵͳ\n");
         printf("\t 1\t-----����ѧ����Ϣ\n");
         printf("\t 2\t-----�޸�ѧ����Ϣ\n");
         printf("\t 3\t-----ɾ��ѧ����Ϣ\n");
         printf("\t 4\t-----����ѧ����Ϣ\n");
         printf("\t 5\t-----ѧ����Ϣ����\n");
         printf("\t 6\t-----��ӡѧ����Ϣ\n");
         printf("\t 7\t-----�˳�ϵͳ\n");

		char ch;
		while(1){
			if(kbhit()){
				ch = getch();
				if(ch == '1'){
                 _1Insert();
         		}else if(ch == '2'){
                 _2Modify();
        		}else if(ch == '3'){
                 _3Delete();
         		}else if(ch == '4'){
                 _4Search();
         		}else if(ch == '5'){
                 _5Sort();
         		}else if(ch == '6'){
                 _6Print();
         		}else if(ch == '7'){
                 exit(0);
         }
			}
		}
         
}
void _1Insert(){
        CLEAR();
        Show_CURSOR();
        char sno[9] ; 
        char sname[11] ;
        char sclass[9];
        unsigned int sage;
        printf("����ѧ����Ϣ\n");
        printf("�����ʽ��ѧ��(8λ) ���� ���� �༶(8λ)(ÿ������֮���Կո����>������0����)\n");
        printf("������ѧ����Ϣ��");
        while(scanf("%s",&sno)){
        		if(strlen(sno) == 1 && sno[0] == '0'){
        			break;
				}
                scanf("%s %d %s",&sname,&sage,&sclass);
                struct Student student;
                strcpy(student.sname,sname);
                strcpy(student.sno,sno);
                strcpy(student.sclass,sclass);
                student.sage = sage;
                Insert(student);
                printf("����ɹ���\n");
                printf("������ѧ����Ϣ��");
        }
        Menu();
}
void _2Modify(){
        CLEAR();
        Show_CURSOR();
        printf("�޸�ѧ����Ϣ\n");
        printf("������Ҫ�޸ĵ�ѧ��ѧ��(����0����)��");
        char fsno[9];
        char esno[9];
        char sname[11];
        char sclass[9];
        unsigned int sage;
        while(scanf("%s",&fsno)){
        		if(strlen(fsno) == 1 && fsno[0] == '0') break;
                struct Node *student = Search(fsno);
                if(student == NULL){
                        printf("�Ҳ�����ѧ����Ϣ��\n");
                        printf("������Ҫ�޸ĵ�ѧ��ѧ��(����0����)��");
                        continue;
                }
                printf("������Ҫ�޸ĺ��ѧ����Ϣ��");
                scanf("%s",&esno);
                if(strlen(esno) == 1 && esno[0] == '0') break;
				else {
                        scanf("%s %d %s",&sname,&sage,&sclass);
                        struct Student stu;
                        strcpy(stu.sno,esno);
                        strcpy(stu.sname,sname);
                        strcpy(stu.sclass,sclass);
                        stu.sage = sage;
                        if(Modify(fsno,stu)){
                                printf("�޸���ɣ�\n");
                                printf("������Ҫ�޸ĵ�ѧ��ѧ��(����0����)��");
                        }
                }
        }
        Menu();
}
void _3Delete(){
    CLEAR();
    Show_CURSOR();
    printf("ɾ��ѧ����Ϣ\n");
    printf("������Ҫɾ����ѧ��ѧ��(����0����):");
    char sno[9];
    while(scanf("%s",&sno)){
    		if(strlen(sno) == 1 && sno[0] == '0'){
        			break;
				}
            if(Delete(sno)==1){
                    printf("ɾ���ɹ�!\n");
            }printf("������Ҫɾ����ѧ��ѧ��(����0����):");
    }
    Menu();
}
void _4Search(){
        CLEAR();
        Show_CURSOR();
        printf("����ѧ����Ϣ\n");
        printf("������Ҫ���ҵ�ѧ����ѧ��(����0����)��");
        char sno[9];
        while(scanf("%s",&sno)){
        		if(strlen(sno) == 1 && sno[0] == '0'){
        			break;
				}
                struct Node* student ;
                student = Search(sno);
                if(student == NULL){
                        printf("�Ҳ�����ѧ����\n");
                        printf("������Ҫ���ҵ�ѧ����ѧ��(����0����)��");
                }else{
                        printf("ѧ�ţ�%s ������%s ���䣺%d �༶��%s\n",student->data.sno,student->data.sname,student->data.sage,student->data.sclass);
                        printf("������Ҫ���ҵ�ѧ����ѧ��(����0����)��");
                }
        }
        Menu();
}
void swap(struct Student *a, struct Student *b){
	struct Student temp;
	strcpy(temp.sclass,b->sclass);
	strcpy(temp.sname,b->sname);
	strcpy(temp.sno,b->sno);
	temp.sage = b->sage;
	
	strcpy(b->sclass,a->sclass);
	strcpy(b->sname,a->sname);
	strcpy(b->sno,a->sno);
	b->sage = a->sage;
	
	strcpy(a->sclass,temp.sclass);
	strcpy(a->sname,temp.sname);
	strcpy(a->sno,temp.sno);
	a->sage = temp.sage; 
}

void Sort(struct Node* start,struct Node* end){
	if(start == NULL || start  == end) return ;
	struct Node* p1 = start;
	struct Node* p2 = start->next;
	
	while(p2 != end){      
	if(strcmp(p2->data.sno,start->data.sno) < 0){
			p1 = p1->next;
			swap(&(p1->data),&(p2->data));
		}
		p2 = p2->next;
	}
	swap(&(p1->data),&(start->data));
	
	Sort(start,p1);
	Sort(p1->next,end);
}

void _5Sort(){
	Sort(StudentList.front,StudentList.rear);
	printf("������ɣ�");
}
void _6Print(){
        CLEAR();
        HIDE_CURSOR();
        Print();
        printf("����0����...");
        char ch;
        while(1){
        	if(kbhit())
        		ch = getch();
                if(ch == '0') Menu();
        }
}

int main(){
        Initialize();
        Menu();

}

