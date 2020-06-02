#include<iostream>
#include<string>
using namespace std;
int main(){
int k; cin>>k;
string s; cin>>s;
for(int i=0;i<s.size();i++){
    cout<<" ";
    if(s[i]==1+'0') cout<<" ";
    if(s[i]==2+'0'||s[i]==3+'0'||s[i]==5+'0'||s[i]==6+'0'||s[i]==7+'0'||s[i]==8+'0'||s[i]==9+'0'||s[i]=='0'){
        cout<<" ";
        for(int i=1;i<=k;i++) cout<<"-";
        cout<<" ";
    }
    if(s[i]==4+'0'){
        cout<<" ";
        for(int i=1;i<=k;i++) cout<<" ";
        cout<<" ";
    }
}
cout<<endl;//first
for(int i=1;i<=k;i++){
    for(int i=0;i<s.size();i++){
        cout<<" ";
        if(s[i]==1+'0') cout<<"|";
        if(s[i]==2+'0'||s[i]==3+'0'||s[i]==7+'0'){
            cout<<" "; for(int i=1;i<=k;i++) cout<<" "; cout<<"|";
        }
        if(s[i]==4+'0'||s[i]==8+'0'||s[i]==9+'0'||s[i]=='0'){
            cout<<"|"; for(int i=1;i<=k;i++) cout<<" "; cout<<"|";
        }
        if(s[i]==5+'0'||s[i]==6+'0'){
            cout<<"|"; for(int i=1;i<=k;i++) cout<<" "; cout<<" ";
        }
    }
    cout<<endl;
}//second
for(int i=0;i<s.size();i++){
    cout<<" ";
    if(s[i]==1+'0') cout<<" ";
    if(s[i]==2+'0'||s[i]==3+'0'||s[i]==5+'0'||s[i]==6+'0'||s[i]==4+'0'||s[i]==8+'0'||s[i]==9+'0'){
        cout<<" ";
        for(int i=1;i<=k;i++) cout<<"-";
        cout<<" ";
    }
    if(s[i]==7+'0'||s[i]=='0'){
        cout<<" ";
        for(int i=1;i<=k;i++) cout<<" ";
        cout<<" ";
    }
}
cout<<endl;//third
for(int i=1;i<=k;i++){
    for(int i=0;i<s.size();i++){
        cout<<" ";
        if(s[i]==1+'0') cout<<"|";
        if(s[i]==4+'0'||s[i]==3+'0'||s[i]==7+'0'||s[i]==5+'0'||s[i]==9+'0'){
            cout<<" "; for(int i=1;i<=k;i++) cout<<" "; cout<<"|";
        }
        if(s[i]==6+'0'||s[i]==8+'0'||s[i]=='0'){
            cout<<"|"; for(int i=1;i<=k;i++) cout<<" "; cout<<"|";
        }
        if(s[i]==2+'0'){
            cout<<"|"; for(int i=1;i<=k;i++) cout<<" "; cout<<" ";
        }
    }
    cout<<endl;
}//fourth
for(int i=0;i<s.size();i++){
    cout<<" ";
    if(s[i]==1+'0') cout<<" ";
    if(s[i]==2+'0'||s[i]==3+'0'||s[i]==5+'0'||s[i]==6+'0'||s[i]==8+'0'||s[i]==9+'0'||s[i]=='0'){
        cout<<" ";
        for(int i=1;i<=k;i++) cout<<"-";
        cout<<" ";
    }
    if(s[i]==4+'0'||s[i]==7+'0'){
        cout<<" ";
        for(int i=1;i<=k;i++) cout<<" ";
        cout<<" ";
    }
}//fifth
return 0;
}
