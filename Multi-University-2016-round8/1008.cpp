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
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1|1
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 1e5 + 5;
int A[MAXN];
struct SegT {
    ll sum[MAXN<<2];
    ll is_same[MAXN<<2], lazy[MAXN<<2];
    void init() {
        memset(sum, 0, sizeof(sum));
        memset(is_same, 0, sizeof(is_same));
        memset(lazy, 0, sizeof(lazy));
    }
   
    void push_up(int rt) {
        if(is_same[rt << 1] && is_same[rt << 1 | 1] &&
                is_same[rt << 1] == is_same[rt << 1 | 1]) {
            is_same[rt] = is_same[rt << 1];
        } else {
            is_same[rt] = 0;
        }
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void push_down(int rt, int l, int r) {
        int m = (l + r) >> 1;
        if(is_same[rt]) {
            is_same[rt << 1] = is_same[rt];
            is_same[rt << 1 | 1] = is_same[rt];
            sum[rt << 1] = is_same[rt] * (m - l + 1);
            sum[rt << 1 | 1] = is_same[rt] * (r - m);
        } else {
            lazy[rt << 1] += lazy[rt];
            lazy[rt << 1 | 1] += lazy[rt];
            sum[rt << 1] += lazy[rt] * (m - l + 1);
            sum[rt << 1 | 1] += lazy[rt] * (r - m);
            lazy[rt] = 0;
            if(is_same[rt << 1]) {
                is_same[rt << 1] += lazy[rt << 1];
                lazy[rt << 1] = 0;
            }
            if(is_same[rt << 1 | 1]) {
                is_same[rt << 1 | 1] += lazy[rt << 1 | 1];
                lazy[rt << 1 | 1] = 0;
            }
        }
    }
    
    void build(int l, int r, int rt) {
        if(l == r) {
            sum[rt] = A[l];
            is_same[rt] = A[l];
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }

    void update1(int L, int R, int x, int l, int r, int rt) {
        if(L <= l && r <= R) {
            sum[rt] += (ll)x * (r - l + 1);
            if(is_same[rt]) {
                is_same[rt] += x;
            } else {
                lazy[rt] += x;
            }
            return;
        }
        int m = (l + r) >> 1;
        push_down(rt, l, r);
        if(m >= L) update1(L, R, x, lson);
        if(m < R) update1(L, R, x, rson);
        push_up(rt);
    }

    void update2(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R && is_same[rt]) {
            is_same[rt] = sqrt(is_same[rt]);
            sum[rt] = is_same[rt] * (r - l + 1);
            return;
        }
        int m = (l + r) >> 1;
        push_down(rt, l, r);
        if(m >= L) update2(L, R, lson);
        if(m < R) update2(L, R, rson);
        push_up(rt);
    }

    ll query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return sum[rt];
        }
        int m = (l + r) >> 1;
        push_down(rt, l, r);
        ll res = 0;
        if(m >= L) res += query(L, R, lson);
        if(m <  R) res += query(L, R, rson);
        return res;
    }
}seg;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        seg.init();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        seg.build(1, n, 1);
        for (int i = 0; i < m; i++) {
            int op;
            scanf("%d", &op);
            if(op == 1) {
                int l, r, x;
                scanf("%d%d%d", &l, &r, &x);
                seg.update1(l, r, x, 1, n, 1);
            } else if(op == 2) {
                int l, r;
                scanf("%d%d", &l, &r);
                seg.update2(l, r, 1, n, 1);
            } else if(op == 3) {
                int l, r;
                scanf("%d%d", &l, &r);
                ll res = seg.query(l, r, 1, n, 1);
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}

