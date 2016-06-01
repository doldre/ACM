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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 200 + 5;
int N, K;
double P[maxn];
double buf[maxn];
double solve(int mask) {
    if(__builtin_popcount(mask) != K) return 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if((mask >> i) & 1) {
            buf[cnt++] = P[i];
        }
    }
    double res = 0;
    for (int m = 0; m < (1<<K); m++) {
        if(__builtin_popcount(m) == K / 2) {
            double tmp = 1;
            for (int i = 0; i < K; i++) {
                if((m>>i) & 1) {
                    tmp *= buf[i];
                } else {
                    tmp *= (1 - buf[i]);
                }
            }
            res += tmp;
        }
    }
    return res;
}
int main(void)
{
#ifdef LOCAL
    freopen("B-small.txt", "r", stdin);
    freopen("B-out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        double ans = 0;
        for (int mask = 0; mask < (1<<N); mask++) {
            ans = max(ans, solve(mask));
        }
        printf("Case #%d: %.9f\n", Cas, ans);
    }
    return 0;
}
