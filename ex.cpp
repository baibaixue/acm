#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

struct Vector3{
	
};
struct IntersectResult
	{
		float distance = 5;
		//Vector3 position = Vector3::zero;
		//Vector3 normal = Vector3::zero;
	};
	
static IntersectResult noHit=new IntersectResult();

int main(){

	printf("%d\n",noHit.distance);
}
