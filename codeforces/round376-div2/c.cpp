#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;
int C[MAXN];
int cnt[MAXN], flag[MAXN];
int used[MAXN];
int tim;
vector<int> G[MAXN];

int ma;
int dfs(int u) {
    if(used[u] == tim) return 0;
    used[u] = tim;
    int c = C[u];
    if(flag[c] != tim) {
        flag[c] = tim;
        cnt[c] = 0;
    }
    cnt[c]++;
    if(cnt[c] > ma) ma = cnt[c];
    int res = 1;
    for (int v: G[u]) {
        res += dfs(v);
    }
    return res;
}
int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        G[l].push_back(r);
        G[r].push_back(l);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(!used[i]) {
            ++tim;
            ma = 0;
            int tot = dfs(i);
            ans += tot - ma;
        }
    }
    cout << ans << endl;
    return 0;
}
