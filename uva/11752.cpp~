/************************************************
 *Author        :mathon
 *Created Time  :2016年04月14日 星期四 14时27分57秒
 ***********************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;
bool isprime[maxn];
vector<ull> ans;

void init() {
	memset(isprime, true, sizeof(isprime));
	for (int i = 2; i < maxn; i++) {
		if(isprime[i]) {
			for (int j = i + i; j < maxn; j += i) {
				isprime[j] = false;
			}
		}
	}
}

void solve() {
	ans.push_back(1);
	for (int i = 2; i < (1<<17); i++) {
		ull t = i;
		for (int j = 2; double(t) * i < pow(2, 64); j++) {
			t *= i;
			if(!isprime[j]) {
				ans.push_back(t);
			}
		}
	}
	sort(ans.begin(), ans.end());
	int len = unique(ans.begin(), ans.end()) - ans.begin();
	for (int i = 0; i < len; i++) {
		cout << ans[i] << endl;
	}
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	init();
	solve();    
    return 0;
}
