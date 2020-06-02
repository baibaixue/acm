#include <iostream>
using     namespace std;
class Point
{
private:
	int x, y;			// ����
	static int count;	// ��̬���ݳ�Ա
public:
	Point(int m = 0, int n = 0): x(m), y(n) { count++; }// ���캯��
	~Point() { count--; }			// ��������
	int GetX() const { return x; }		// ����x
	int GetY() const { return y; }		// ����y
	static void ShowCount() { cout << count << endl; }// ���count
};

int Point::count=0;		// ��̬���ݳ�Ա�ĳ�ʼ��
int main()					// ������main()
{
	Point::ShowCount();			// ���count
	Point a(6, 8);				// �������
	Point::ShowCount();			// ���count
	return 0;                    	    // ����ֵ0, ���ز���ϵͳ
}

