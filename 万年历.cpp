
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include <stdlib.h> 
#include <string.h>
#include <iostream>
//Welcome to this project,this is a common project,it has many menu,like:callender,plusmachine and many ohther meuns.

//*******************************************************************************************************************************************  
//now this is the first menu:callender
//*******************************************************************************************************************************************  

int musichope(){
   PlaySound (TEXT("hope.wav"), NULL,SND_FILENAME|SND_ASYNC);
} 

int musictime(){
   PlaySound (TEXT("time.wav"), NULL,SND_FILENAME|SND_ASYNC);
} 

int musicstory(){
   PlaySound (TEXT("story.wav"), NULL,SND_FILENAME|SND_ASYNC);
} 

int musicnext(){
   PlaySound (TEXT("thenext.wav"), NULL,SND_FILENAME|SND_ASYNC);
}  

int musicseve(){
   PlaySound (TEXT("seve.wav"), NULL,SND_FILENAME|SND_ASYNC);
}  
//������ж� 
int isOrNotLeapYear(int year){
    return (year%4==0&&year%100!=0||year%400==0)?1:0;
}
//�·ݶ�Ӧ������ 
int dayOfMonth(int year,int month){
    int day;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        day=31;
    }else if(month==4||month==6||month==9||month==11){
        day=30;
    }else if(month==2&&isOrNotLeapYear(year)){
        day=29;
    }else if(month==2){
        day=28;
    }else{
        printf("������������������!\n");
        day=0;
    }
    return day;
}
//��һ��һ��һ������������ڹ��˶����� 
int sumOfDay(int year,int month){
    int dayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    //��һ��һ��һ�յ���ǰ�����յ����Ӻ�
    sum += (year-1)*365;
    //���İٵ�������
    sum += ((year-1)/400)*97;
    //�����İٵ�����
    sum += ((year-1)%400)/100*24;
    //����һ�ٵ�����
    sum += ((year-1)%100)/4;
    //���������  
    for(int i=0;i<month-1;i++){
        sum += dayOfMonth[i];
    }
    if(month==2&&isOrNotLeapYear(year)){
            sum++;
    }
    return sum;
}
//��Ҫ��ӡ����(��ӡ�����е�ÿһ��) 
void displayMonth(int year,int month){
    int i;
    int day;
    int sumday;
    int temp;
    sumday = sumOfDay(year,month);
    temp = sumday%7;
    day = dayOfMonth(year,month);
    if(day==0){
        printf("��û������·�������û��*����\n");
        return;
    }else{
        printf("\n");
        printf("\n");
        printf("\n--------------------------------------------------\n");
        printf("��\tһ\t��\t��\t��\t��\t��\n");
        printf("--------------------------------------------------\n");
    }
    for(i=0;i<temp+1;i++){
        printf("\t");
    }
    if(temp+1==7){
        printf("\r");
    }   
    for(i=1;i<=day;i++){
        printf("%d\t",i);
        if((i+temp+1)%7==0){
            printf("\n");
        }
    }
    printf("\n");
    printf("\n");
}
//��ӡ���� 
void displayYear(int year){
    int month;
    for(month = 1;month<=12;month++){
        displayMonth(year,month);
    }
}
//��ӡ���� 
void displayJdu(int year,int ji){
    int month;
    system("cls");
    if(ji==1){
        for(month = 1;month<=3;month++){
            displayMonth(year,month);
        }
    }else if(ji==2){
        for(month = 4;month<=6;month++){
            displayMonth(year,month);
        }
    }else if(ji==3){
        for(month = 7;month<=9;month++){
            displayMonth(year,month);
        }
    }else if(ji==4){
        for(month = 10;month<=12;month++){
            displayMonth(year,month);
        }
    }else{
        printf("��������ȷ�ļ��� ����?\n\n");
    }       
}
//��ӡ��ĳ��ĳ�µ�ĳ��ĳ�� 
void mounian(int year,int month,int cha){
    int count;
    for(count = 1;count<=cha;count++){
        displayMonth(year,month);
        month++;
        if(month==13){
            year++;
            month=1;
        }   
    }   
}
//��������
void cartoon(){                           
    printf ("             �~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(500); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(300); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100);
    printf ("�~");
    Sleep(500); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(100); 
    printf ("�~\n"); 
}
//���ٶ�������
void fastcartoon(){                            
    printf ("             �~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(100); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50);
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~");
    Sleep(50); 
    printf ("�~\n"); 
}
//���ɺ��� 
void list(){
    system("color B9");
    system ("cls");
    printf ("\n\n          ������2017��Ʒ����ϼ�       �����ó�Ʒ\n\n\n");
    printf ("\n\n\n\n                     ϵͳ��ʼ����......  \n\n");
    cartoon();
    printf ("\n\n\n                     �����ļ���ȡ��......\n\n\n");
    fastcartoon();
    printf ("\n\n\n                       �����Ѿ���\n\n\n\n");
    system ("pause");  
}
//������֤���� 
int key(){
    int h;
    int e;
    int m=23333;
    while(1){ 
    printf ("\n\n\n\n                          ACE & ������\n");
    printf ("\n                      �����֤ϵͳ Ver 1.4.3\n"); 
    printf ("\n                       ����������������88888\n\n"); 
        printf("\n\n               ��������ACE/������ �ṩ��KEY����������\n\n                              ");
        scanf ("%d",&e);
        getchar();
      if (e==m){
        printf ("\n\n                           ��֤�ɹ� \n");
        printf ("\n                        ��ӭ���� ACE admin \n");
        Sleep (2000); 
        system ("cls");
        break;  
    }else if (e==88888){
        system ("cls");
        printf ("\n\n      ��ӭ���롰�������롱����ģ�� Ϊ�����İ�ȫ ��ش��������ⷽ���޸�����\n\n\n");
        printf ("\n\n1.�����õ�ȫ����ʲô��\n\n");
        char username[50]="�������ƶ�����������" ;
        char weixin[20]="cttxiaotian";
        char username1[20];
        char weixin1[20];
        scanf ("%s",username1); 
        printf ("\n\n2.�����õ�΢�Ź��ں��˺��Ƕ��٣�\n\n");
        scanf ("%s",weixin1);
        if (strcmp(username1,username)==0||strcmp(weixin1,weixin)==0){
            printf ("\n\n\n\n�����֤��ͨ������������Ϊ��\n\n");
            printf ("      23333   \n\n"); 
            printf ("  3���ֺ��Զ����ص�¼����\n");
            Sleep(3000); 
            system ("cls");
        }else {
            printf ("\n\n         �ش����\n\n");
            Sleep(3000);
            system ("cls");
        }
    }else 
      if (e!=m||e!=88888){
      printf ("             �����֤ʧ�ܣ�����ϵACEС�鸺���˻�ȡ��֤��\n");
      Sleep(2000);
      system ("cls");
      } 
    }
list(); 
}
//�˵� 
int caidan(){
    system("color F3");
    int flag;
    while(1){
        system("cls");
    printf ("\n\n          ������2017��Ʒ����ϼ�       �����ó�Ʒ\n\n\n");
        printf("\n\n       1.������                                7.��������ѡ��\n\n");
        printf("       2.��ѯ��                                8.\n\n");
        printf("       3.��ѯ��\n\n");
        printf("       4.ĳ��ĳ��-ĳ��ĳ��\n\n");
        printf("       5.����\n\n");
        printf("       6.�˳�\n\n");
        printf("");
        scanf("%d",&flag);
        getchar();
        if(flag==1||flag==2||flag==3||flag==4||flag==5||flag==6||flag==7){
            break;
        }else{
            system("cls");
            printf("     ��������ȷ��ѡ��\n\n");
            system("pause");
        }
    }
    system("cls");
    return flag;
}
//�������� 
int systemcolor();
int systemcolorconfig();
int setting();
//ϵͳ��ɫ�Զ��庯��
int systemcolor(){                            
    system("cls");
    printf ("\n\n\n��ѡ����ϲ������ɫ��\n\n");
    printf ("��1����ɫ���� ��ɫ����\n��2������ɫ���� ��ɫ����\n��3������ɫ���� ����ɫ����\n��4��ǳ��ɫ���� ��ɫ����\n��5������ɫ���� ��ɫ����\n");
    printf ("��6����ɫ���� ����ɫ����\n��7����ɫ���� ����ɫ����\n��8���ָ�ϵͳĬ��\n\n\n"); 
    int a;
    scanf ("%d",&a);
    getchar();
    if (a==1){
        system ("color 07");
    }else
      if (a==2){
        system ("color C1");
      }else
        if (a==3){
                system ("color B3");
        }else
          if (a==4){
                system ("color A4");
          }else
            if (a==5){
                    system ("color E4");
            }else
              if (a==6){
                    system ("color 8D");
              }else
                if (a==7){
                        system ("color 09");
                }else
                        system ("color B9");
    systemcolorconfig();
}
//ϵͳ��ɫ�������
int systemcolorconfig(){                            
    system ("cls");
    printf ("\n\n\n           ���ı�����ɫ�Ѹ���:\n           �Ƿ��������ã�\n\n           ��1��ȷ��   ��2������ѡ��\n\n\n");
    int a;
    scanf ("%d",&a);
    getchar();
    if (a==1){
        setting();
    }else
        systemcolor();
}
//����֧��
int support(){                            
    system ("cls");
    printf ("\n\n          ������2017��Ʒ����ϼ�       �����ó�Ʒ\n\n\n");
    printf ("�汾���ܣ�\n��1���ó���Ϊ2017�곬�����ƶ����������ҵ����е�С����ĺϼ���\n��2����������������ƶ������������ڲ���Ա�ܽ�ʹ��\n");
    printf ("��3����������д�����й����Ҹ������д��������ͳһʹ��MinGW GCC 4.7.2�����������ʾ�����������з�����������ϵ�ͷ�������������������\n");
    printf ("��4����������ִ��뽫���п�Դ�����������ô��������Ƶ��ɻ��ҹ�����һ�ɲ����Ӧ\n");
    printf ("��5���������ƶ����������������Դ���ΪĿ�꣬�ҹ����ҿɳ�ŵ��������丽��������еĺ��Ĵ����ɹ��������б�д���ɣ��������ƣ������ɺ�\n\n\n");
    printf ("���ߣ���ͳ˧\n���������飺�������ƶ�����������\n��ϵ��ʽ��\n    QQ 1271261360\n    ���䣺1271261360@qq.com\n\n\n�ǳ���лʹ�ó�����ϵ�����\n");
    printf ("���� 8 �����ص���һ����\n\n\n"); 
    int a;
    scanf ("%d",&a);
    getchar();
    if (a==8){
      caidan();
    }else;
}
//ϵͳ���ú��� 
int setting(){
    system ("cls");
    printf ("\n\n          ������2017��Ʒ����ϼ�               �����ó�Ʒ\n\n\n");
    printf ("\n\n*************************************************************\n\n");
    printf ("\n                       ϵͳ����\n"); 
    printf ("\n\n*************************************************************\n\n");
    printf (" ��1��������ɫ����\n��2������֧��\n��3���������˵�\n\n");
    int p;
    printf ("������������еĲ�����\n");
    scanf ("%d",&p);
    getchar();
    if (p==1){
        systemcolor();
    }else
        if (p==2){
          support();
        }else
          if (p==3){
          caidan();
          }else;
} 

int searching(){
    int ji,month,year,flag,yeartwo,monthtwo,cha;
    while(1){
        flag=caidan();
        if(flag==1){
            printf("����������,��.����\n\n");
            scanf("%d.%d",&year,&month);
            getchar();
            displayMonth(year,month); 
        }else if(flag==2){
            printf("������Ҫ��ѯ�����\n\n");
            scanf("%d",&year);
            getchar();
            displayYear(year);      
        }else if(flag==3){
            printf("1Ϊ����\n");
            printf("2Ϊ�ļ�\n");
            printf("3Ϊ�＾\n");
            printf("4Ϊ����\n");
            printf("������Ҫ��ѯ����ݺͼ���,��.����,\n\n");
            scanf("%d.%d",&year,&ji);
            getchar();
            displayJdu(year,ji);
        }else if(flag==4){
            printf("������Ҫ��ѯ������,����2011.1-2012.1\n\n");
            scanf("%d.%d-%d.%d",&year,&month,&yeartwo,&monthtwo);
            getchar();
            cha=(yeartwo-year)*12+monthtwo-month+1;
            mounian(year,month,cha);
        }else if(flag==5){
            setting(); 
        }else if(flag==7){
            printf ("\n      ��ѡ������Ҫ���õı������֣�\n\n");
            printf ("  1.Hope\n  2.Story Of US\n  3.The Next Episode\n  4.SEVE\n  5.Time\n\n");
            int l;
            scanf ("%d",&l);
            if (l==1){
                musichope();
            }else if (l==2){
                musicstory();
            }else if (l==3){
                musicnext();
            }else if (l==4){
                musicseve();
            }else if (l==5){
                musictime();
            }else printf ("  ��������  \n");
        } else if(flag==6){
            break;
        }
        system("pause");
    }   
}

int callender(){
    musichope();
    key();
    searching();    
}

//*******************************************************************************************************************************************  
//in front of this text is the callender.cpp file
//*******************************************************************************************************************************************  


//******************************************************************************************************************************************* 
//in front of this text is the plus.cpp file
//******************************************************************************************************************************************* 


int mainselect(); 



int mainselect(){

    printf ("\n\n\n                                      ��ѡ��һ������Ŀ����Enter����\n\n");
    printf ("                            1.�๦��������        2.�๦�ܼ�����\n\n");
    int a;
    scanf ("%d",&a);
    if (a==1){
        callender();
    }else
        plus();

}

//*******************************************************************************************************************************************
//in front of this text is the mainselect.cpp file 
//******************************************************************************************************************************************* 
int main(){  
    mainselect();
}

