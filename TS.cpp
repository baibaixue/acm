#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2500;
const int M = 400005;
const int FIN = 2015;
typedef long long ll;
int n, m, s, t, sum;

int ec,  first[N], que[N], lev[N];
int Next[M], to[M], v[M];

void init() {
    sum = 0;
    ec = 0;
    memset(first, -1, sizeof(first));
    s = 0, t = FIN;
}

void addEdge(int a,int b,int c) {
    to[ec] = b;
    v[ec] = c;
    Next[ec] = first[a];
    first[a] = ec++;

    to[ec] = a;
    v[ec] = 0;
    Next[ec] = first[b];
    first[b] = ec++;
}

int BFS() {
    int kid, now, f = 0, r = 1, i;
    memset(lev, 0, sizeof(lev));
    que[0] = s, lev[s] = 1;
    while (f < r) {
        now = que[f++];
        for (i = first[now]; i != -1; i = Next[i]) {
            kid = to[i];    
            if (!lev[kid] && v[i]) {
                lev[kid] = lev[now] + 1;    
                if (kid == t) return 1;
                que[r++] = kid;
            }
        }
    }
    return 0;
}

int DFS(int now, int sum) {
    int kid, flow, rt = 0;
    if (now == t) return sum;
    for (int i = first[now]; i != -1 && rt < sum; i = Next[i]) {
        first[now] = i;  
        kid = to[i];
        if (lev[kid] == lev[now] + 1 && v[i]) {
            flow = DFS(kid, min(sum - rt, v[i]));
            if (flow) {
                v[i] -= flow;
                v[i^1] += flow;
                rt += flow;
            } else lev[kid] = -1;   
        }           
    }
    return rt;
}

int dinic() {
    int ans = 0;
    while (BFS()) {
                  
        ans += DFS(s, INF);
    }
    return ans;
}   

void input() {
    int Min = INF, Max = 0;
    scanf("%d %d", &n, &m);
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);  
        sum += a;
        addEdge(s, i, a);
        for (int j = b; j <= c; j++) {
            addEdge(i, j + n, 1);   
        }
        if (c < b) swap(c, b);
        if (Min > b) Min = b;
        if (Max < c) Max = c;
    }
    for (int i = Min; i <= Max; i++) {
        addEdge(i + n, t, m);   
    }
}

int main() {
    int T, Case = 1;
    scanf("%d", &T);
    while (T--) {
        
        init();
        input();
		printf("Case %d: ", Case++);
        if (dinic() == sum) printf("Yes\n");
        else printf("No\n");
        puts("");
    }
    return 0;
}

