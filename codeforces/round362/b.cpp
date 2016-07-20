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
const int maxn = 1e5 + 5;
int subtree[maxn];
double E[maxn];
vector<int> G[maxn];
int n;
void dfs(int u) {
    subtree[u] = 1;
    for (int v: G[u]) {
        dfs(v);
        subtree[u] += subtree[v];
    }
}

void dfs2(int u) {
    for (auto v: G[u]) {
        E[v] = E[u] + 1 + (double)(subtree[u] - subtree[v] - 1) / 2;
        dfs2(v);
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        G[p].push_back(i);
    }
    dfs(1);
    E[1] = 1;
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        printf("%.9f%c", E[i], i == n ? '\n' : ' ');
    }
    return 0;
}

