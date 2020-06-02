#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 220
#define inf 0x3f3f3f3f
using namespace std;
struct node {
	int id;
	int cap;
	double x, y, z;
	double dis;
};
node send[maxn];
node receive[maxn];
int matchsend[maxn];
int matchreceive[maxn];
vector<node> rank_send[maxn];
vector<node> rank_receive[maxn];
int C;
int Rank[maxn];
double distance(node a, node b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}
bool cmp(node a, node b) {
	if (a.dis == b.dis) {
		return a.cap > b.cap;
	}
	else {
		return a.dis < b.dis;
	}
}
int is_review(int a, int b,int s) {
	for (int i = 0; i < C; i++) {
		if (rank_send[s][i].id == a) {
			return 1;
		}
		else if (rank_send[s][i].id == b) {
			return -1;
		}
	}
}
void match() {
	for (int i = 1; i <= C; i++) {
		Rank[i] = 0;
	}
	while (1) {
		int flag = 0;
		for (int i = 1; i <=C; i++) {
			int r = receive[i].id;
			if (matchreceive[r] == 0) {
				int s = rank_receive[i][Rank[i]++].id;
				if (matchsend[s] == 0) {
					matchsend[s] = r;
					matchreceive[r] = s;
				}
				else {
					int pre = matchsend[s];
					if (is_review(r, pre, s) == 1) {
						matchreceive[pre] = 0;
						matchreceive[r] = s;
						matchsend[s] = r;
					}
				}
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	return;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &C);
		memset(matchsend, 0, sizeof(matchsend));
		memset(matchreceive, 0, sizeof(matchreceive));
		for (int i = 1; i <=C; i++) {
			scanf("%d", &send[i].id);
			scanf("%d%lf%lf%lf", &send[i].cap, &send[i].x, &send[i].y, &send[i].z);
			rank_send[send[i].id].clear();
		}
		for (int i = 1; i <=C; i++) {
			scanf("%d", &receive[i].id);
			scanf("%d%lf%lf%lf", &receive[i].cap, &receive[i].x, &receive[i].y, &receive[i].z);
			rank_receive[receive[i].id].clear();
			for (int j = 1; j <=C; j++) {
				send[j].dis = distance(receive[i], send[j]);
				rank_receive[receive[i].id].push_back(send[j]);
			}
			sort(rank_receive[receive[i].id].begin(), rank_receive[i].end(), cmp);
		}
		for (int i = 1; i <=C; i++) {
			for (int j = 1; j <=C; j++) {
				receive[j].dis = distance(receive[j], send[i]);
				rank_send[send[i].id].push_back(receive[j]);
			}
			sort(rank_send[send[i].id].begin(), rank_send[send[i].id].end(), cmp);
		}
		match();
		for (int i = 1; i <= C; i++) {
			printf("%d %d\n", send[i].id, matchsend[send[i].id]);
		}
	}
}
