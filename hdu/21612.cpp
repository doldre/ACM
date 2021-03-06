/a************************************************
 *Author        :mathon
 *Created Time  :2016年04月14日 星期四 13时42分08秒
*************************************************/
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 160000 + 5;
bool isprime[maxn];

void init() {
	fill(isprime, isprime + maxn, true);
	for (int i = 2; i < maxn; i++) {
		if(isprime[i]) for (int j = i + i; j < maxn; j += i) {
			isprime[j] = false;
		}
	}
	isprime[1] = false;
	isprime[2] = false;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	init();
	int x;
	int t = 0;
	while(cin >> x && x > 0) {
		cout << ++t << ": ";
		cout << (isprime[x] ? "yes" : "no") << endl;
	}
    return 0;
}
