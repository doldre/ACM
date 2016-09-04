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
const int MAXN = 2000 + 5;
struct BIT {
    ll bit[MAXN][MAXN];
    int n, m;
    void init(int n, int m) {
        this->n = n; this->m = m;
        memset(bit, 0, sizeof(bit));
    }
    void update(int x, int y, int w) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                bit[i][j] += w;
            }
        }
    }
    ll sum(int x, int y) {
        ll res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                res += bit[i][j];
            }
        }
        return res;
    }
}bit;

bool last[MAXN], cur[MAXN];
int n, m, k;
struct Node {
    int x, y, w;
};
vector<Node> G[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        int len; scanf("%d", &len);
        while(len--) {
            Node x;
            scanf("%d%d%d", &x.x, &x.y, &x.w);
            G[i].push_back(x);
        }
    }
    int q;
    memset(cur, true, sizeof(cur));
    bit.init(n, m);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        char op[20];
        scanf("%s", op);
        if(op[0] == 'S') {
            int x;
            scanf("%d", &x);
            cur[x] ^= 1;
        } else {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            for (int i = 1; i <= k; i++) {
                if(last[i] != cur[i]) {
                    if(cur[i] == true) {
                        for (auto &x: G[i]) {
                            bit.update(x.x, x.y, x.w);
                        }
                    } else {
                        for (auto &x: G[i]) {
                            bit.update(x.x, x.y, -x.w);
                        }
                    }
                    last[i] = cur[i];
                }
            }
            ll res = bit.sum(x2, y2) - bit.sum(x1 - 1, y2) - 
                bit.sum(x2, y1 - 1) + bit.sum(x1 - 1, y1 - 1);
            printf("%lld\n", res);
        }
    }
    return 0;
}

