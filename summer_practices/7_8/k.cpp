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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 1e5 + 5;
struct SegTree {
    ll sum[maxn<<2];
    bool eqone[maxn<<2];
    
    void push_up(int rt) {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
        eqone[rt] = eqone[rt<<1] && eqone[rt<<1|1];
    }

    void init() {
        memset(sum, 0, sizeof(sum));
        memset(eqone, false, sizeof(eqone));
    }

    void build(int l, int r, int rt) {
        // pr(l); pr(r); prln(rt);
        if(l == r) {
            scanf("%lld", &sum[rt]);
           // pr("leaf");  pr(rt);
            // prln(sum[rt]);
            if(sum[rt] == 1) eqone[rt] = true;
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
        // pr(rt); prln(sum[rt]);
    }

    void update(int L, int R, int l, int r, int rt) {
        if(eqone[rt]) return;
        if(l == r) {
            sum[rt] = sqrt(sum[rt]);
            if(sum[rt] == 1) eqone[rt] = true; 
            return;
        }
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, lson);
        if(m + 1 <= R) update(L, R, rson);
        push_up(rt);
    }

    ll querry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return sum[rt];
        }
        int m = (l + r) >> 1;
        ll res = 0;
        if(L <= m) res += querry(L, R, lson);
        if(m + 1 <= R) res += querry(L, R, rson);
        return res;
    }
}seg;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case = 0;
    int n, m;
    while(scanf("%d", &n) == 1) {
        seg.init();
        seg.build(1, n, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", ++Case);
        for (int i = 0; i < m; i++) {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            if(x > y) swap(x, y);
            if(t == 0) {
                seg.update(x, y, 1, n, 1);
            } else {
                ll res = seg.querry(x, y, 1, n, 1);
                printf("%lld\n", res);
            }
        }
        puts("");
    }
    return 0;
}

