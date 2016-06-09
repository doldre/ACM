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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1000 + 5;
int N, M;
vector<int> G[maxn], T[maxn];
int con[maxn][maxn];

int dfn[maxn], low[maxn], sccid[maxn], dfsNum, scc, in[maxn];
int stk[maxn], top;
void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    in[u] = true;
    stk[top++] = u;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfn[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        while(true) {
            int v = stk[--top];
            sccid[v] = scc;
            in[v] = false;
            if(u == v) break;
        }
    }
}

int match[maxn], used[maxn];

void dfs(int s, int v) {
    for(int i = 0; i < (int)T[v].size(); i++) {
        int u = T[v][i];
        if(used[u]) continue;
        used[u] = true;
        dfs(s, u);
        if(con[s][u] == 0) {
            T[s].push_back(u);
            con[s][u] = 1;
        }
    }
}


void transer() {
    for (int i = 1; i <= scc; i++) {
        memset(used, 0, sizeof(used));
        dfs(i, i);
    }
}


bool bin_match(int u) {
    for (int i = 0; i < (int)T[u].size(); i++) {
        int v = T[u][i];
        if(used[v]) continue;
        used[v] = true;
        if(match[v] == -1 || bin_match(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int tt;
    scanf("%d", &tt);
    for (int Cas = 1; Cas <= tt; Cas++) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++) G[i].clear(), T[i].clear();
        memset(con, 0, sizeof(con));
        for (int i = 1; i <= M; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        memset(dfn, -1, sizeof(dfn));
        top = 0;
        scc = dfsNum = 0;
        for (int i = 1; i <= N; i++) {
            if(dfn[i] == -1) tarjan(i);
        }

        for (int i = 1; i <= N; i++) {
            int u = sccid[i];
            for (int j = 0; j < (int)G[i].size(); j++) {
                int v = sccid[G[i][j]];
                if(u == v) continue;
                if(con[u][v] == 0) {
                    T[u].push_back(v);
                    con[u][v] = 1;
                }
            }
        }
        transer();
        memset(match, -1, sizeof(match));
        int matches = 0;
        for (int i = 1; i <= scc; i++) {
            memset(used, 0, sizeof(used));
            matches += bin_match(i);
        }
        printf("Case %d: %d\n", Cas, scc - matches);
    }
    return 0;
}
