#include <iostream>
using     namespace std;
class Point
{
private:
	int x, y;			// 坐标
	static int count;	// 静态数据成员
public:
	Point(int m = 0, int n = 0): x(m), y(n) { count++; }// 构造函数
	~Point() { count--; }			// 析构函数
	int GetX() const { return x; }		// 返回x
	int GetY() const { return y; }		// 返回y
	static void ShowCount() { cout << count << endl; }// 输出count
};

int Point::count=0;		// 静态数据成员的初始化
int main()					// 主函数main()
{
	Point::ShowCount();			// 输出count
	Point a(6, 8);				// 定义对象
	Point::ShowCount();			// 输出count
	return 0;                    	    // 返回值0, 返回操作系统
}

