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

const int MAXN = 5e5 + 5;
struct BIT {
    int bit[MAXN], n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }
    void add(int i, int x) {
        for(; i <= n; i += lowbit(i)) {
            bit[i] += x;
        }
    }
    int sum(int i) {
        int res = 0;
        for(; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;

int V[MAXN], cnt_v;
int ID(int x) {
    return lower_bound(V, V + cnt_v, x) - V + 1;
}
struct Data {
    int x, y, a, b, op;
    Data() {}
    Data(int x, int y, int a, int b, int op):
        x(x), y(y), a(a), b(b), op(op) {}
    bool operator < (const Data &b) const {
        if (y == b.y) return op > b.op;
        else return y < b.y;
    }
}data[MAXN];
int cnt_d;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        cnt_v = 0, cnt_d = 0;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            V[cnt_v++] = x1;
            V[cnt_v++] = y1;
            V[cnt_v++] = x2;
            V[cnt_v++] = y2;
            if(x1 == x2) {
                if(y1 > y2) swap(y1, y2);
                data[cnt_d++] = Data(x1, y1, 0, 0, 1);
                data[cnt_d++] = Data(x1, y2, 0, 0, -1);
            } else {
                if(x1 > x2) swap(x1, x2);
                data[cnt_d++] = Data(0, y1, x1, x2, 0);
            }
        }
        sort(V, V + cnt_v);
        cnt_v = unique(V, V + cnt_v) - V;
        sort(data, data + cnt_d);
        bit.init(cnt_v);
        ll ans = 0;
        for (int i = 0; i < cnt_d; i++) {
            if(data[i].op == 0) {
                int l = ID(data[i].a) - 1, r = ID(data[i].b);
                ans += bit.sum(r) - bit.sum(l);
            } else {
                int x = ID(data[i].x);
                bit.add(x, data[i].op);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

