/************************************************
 *Author        :mathon
 *Created Time  :2016年04月14日 星期四 15时52分28秒
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e8 + 1e5 + 5;
const double eps = 1e-9;
const int maxa = 10000 + 5;
int f(int x) {
	return x * x + x + 41;
}

bool isprime[maxn];
int sum[maxn];
void init() {
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for (int i = 2; i < maxn; i++) {
		if(isprime[i]) {
			for (int j = i + i; j < maxn; j += i) {
				isprime[j] = false;
			}
		}
	}

	for(int i = 1; i < maxa; i++) {
		int t = f(i-1);
		if(isprime[t]) {
			sum[i] = sum[i-1] + 1;
		} else {
			sum[i] = sum[i-1];
		}
	}
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	init();
	int a, b;
	while(cin >> a >> b) {
		printf("%.2f\n", (sum[b+1] - sum[a]) * 100.0 / (b - a + 1) + eps);
	}
    return 0;
}
