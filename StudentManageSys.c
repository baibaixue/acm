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
                printf("分配空间失败！\n");
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
        printf("找不到此学生！\n");
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
                printf("学号：%s\t姓名：%s\t年龄：%d\t班级：%s\n",
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

         printf("\t\t学生管理系统\n");
         printf("\t 1\t-----插入学生信息\n");
         printf("\t 2\t-----修改学生信息\n");
         printf("\t 3\t-----删除学生信息\n");
         printf("\t 4\t-----查找学生信息\n");
         printf("\t 5\t-----学生信息排序\n");
         printf("\t 6\t-----打印学生信息\n");
         printf("\t 7\t-----退出系统\n");

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
        printf("插入学生信息\n");
        printf("输入格式：学号(8位) 姓名 年龄 班级(8位)(每个数据之间以空格隔开>，输入0返回)\n");
        printf("请输入学生信息：");
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
                printf("插入成功！\n");
                printf("请输入学生信息：");
        }
        Menu();
}
void _2Modify(){
        CLEAR();
        Show_CURSOR();
        printf("修改学生信息\n");
        printf("输入需要修改的学生学号(输入0返回)：");
        char fsno[9];
        char esno[9];
        char sname[11];
        char sclass[9];
        unsigned int sage;
        while(scanf("%s",&fsno)){
        		if(strlen(fsno) == 1 && fsno[0] == '0') break;
                struct Node *student = Search(fsno);
                if(student == NULL){
                        printf("找不到此学生信息！\n");
                        printf("输入需要修改的学生学号(输入0返回)：");
                        continue;
                }
                printf("输入需要修改后的学生信息：");
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
                                printf("修改完成！\n");
                                printf("输入需要修改的学生学号(输入0返回)：");
                        }
                }
        }
        Menu();
}
void _3Delete(){
    CLEAR();
    Show_CURSOR();
    printf("删除学生信息\n");
    printf("输入需要删除的学生学号(输入0返回):");
    char sno[9];
    while(scanf("%s",&sno)){
    		if(strlen(sno) == 1 && sno[0] == '0'){
        			break;
				}
            if(Delete(sno)==1){
                    printf("删除成功!\n");
            }printf("输入需要删除的学生学号(输入0返回):");
    }
    Menu();
}
void _4Search(){
        CLEAR();
        Show_CURSOR();
        printf("查找学生信息\n");
        printf("输入需要查找的学生的学号(输入0返回)：");
        char sno[9];
        while(scanf("%s",&sno)){
        		if(strlen(sno) == 1 && sno[0] == '0'){
        			break;
				}
                struct Node* student ;
                student = Search(sno);
                if(student == NULL){
                        printf("找不到此学生！\n");
                        printf("输入需要查找的学生的学号(输入0返回)：");
                }else{
                        printf("学号：%s 姓名：%s 年龄：%d 班级：%s\n",student->data.sno,student->data.sname,student->data.sage,student->data.sclass);
                        printf("输入需要查找的学生的学号(输入0返回)：");
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
	printf("排序完成！");
}
void _6Print(){
        CLEAR();
        HIDE_CURSOR();
        Print();
        printf("按下0返回...");
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

