/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
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
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 19;
double p[maxn][maxn];
double dp[1<<maxn][maxn];
int n;

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}

	dp[1][0] = 1;
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < n; j++) {
			if(!((i >> j) & 1)) {
				continue;
			}
			for (int k = 0; k < n; k++) {
				if(j == k || !((i >> k) & 1)) {
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i^(1<<k)][j] * p[j][k] +
						dp[i^(1<<j)][k] * p[k][j]);
			}
		}
	}
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = max(dp[(1<<n)-1][i], res);
	}
	printf("%.9f\n", res);
    return 0;
}
