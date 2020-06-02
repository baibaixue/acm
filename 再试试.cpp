#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
struct Point
{
    double x;
    double y;
    Point(){}
    Point(double xx,double yy){
    	x=xx;
    	y=yy;
	}
};
double Distance(const Point& lhs, const Point& rhs)
{
    
    return sqrt(((lhs.x-rhs.x)*(lhs.x-rhs.x))+((lhs.y-rhs.y)*(lhs.y-rhs.y)));
}
int main()
{
    vector<double>d;
    int n;
    while(cin>>n){
    Point arr[n];
    for (int i =0; i < n; i++){
        double x,y;
        cin>>x>>y;
        arr[i]=Point(x,y);
}
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               double dis = Distance(arr[i],arr[j]);
                d.push_back(dis);
          }
       }
       vector<double>::iterator biggest;
        biggest = max_element(d.begin(), d.end());
        vector<double>::iterator smallest;
        smallest = min_element(d.begin(),d.end());
         cout<<setprecision(5)<<*biggest<<setprecision(5)<<*smallest<<endl;
    }
    return 0;
}
