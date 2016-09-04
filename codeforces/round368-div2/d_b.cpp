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

const int MAXQ = 1e5 + 5;
const int MAXN = 1e3 + 5;
struct Node {
    int op, a, b;
    vector<int> nxt;
}node[MAXQ];

bool A[MAXN][MAXN];
int cnt[MAXN];
bool flag[MAXN];
int res[MAXQ];
int n, m, q;

void dfs(int u, int ans) {
    int bac = A[node[u].a][node[u].b];
    int cnt_bac = cnt[node[u].a];
    if(node[u].op == 1) {
        if(A[node[u].a][node[u].b] != flag[node[u].a]) {
            cnt[node[u].a]++;
            ans++;
            A[node[u].a][node[u].b] = flag[node[u].a];
        }
    } else if(node[u].op == 2) {
        if(A[node[u].a][node[u].b] == flag[node[u].a]) {
            cnt[node[u].a]--;
            ans--;
            A[node[u].a][node[u].b] = !flag[node[u].a];
        }
    } else if(node[u].op == 3) {
        flag[node[u].a] = !flag[node[u].a];
        ans -= cnt[node[u].a];
        cnt[node[u].a] = m  - cnt[node[u].a];
        ans += cnt[node[u].a];
    } 
    res[u] = ans;
    for (auto v: node[u].nxt) {
        dfs(v, ans);
    }
    int op = node[u].op;
    if(op == 1 || op == 2) {
        A[node[u].a][node[u].b] = bac;
        cnt[node[u].a] = cnt_bac;
    } else if(op == 3) {
        flag[node[u].a] = !flag[node[u].a];
        cnt[node[u].a] = cnt_bac;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i++) {
        int op, a, b;
        scanf("%d", &op);
        if(op == 1 || op == 2) {
            scanf("%d%d", &a, &b);
            node[i-1].nxt.push_back(i);
            node[i].op = op; node[i].a = a; node[i].b = b;
        } else if(op == 3) {
            scanf("%d", &a);
            node[i-1].nxt.push_back(i);
            node[i].op = op; node[i].a = a;
        } else if(op == 4) {
            scanf("%d", &a);
            node[a].nxt.push_back(i);
            node[i].op = 4;
        }
    }
    memset(flag, true, sizeof(flag));
    dfs(0, 0);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}

