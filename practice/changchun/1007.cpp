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
const ll MOD = 1e9 + 7;
const int MAXN = 50 + 5;
int G[MAXN][MAXN];
int n, m;
int cnt;
map<ll, bool> used;

int buf[MAXN];

void dfs(int pos) {
    cnt++;
    for (int i = buf[pos-1] + 1; i <= n; i++) {
        bool ok = true;
        for (int j = 1; j < pos; j++) {
            for (int k = j + 1; k < pos; k++) {
                int x = buf[j], y = buf[k];
                if(G[i][x] && G[i][y] && G[x][y]) ok = false;
                if(!G[i][x] && !G[i][y] && !G[x][y]) ok = false;
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok) {
            buf[pos] = i;
            dfs(pos+1);
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        memset(G, 0, sizeof(G));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int a, b; scanf("%d%d", &a, &b);
            G[a][b] = 1;
            G[b][a] = 1;
        }
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * 2) % MOD;
        }
        cnt = 0;
        dfs(1);
        ans = (ans - cnt % MOD + MOD) % MOD;
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

