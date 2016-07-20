#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x << " "

const int maxn = 9  + 5;
bool can_adj[maxn][maxn];

int G[2*maxn][2*maxn];
int yin[maxn];
int n, m;

bool vis[maxn*2];
int match[maxn*2];

bool dfs(int u) {
    for (int i = 0; i < 2 * n; i++) {
        if(!G[u][i]) continue;
        int v = i;
        if(!vis[v]) {
            vis[v] = 1;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bin_match() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < 2 * n; i++) {
        if(match[i] == -1) {
            for (int j = 0; j < 2 * n; j++) {
                vis[j] = 0;
            }
            if(dfs(i)) {
                ans++;
            }
        }
    }
    // prln(ans);
    return ans;
}

int solve() {
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(can_adj[i][yin[j]] && can_adj[i][yin[(j+1) % n]]) {
                // pr(i); prln(yin[j]);
                // pr(i); prln(j);
                G[i][j + n] = 1;
                G[j + n][i] = 1;
            }
        }
    }

    return n - bin_match();
}

int work() {
    int ans = n;
    for (int i = 0; i < n; i++) {
        yin[i] = i;
    }

    srand(time(NULL));
    for (int i = 0; i < 200; i++) {
        random_shuffle(yin + 1, yin + n);
        ans = min(ans, solve());
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(can_adj, true, sizeof(can_adj));

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            // pr(u); prln(v);
            can_adj[u][v] = false;
        }
        int ans;
        if(n == 0) {
            ans = 0;
        } else ans = work();
        printf("%d\n", ans);
    }
}

