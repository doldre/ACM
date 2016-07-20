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
const int maxn = 1e6 + 5;
int A[maxn];
bool used[maxn];
vector<int> G[maxn];
int n, m;
void dfs(int u, vector<int> &pos, vector<int> &val) {
    used[u] = true;
    pos.push_back(u); val.push_back(A[u]);
    for (auto v: G[u]) {
        if(!used[v]) {
            dfs(v, pos, val);
        }
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        vector<int> pos, val;
        if(!used[i]) {
            dfs(i, pos, val);
            sort(val.begin(), val.end(), greater<int>());
            sort(pos.begin(), pos.end());
            for (int i = 0; i < (int)pos.size(); i++) {
                A[pos[i]] = val[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", A[i], i == n ? '\n' : ' ');
    }
    return 0;
}

