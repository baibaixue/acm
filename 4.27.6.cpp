#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <utility>

using namespace std;
const int maxn = (int)2e5+5;
const int mod = 10007;

int prefix[maxn],dp[maxn];
string pattern;

void get_prefix_table() {
	int i = 0,len = -1,n = pattern.size();
	prefix[0] = -1;
	while (i < n) {
		if(len == -1 || pattern.at(i) == pattern.at(len)) {
			i++;
			len++;
			prefix[i] = len;
		}else {
			len = prefix[len];
		}
		printf("next[%d]=%d\n",i,prefix[i]);
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	int T,n,sum;
	cin >> T;
	while (T--) {
		cin >> n >> pattern;
		get_prefix_table();
		memset(dp,0,sizeof(dp));
		dp[0] = 0;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = (dp[prefix[i]] + 1) % mod;
			sum = (sum + dp[i]) % mod;
		}
		cout << sum << '\n';
	}
	return 0;
}

