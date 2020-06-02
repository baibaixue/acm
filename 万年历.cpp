
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
//闰年的判断 
int isOrNotLeapYear(int year){
    return (year%4==0&&year%100!=0||year%400==0)?1:0;
}
//月份对应的天数 
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
        printf("。。。。。。。。。!\n");
        day=0;
    }
    return day;
}
//从一年一月一日至输入的日期过了多少天 
int sumOfDay(int year,int month){
    int dayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    //从一年一月一日到当前年月日的日子和
    sum += (year-1)*365;
    //满四百的闰年数
    sum += ((year-1)/400)*97;
    //不满四百的闰年
    sum += ((year-1)%400)/100*24;
    //不足一百的闰年
    sum += ((year-1)%100)/4;
    //这年的天数  
    for(int i=0;i<month-1;i++){
        sum += dayOfMonth[i];
    }
    if(month==2&&isOrNotLeapYear(year)){
            sum++;
    }
    return sum;
}
//主要打印函数(打印月历中的每一天) 
void displayMonth(int year,int month){
    int i;
    int day;
    int sumday;
    int temp;
    sumday = sumOfDay(year,month);
    temp = sumday%7;
    day = dayOfMonth(year,month);
    if(day==0){
        printf("有没有这个月份你心里没点*数吗？\n");
        return;
    }else{
        printf("\n");
        printf("\n");
        printf("\n--------------------------------------------------\n");
        printf("日\t一\t二\t三\t四\t五\t六\n");
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
//打印整年 
void displayYear(int year){
    int month;
    for(month = 1;month<=12;month++){
        displayMonth(year,month);
    }
}
//打印季度 
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
        printf("请输入正确的季度 好吗?\n\n");
    }       
}
//打印从某年某月到某年某月 
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
//动画函数
void cartoon(){                           
    printf ("             ▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(500); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(300); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100);
    printf ("▇");
    Sleep(500); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(100); 
    printf ("▇\n"); 
}
//快速动画函数
void fastcartoon(){                            
    printf ("             ▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(100); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50);
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇");
    Sleep(50); 
    printf ("▇\n"); 
}
//过渡函数 
void list(){
    system("color B9");
    system ("cls");
    printf ("\n\n          超天堂2017精品软件合集       超天堂出品\n\n\n");
    printf ("\n\n\n\n                     系统初始化中......  \n\n");
    cartoon();
    printf ("\n\n\n                     数据文件读取中......\n\n\n");
    fastcartoon();
    printf ("\n\n\n                       程序已就绪\n\n\n\n");
    system ("pause");  
}
//密码认证函数 
int key(){
    int h;
    int e;
    int m=23333;
    while(1){ 
    printf ("\n\n\n\n                          ACE & 超天堂\n");
    printf ("\n                      身份认证系统 Ver 1.4.3\n"); 
    printf ("\n                       如忘记密码请输入88888\n\n"); 
        printf("\n\n               请输入由ACE/超天堂 提供的KEY以启动程序\n\n                              ");
        scanf ("%d",&e);
        getchar();
      if (e==m){
        printf ("\n\n                           认证成功 \n");
        printf ("\n                        欢迎回来 ACE admin \n");
        Sleep (2000); 
        system ("cls");
        break;  
    }else if (e==88888){
        system ("cls");
        printf ("\n\n      欢迎进入“忘记密码”功能模块 为了您的安全 请回答下列问题方可修改密码\n\n\n");
        printf ("\n\n1.超天堂的全名是什么？\n\n");
        char username[50]="超天堂移动互联工作室" ;
        char weixin[20]="cttxiaotian";
        char username1[20];
        char weixin1[20];
        scanf ("%s",username1); 
        printf ("\n\n2.超天堂的微信公众号账号是多少？\n\n");
        scanf ("%s",weixin1);
        if (strcmp(username1,username)==0||strcmp(weixin1,weixin)==0){
            printf ("\n\n\n\n身份验证已通过，您的密码为：\n\n");
            printf ("      23333   \n\n"); 
            printf ("  3秒种后自动返回登录界面\n");
            Sleep(3000); 
            system ("cls");
        }else {
            printf ("\n\n         回答错误！\n\n");
            Sleep(3000);
            system ("cls");
        }
    }else 
      if (e!=m||e!=88888){
      printf ("             身份认证失败，请联系ACE小组负责人获取认证码\n");
      Sleep(2000);
      system ("cls");
      } 
    }
list(); 
}
//菜单 
int caidan(){
    system("color F3");
    int flag;
    while(1){
        system("cls");
    printf ("\n\n          超天堂2017精品软件合集       超天堂出品\n\n\n");
        printf("\n\n       1.万年历                                7.背景音乐选择\n\n");
        printf("       2.查询年                                8.\n\n");
        printf("       3.查询季\n\n");
        printf("       4.某年某月-某年某月\n\n");
        printf("       5.设置\n\n");
        printf("       6.退出\n\n");
        printf("");
        scanf("%d",&flag);
        getchar();
        if(flag==1||flag==2||flag==3||flag==4||flag==5||flag==6||flag==7){
            break;
        }else{
            system("cls");
            printf("     请输入正确的选项\n\n");
            system("pause");
        }
    }
    system("cls");
    return flag;
}
//公共定义 
int systemcolor();
int systemcolorconfig();
int setting();
//系统颜色自定义函数
int systemcolor(){                            
    system("cls");
    printf ("\n\n\n请选择您喜欢的颜色：\n\n");
    printf ("（1）黑色背景 白色字体\n（2）淡红色背景 蓝色字体\n（3）淡绿色背景 湖蓝色字体\n（4）浅绿色背景 红色字体\n（5）淡黄色背景 红色字体\n");
    printf ("（6）灰色背景 淡紫色字体\n（7）黑色背景 淡蓝色字体\n（8）恢复系统默认\n\n\n"); 
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
//系统颜色变更提醒
int systemcolorconfig(){                            
    system ("cls");
    printf ("\n\n\n           您的背景颜色已更改:\n           是否立即启用？\n\n           （1）确认   （2）重新选择\n\n\n");
    int a;
    scanf ("%d",&a);
    getchar();
    if (a==1){
        setting();
    }else
        systemcolor();
}
//技术支持
int support(){                            
    system ("cls");
    printf ("\n\n          超天堂2017精品软件合集       超天堂出品\n\n\n");
    printf ("版本介绍：\n（1）该程序为2017年超天堂移动互联工作室的所有的小程序的合集版\n（2）本软件供超天堂移动互联工作室内部人员总结使用\n");
    printf ("（3）本软件所有代码均有工作室负责与编写，编译器统一使用MinGW GCC 4.7.2，对于软件显示不正常与运行非正常的请联系客服进行适配或获得其余帮助\n");
    printf ("（4）本软件部分代码将进行开源处理，对于闲置代码有相似的疑惑我工作室一律不予回应\n");
    printf ("（5）超天堂移动互联工作室向来以创新为目标，我工作室可承诺本软件及其附属软件所有的核心代码由工作室自行编写而成，如有类似，纯属巧合\n\n\n");
    printf ("作者：刘统帅\n所属工作组：超天堂移动互联工作室\n联系方式：\n    QQ 1271261360\n    邮箱：1271261360@qq.com\n\n\n非常感谢使用超天堂系列软件\n");
    printf ("输入 8 立即回到上一界面\n\n\n"); 
    int a;
    scanf ("%d",&a);
    getchar();
    if (a==8){
      caidan();
    }else;
}
//系统设置函数 
int setting(){
    system ("cls");
    printf ("\n\n          超天堂2017精品软件合集               超天堂出品\n\n\n");
    printf ("\n\n*************************************************************\n\n");
    printf ("\n                       系统设置\n"); 
    printf ("\n\n*************************************************************\n\n");
    printf (" （1）界面颜色设置\n（2）技术支持\n（3）返回主菜单\n\n");
    int p;
    printf ("请输入您想进行的操作：\n");
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
            printf("请输入年月,用.隔开\n\n");
            scanf("%d.%d",&year,&month);
            getchar();
            displayMonth(year,month); 
        }else if(flag==2){
            printf("请输入要查询的年份\n\n");
            scanf("%d",&year);
            getchar();
            displayYear(year);      
        }else if(flag==3){
            printf("1为春季\n");
            printf("2为夏季\n");
            printf("3为秋季\n");
            printf("4为冬季\n");
            printf("请输入要查询的年份和季度,用.隔开,\n\n");
            scanf("%d.%d",&year,&ji);
            getchar();
            displayJdu(year,ji);
        }else if(flag==4){
            printf("请输入要查询的年月,例如2011.1-2012.1\n\n");
            scanf("%d.%d-%d.%d",&year,&month,&yeartwo,&monthtwo);
            getchar();
            cha=(yeartwo-year)*12+monthtwo-month+1;
            mounian(year,month,cha);
        }else if(flag==5){
            setting(); 
        }else if(flag==7){
            printf ("\n      请选择您想要设置的背景音乐：\n\n");
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
            }else printf ("  输入有误！  \n");
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

    printf ("\n\n\n                                      请选择一个子项目并按Enter进入\n\n");
    printf ("                            1.多功能万年历        2.多功能计算器\n\n");
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

