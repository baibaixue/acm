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
        int pid;    /*进程ID*/
        int pstate; /*进程状态*/
        char *pname;/*映像名称*/
        int ptime;  /*剩余运行时间*/    
};

struct Node{
        struct PCB data;
        struct Node *next;/*下一个PCB*/
        struct Node *pre;
};

struct LinkedList{
        struct Node *front;
        struct Node *rear;
        struct Node *currPtr;
        unsigned int size;
};

struct LinkedList freeQueue;    /*空白PCB队列*/
struct LinkedList readyQueue;   /*就绪队列*/
struct LinkedList runningQueue; /*执行队列*/

void Initialize(struct LinkedList*);         /*初始化链表*/
void Initialize_free(void);                 /*初始化空白PCB队列及PCB*/
int Isempty(struct LinkedList);             /*判断队列是否为空*/
void Insert(struct PCB ,struct LinkedList*); /*队列中插入新PCB*/

void Free2Ready(int);      /*从空白队列取出PCB插入就绪队列,同时确定进程所需要的执行时间*/
void Ready2Running(void);  /*从就绪队列取出PCB插入执行队列*/
void Running2Ready(void);  /*从执行队列取出PCB插入就绪队列*/
void Running2Free(void);   /*从执行队列取出PCB插入空白队列*/

void Start(void);
void Sched(void);

void Destroy(struct LinkedList*);            /*销毁队列*/


#endif

