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

const int MAXN = 1e5 + 5;
int A[MAXN];
int L[MAXN], R[MAXN];
int N;
ll k;
vector<int> G[MAXN];
int degree[MAXN];
int dfsNum;

struct BIT {
    int bit[MAXN*4], n;
    void init(int n) {
        memset(bit, 0, sizeof(bit));
        this->n = n;
    }
    void add(int i, int x) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += x;
        }
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;

void dfs(int u, int fa) {
    L[u] = ++dfsNum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
    }
    R[u] = ++dfsNum;
}

pii buf[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; 
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &N, &k);
        for (int i = 1; i <= N; i++) {
            G[i].clear();
            scanf("%d", &A[i]);
            buf[i] = pii(A[i], i);
        }
        bit.init(N*2);
        memset(degree, 0, sizeof(degree));
        for (int i = 1; i <= N - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            degree[v]++;
        }
        int root = 1;
        while(degree[root]) root++;
        dfsNum = 0;
        dfs(root, -1);
        sort(buf + 1, buf + N + 1);
        int head = 1;
        ll ans = 0;
        for (int i = N; i >= 1;  i--) {
            ll tmp = k / buf[i].xx;
            for (;head <= N && buf[head].xx <= tmp; head++) {
                bit.add(L[buf[head].yy], 1);
            }
            ans += bit.sum(R[buf[i].yy] - 1) - bit.sum(L[buf[i].yy]);
        }
        cout << ans << endl;
    }
    return 0;
}

