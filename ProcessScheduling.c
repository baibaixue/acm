#include<stdio.h>
#include<stdlib.h>
#include"ProcessScheduling.h"
#include<string.h>
void Initialize(struct LinkedList* queue){
    queue->front = (struct Node*)malloc(sizeof(struct Node));
    queue->rear = (struct Node*)malloc(sizeof(struct Node));
    queue->front->next = queue->rear;
    queue->front->pre = NULL;
    queue->rear->pre = queue->front;
    queue->rear->next = NULL;
    queue->currPtr = NULL;
    queue->size = 0;
}


void Initialize_free() {
    struct PCB pcb0;
    pcb0.pid = 0; pcb0.pname = "p0"; pcb0.pstate = Free; pcb0.ptime = 0;
    Insert(pcb0, &freeQueue);
    
    struct PCB pcb1;
    pcb1.pid = 1; pcb1.pname = "p1"; pcb1.pstate = Free; pcb1.ptime = 0;
    Insert(pcb1, &freeQueue);
    
    struct PCB pcb2;
    pcb2.pid = 2; pcb2.pname = "p2"; pcb2.pstate = Free; pcb2.ptime = 0;
    Insert(pcb2, &freeQueue);
    
    struct PCB pcb3;
    pcb3.pid = 3; pcb3.pname = "p3"; pcb3.pstate = Free; pcb3.ptime = 0;
    Insert(pcb3, &freeQueue);
    
    struct PCB pcb4;
    pcb4.pid = 4; pcb4.pname = "p4"; pcb4.pstate = Free; pcb4.ptime = 0;
    Insert(pcb4, &freeQueue);

    struct PCB pcb5;
    pcb5.pid = 5; pcb5.pname = "p5"; pcb5.pstate = Free; pcb5.ptime = 0;
    Insert(pcb5, &freeQueue);


}


int Isempty(struct LinkedList queue){
        if(queue.size == 0) return 1;
        else return 0;
}


void Insert(struct PCB pcb, struct LinkedList *freequeue){
        struct Node *newnode;
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode==NULL){
                printf("分配空间失败！\n");
                exit(1);
        }else{
                freequeue->size += 1;
                newnode->data.pid = pcb.pid;
                newnode->data.pstate = pcb.pstate;
                newnode->data.pname = (char*)malloc(sizeof(pcb.pname)); 
                strcpy(newnode->data.pname,pcb.pname);
                newnode->data.ptime = 0;

                if(freequeue->size == 1){
                        freequeue->front->next = newnode;
                        newnode->pre = freequeue->front;
                        newnode->next = freequeue->rear;
                        freequeue->rear->pre = newnode;
                }else{
                        freequeue->currPtr = freequeue->front;
                        while(freequeue->currPtr->next != freequeue->rear){
                                freequeue->currPtr = freequeue->currPtr->next;
                        }
                        newnode->pre = freequeue->currPtr;
                        freequeue->currPtr->next->pre = newnode;
                        newnode->next = freequeue->currPtr->next;
                        freequeue->currPtr->next = newnode;
                }
        }
}

void Free2Ready(int _ptime) {
    if (!Isempty(freeQueue)) {
        /*取出PCB*/
        struct Node* temp = freeQueue.front->next;
        temp->data.ptime = _ptime;
        temp->data.pstate = ready;/*状态变为就绪状态*/
        /*将PCB插入就绪队列队尾*/
        freeQueue.front->next = temp->next;
        temp->next->pre = freeQueue.front;
        struct Node* before = readyQueue.rear->pre;
        before->next = temp;
        temp->pre = before;
        temp->next = readyQueue.rear;
        readyQueue.rear->pre = temp;

        freeQueue.size--;
        readyQueue.size++;

        printf("Sched: %s(Free -> Ready)\n", temp->data.pname);
    }
    else {
        return;
    }
}

