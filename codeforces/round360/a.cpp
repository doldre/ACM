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
const int maxn = 1e5 + 7;
vector<int> G[maxn];
vector<int> ans[2];
int used[maxn];
int col[maxn];
bool suc = true;
void dfs(int v, int color) {
    used[v] = true;
    col[v] = color;
    if(!suc) return;
    for (auto u: G[v]) {
        if(used[u] && col[u] == color) {
            suc = false;
            return;
        } else if(used[u] && col[u] != color) {
            continue;
        }
        else if(!used[u]) {
            dfs(u, !color); 
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    suc = true;
    for (int i = 1; i <= n; i++) {
        if(used[i] == false) {
            dfs(i, 0);
        }
    }
    if(!suc) {
        printf("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            ans[col[i]].push_back(i);
        }
        printf("%d\n", (int)ans[0].size());
        for (auto x: ans[0]) {
            printf("%d ", x);
        }
        puts("");
        printf("%d\n", (int)ans[1].size());
        for (auto x: ans[1]) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}

