  #include<bits/stdc++.h>
  using namespace std;
  int main()
  {
  int t;
  cin>>t;
  int i,j;
  int c[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  map<int,char>a;
 a[0]='1';
 a[1]='0';
 a[2]='X';
 a[3]='9';a[8]='4';
 a[4]='8';a[9]='3';
 a[5]='7';a[10]='2';
 a[6]='6';
 a[7]='5';
 bool flag=false;
 while(t--)
 {
   string s;
   cin>>s;
   int ans=0;
  bool tmp=false;
  for(i=0;i<17;i++)
     {
         if(s[i]!='X')
       ans+=(s[i]-'0')*c[i];
      else
        ans+=10*c[i];
            ans=ans%11;
      }
      
   if(a[ans]==s[17])continue;
  else
   {
     cout<<s<<endl;
      flag=true;
   }
   
 }
 if(!flag)
 cout<<"All passed\n";
 }
