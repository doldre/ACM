/************************************************
 *Author        :mathon
 *Created Time  :日  5/ 8 00:58:42 2016
 *Problem class:
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 200000 + 5, maxk = 50 + 5;
int n, k;
double dp[maxk][maxn];
int t[maxn];
double presum[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sa(n); sa(k);
    for (int i = 1; i <= n; i++) {
        sa(t[i]);
    }
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i - 1] + 1 / (double(t[i]));
    }

    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= k; j++) {

        }
    }
    return 0;
}
