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
vector<int> G[maxn];
int low[maxn], dfn[maxn], dfsNum;
int cnt[maxn];

void dfs(int u) {
    dfn[u]= low[u] = ++dfsNum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfn[v] == -1) {
            dfs(v);
            if(u == 1) cnt[u]++;
            if(u != 1 && low[v] >= dfn[u]) cnt[u]++;
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int u, v;
    int Case = 0;
    while(scanf("%d", &u) == 1 && u) {
        for (int i = 0; i < maxn; i++) G[i].clear();
        scanf("%d", &v);
        G[u].push_back(v);
        G[v].push_back(u);
        while(scanf("%d", &u) && u) {
            scanf("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(dfn, -1, sizeof(dfn));
        dfsNum = 0;
        memset(cnt, 0, sizeof(cnt));
        dfs(1);
        cnt[1]--;
        bool flag = false;
        if(Case > 0) puts("");
        printf("Network #%d\n", ++Case);
        for (int i = 1; i < maxn; i++) {
            if(cnt[i] > 0) {
                printf("  SPF node %d leaves %d subnets\n", i, cnt[i] + 1);
                flag = true;
            }
        }
        if(!flag) {
            printf("  No SPF nodes\n");
        }
    }
    return 0;
}

