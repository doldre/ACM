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

const int MAXN = 100 + 5;
int mp[MAXN][MAXN];
int n, m, s;
int A[MAXN];
int ans = 0;
void dfs(int len, int v[], int cnt) {
    if(cnt == s) {
        ans++;
        return;
    }
    for (int i = 0; i < len; i++) {
        int t = 0;
        int buf[MAXN];
        for (int j = i + 1; j < len; j++) {
            if(mp[v[i]][v[j]]) {
                buf[t++] = v[j];
            }
        }
        dfs(t, buf, cnt + 1);
    }
}
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &s);
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            mp[u-1][v-1] = true;
            mp[v-1][u-1] = true;
        }
        ans = 0;
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = i + 1; j < n; j++) {
                if(mp[i][j]) A[len++] = j;
            }
            dfs(len, A, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