void Ready2Running() {
    if (!Isempty(readyQueue)) {
        /*取随机数*/
        srand((int)time(0));
        int rand_num;
        if(readyQueue.size == 1){
        	rand_num = 0;
		}
        else {
        	rand_num = rand() % (readyQueue.size - 1);
		}
        
        struct Node* temp;
        readyQueue.currPtr = readyQueue.front->next;
        while (rand_num != 0) {
            readyQueue.currPtr = readyQueue.currPtr->next;
            rand_num--;
        }
        temp = readyQueue.currPtr;
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        temp->data.pstate = running;/*就绪状态转换为运行态*/
        if (!Isempty(runningQueue)) {   /*是否有正在运行的进程*/
            if (runningQueue.front->next->data.ptime <= 0) {    
                /*进程执行结束,回收PCB到空白队列*/
                Running2Free();
            }
            else {
                /*进程未执行结束，将处于运行状态的进程回收到就绪队列*/
                Running2Ready();
            }
        }
        /*进入执行队列*/
        runningQueue.front->next = temp;
        temp->next = runningQueue.rear;
        runningQueue.rear->pre = temp;
        temp->pre = runningQueue.front;
        
        runningQueue.size++;
        readyQueue.size--;
        
        printf("Sched: %s(Ready -> Running)\n", temp->data.pname);
    }
    
}

void Running2Ready() {
    struct Node* temp = runningQueue.front->next;
    temp->data.pstate = ready;/*运行态变为就绪态*/ 
    runningQueue.front->next = runningQueue.rear;
    runningQueue.rear->pre = runningQueue.front;

    struct Node* before = readyQueue.rear->pre;
    before->next = temp;
    temp->next = readyQueue.rear;
    readyQueue.rear->pre = temp;
    temp->pre = before;
    
    runningQueue.size--;
    readyQueue.size++;

    printf("Sched: %s(Running -> Ready)\n", temp->data.pname);
}

void Running2Free() {
    struct Node* temp = runningQueue.front->next;
    temp->data.pstate = Free;/*运行态变为空闲态*/ 
    runningQueue.front->next = runningQueue.rear;
    runningQueue.rear->pre = runningQueue.front;

    struct Node* before = freeQueue.rear->pre;
    before->next = temp;
    temp->next = freeQueue.rear;
    freeQueue.rear->pre = temp;
    temp->pre = before;

    runningQueue.size--;
    freeQueue.size++;

    printf("Sched: %s(Running -> Free)\n", temp->data.pname);
}

void Destroy(struct LinkedList *queue)
{
        queue->currPtr = queue->rear;
        while(queue->currPtr != NULL)
        {
                struct Node* temp = queue->currPtr;
                queue->currPtr = queue->currPtr->pre;
                free(temp);
        }
        queue->size = 0;
}

void Start() {
	Initialize_free();
    int pcb_num; /*进程数量*/
    printf("进程数量(输入0退出):");
    scanf("%d", &pcb_num);
    if (pcb_num == 0) {
        Destroy(&freeQueue);
        Destroy(&readyQueue);
        Destroy(&runningQueue);
        exit(0);
    }
    else {
        printf("每个进程执行时间(中间以空格隔开):");
        while (pcb_num !=0) {
            int t;
            scanf("%d", &t);
            Free2Ready(t);
            pcb_num--;
        }
    }
    Sched();
}

void Sched() {
    int Time = 0;   /*执行时间*/
    while (!Isempty(readyQueue) || !Isempty(runningQueue)) {
        printf("Time: %d  \n", Time);
        if (!Isempty(runningQueue)) {
            runningQueue.currPtr = runningQueue.front->next;
            runningQueue.currPtr->data.ptime -= ts; 
            if(runningQueue.currPtr->data.ptime<=0){
            	Running2Free();
			}
        }
		Ready2Running();
    	Time += ts;
        printf("Running:");
        runningQueue.currPtr = runningQueue.front->next;
        while (runningQueue.currPtr != runningQueue.rear) {
            printf(" %s", runningQueue.currPtr->data.pname);
            runningQueue.currPtr = runningQueue.currPtr->next;
        }
        printf("\nReady: ");
        readyQueue.currPtr = readyQueue.front->next;
        if (readyQueue.currPtr != readyQueue.rear) {
            printf("%s", readyQueue.currPtr->data.pname);
            readyQueue.currPtr = readyQueue.currPtr->next;
        }
        while (readyQueue.currPtr != readyQueue.rear) {
            printf("->%s", readyQueue.currPtr->data.pname);
            readyQueue.currPtr = readyQueue.currPtr->next;
        }
        printf("\n\n");
    }
}

int main() {
    Initialize(&freeQueue);
    Initialize(&readyQueue);
    Initialize(&runningQueue);

    while (1) {
        Start();
    }
}
