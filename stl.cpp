#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Pass
{
public:
bool operator()(int x)
{
       return x>=60;
}
};

int main()
{
vector<int> a;
int count;
a.push_back(78);
a.push_back(92);
a.push_back(52);
count = count_if(a.begin(),a.end(),Pass());
cout<<"count="<<count<<endl;
}

 
