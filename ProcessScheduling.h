//ProcessScheduling.h
#ifndef _PROCESSSCHEDULING_H
#define _PROCESSSCHEDULING_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Free 0 
#define ready 1
#define running 2
#define ts 2 /*time slice*/
#define PCBnum 6 /*PCB number*/

struct  PCB{
        int pid;    /*����ID*/
        int pstate; /*����״̬*/
        char *pname;/*ӳ������*/
        int ptime;  /*ʣ������ʱ��*/    
};

struct Node{
        struct PCB data;
        struct Node *next;/*��һ��PCB*/
        struct Node *pre;
};

struct LinkedList{
        struct Node *front;
        struct Node *rear;
        struct Node *currPtr;
        unsigned int size;
};

struct LinkedList freeQueue;    /*�հ�PCB����*/
struct LinkedList readyQueue;   /*��������*/
struct LinkedList runningQueue; /*ִ�ж���*/

void Initialize(struct LinkedList*);         /*��ʼ������*/
void Initialize_free(void);                 /*��ʼ���հ�PCB���м�PCB*/
int Isempty(struct LinkedList);             /*�ж϶����Ƿ�Ϊ��*/
void Insert(struct PCB ,struct LinkedList*); /*�����в�����PCB*/

void Free2Ready(int);      /*�ӿհ׶���ȡ��PCB�����������,ͬʱȷ����������Ҫ��ִ��ʱ��*/
void Ready2Running(void);  /*�Ӿ�������ȡ��PCB����ִ�ж���*/
void Running2Ready(void);  /*��ִ�ж���ȡ��PCB�����������*/
void Running2Free(void);   /*��ִ�ж���ȡ��PCB����հ׶���*/

void Start(void);
void Sched(void);

void Destroy(struct LinkedList*);            /*���ٶ���*/


#endif

