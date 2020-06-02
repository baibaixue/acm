#include <iostream>
using	namespace	std;
class CMyVect{
	public:
		CMyVcet(){
			num=0;
			list=NULL;
		}
		CMyVect(int n){
			num=n;
			list=new int[n];
		} 
		CMyVect(const CMyVect& v){
			num=v.num;
			list=new int[v.num];
			for(int i=0;i<num;i++){
				list[i]=v.list[i];
			}
		}
		int& operator[](const int &n);
		int operator[](const int &n)const;
		~CMyVect(){
			num=0;
			delete []list;
		}
		int size()const{
			return num;
		}
	private:
		int num;
		int* list;
}; 
int& CMyVect::operator[](const int &n){
	return list[n];
}
int CMyVect::operator[](const int &n)const{
	return list[n];
} 
void	DisplayVector (const CMyVect &V)
{	for (int i = 0; i < V.size(); i++)
		cout << V [i] << '\t';
	cout << endl;
}
int  main()
{	int		i, n;
	cin >> n;
	CMyVect 	V(n);
	for (i = 0; i < V.size(); i++)
		V [i] = 2 * i;
		
	CMyVect  V2 (V);
	
	for (i = 0; i < V2.size(); i++)
		V2 [i] = 2 * V2 [i] + 1;
	
	DisplayVector (V);
	DisplayVector (V2);
	
	return 0;
}
