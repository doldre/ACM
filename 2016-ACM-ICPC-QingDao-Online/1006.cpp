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

const int MAXN = 1e5 + 5;
int deg[MAXN];
int A[MAXN];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        memset(deg, 0, sizeof(deg));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++; deg[v]++;
        }
        int cnt_odd = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(deg[i] % 2 == 1) {
                cnt_odd++;
            }
            int cnt = (deg[i] + 1) / 2;
            while(cnt--) ans ^= A[i];
        }
        if(cnt_odd == 2) {
            printf("%d\n", ans);
        } else if(cnt_odd == 0) {
            int tmp = ans;
            for (int i = 1; i <= n; i++) {
                ans = max(ans, tmp ^ A[i]);
            }
            printf("%d\n", ans);
        } else {
            printf("Impossible\n");
        }

    }
    return 0;
}

