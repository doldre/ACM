//
//  Created by TaoSama on 2016-05-27
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N], T[N];

int dfn[N], low[N], in[N], id[N], scc, dfsNum;
int stk[N], top;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++scc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = scc;
            if(v == u) break;
        }
    }
}

bool vis[N];
int match[N];
bool dfs(int u) {
    for(int i = 0; i < T[u].size(); ++i) {
        int v = T[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\input.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear(), T[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }

        scc = dfsNum = 0;
        memset(dfn, 0, sizeof dfn);
        for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);

        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j = 0; j < G[i].size(); ++j) {
                int v = id[G[i][j]];
                if(u == v) continue;
                T[u].push_back(v);
            }
        }

        int matches = 0;
        memset(match, -1, sizeof match);
        for(int i = 1; i <= scc; ++i) {
            memset(vis, 0, sizeof vis);
            matches += dfs(i);
        }
        printf("%d\n", scc - matches);
    }
#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
