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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int INF = 0x3f3f3f3f;
const int MAXK = 10 + 5;
int r[MAXK], c[MAXK];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &r[i], &c[i]);
    }
    ll ans = (ll) N * (N + 1) / 2 * (ll) M * (M + 1) / 2;
    for (int i = 1; i < (1 << K); i++) {
        int cnt = __builtin_popcount(i);
        int x1 = INF, x2 = -1, y1 = INF, y2 = -1;
        for (int j = 0; j < K; j++) {
            if ((1 << j) & i) {
                x1 = min(x1, r[j]);
                x2 = max(x2, r[j]);
                y1 = min(y1, c[j]);
                y2 = max(y2, c[j]);
            }
        }
        ll tmp = (ll) x1 * y1 * (N - x2 + 1) * (M - y2 + 1);
        if (cnt % 2) ans -= tmp; 
        else ans += tmp; 
    }
    cout << ans << endl;
    return 0;
}

