
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include <string>
#include <algorithm>
using namespace std;
struct ax
{
    string str;
    int grade;
}arr[1001];
bool com(const ax &a,const ax &b)    
{    
    if(a.grade != b.grade)
    return a.grade > b.grade;
    else
        return a.str < b.str;
}
int main()
{
    int n;
    int m,g;
    int t_val[11];
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&m,&g);
        int Count = 0;
        for(int i = 1; i <= m; i++)
            scanf("%d",& t_val[i]);
        for(int i = 0; i < n; i++)
        {    
            cin>> arr[i].str;
            arr[i].grade = 0;
            int t,x;
            scanf("%d",&t);
            while(t--)
            {
                scanf("%d",& x);
                arr[i].grade += t_val[x];
            }
            if(arr[i].grade >= g)
                Count++;
        }
        sort(arr,arr+n,com);
        cout << Count << endl;
        for(int i = 0; i < Count ; i++)
            cout << arr[i].str << " " << arr[i].grade << endl;
    }
    //fclose(stdin);//关闭文件 
    //fclose(stdout);//关闭文件 
    return 0;
}
