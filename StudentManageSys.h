#ifndef _STUDENTMANAGESYS_H
#define _STUDENTMANAGESYS_H
#include<stdio.h>
#include<stdlib.h>
#define CLEAR() printf("\033[2J")
#define HIDE_CURSOR() printf("\033[?25l")
#define Show_CURSOR() printf("\033[?25h")

struct  Student{
        char sno[9];
        char sname[11];
        unsigned int sage;
        char sclass[9];
};

struct Node{
        struct Student data;
        struct Node *next;
};

struct LinkedList{
        struct Node *front;
        struct Node *rear;
        struct Node *currPtr;
        unsigned int size;
}StudentList; 

void Initialize(void);
int Isempty(void);
void Insert(struct Student);
int Delete(char*);
struct Node* Search(char*);
int Modify(char* , struct Student);
void Print(void);
void Sort(struct Node* ,struct Node*);

void Menu(void);
void _1Insert(void);
void _2Modify(void);
void _3Delete(void);
void _4Search(void);
void _5Sort(void);
void _6Print(void);

#endif

