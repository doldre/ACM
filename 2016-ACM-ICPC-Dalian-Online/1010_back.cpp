#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
int A[maxn], beg[maxn], ed[maxn];
int n;
ll k;
vector<int> G[maxn];
int deg[maxn];
int dfsNum;
int bit[maxn*4], bit_n;
void init(int n) {
    memset(bit, 0, sizeof(bit));
    bit_n = 2*n;
    dfsNum = 0;
    for (int i = 0; i <= n; i++) G[i].clear();
    memset(deg, 0, sizeof(deg));
}

void add(int i) {
    for (; i <= bit_n; i += i & -i) {
        bit[i]++;
    }
}

int sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & - i) {
        res += bit[i];
    }
    return res;
}

void dfs(int u, int fa) {
    beg[u] = ++ dfsNum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
    }
    ed[u] = dfsNum;
}

struct Node {
    int id, v;
    bool operator < (const Node &b) const {
        return v < b.v;
    }
}nds[maxn];

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &n, &k);
        init(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            nds[i].id = i;
            nds[i].v = A[i];
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
            deg[b]++;
        }
        int root = 1;
        for (; deg[root] != 0; root++);
        dfs(root, -1);
        sort(nds + 1, nds + n + 1);
        int j = 1;
        ll ans = 0;
        for (int i = n; i >= 1; i--) {
            ll t = k / nds[i].v;
            for (; j <= n && nds[j].v <= t; j++) {
                add(beg[nds[j].id]);
            }
            ans += sum(ed[nds[i].id]) - sum(beg[nds[i].id]);
        }
        cout << ans << endl;
    }
    return 0;
}

