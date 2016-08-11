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

const int MAXN = 1e6 + 5;
struct Seg_Tree {
    int sum[MAXN << 2];
    int lazy[MAXN << 2];
    void push_up(int rt) {
        sum[rt] = sum[rt << 1] ^ sum[rt << 1 | 1];
    }

    void push_down(int rt) {
        if(lazy[rt]) {
            sum[rt << 1] ^= lazy[rt];
            lazy[rt << 1] ^= lazy[rt];
            sum[rt << 1 | 1] ^= lazy[rt];
            lazy[rt << 1 | 1] ^= lazy[rt];
            lazy[rt] = 0;
        }
    }

    void update(int L, int R, int val, int l, int r, int rt) {
        if(L <= l && r <= R) {
            sum[rt] ^= val;
            lazy[rt] ^= val;
            return;
        }
        int m = (l + r) >> 1;
        push_down(rt);
        if(m >= L) update(L, R, val, l, m, rt << 1);
        if(m < R) update(L, R, val, m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    int query(int p, int l, int r, int rt) {
        if(l == r) {
            return sum[rt];
        }
        int m = (l + r) >> 1;
        push_down(rt);
        if(p <= m) {
            return query(p, l, m, rt << 1);
        } else return query(p, m + 1, r, rt << 1 | 1);
    }
}seg;

struct Query {
    int l, r, num;
    bool operator < (const Query &b) const {
        return r < b.r;
    }
}q[MAXN];

int A[MAXN], ans[MAXN];
map<int, int> mp;
int n, m;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].num = i;
    }
    sort(q, q + m);
    int j = 1;
    for (int i = 0; i < m; i++) {
        while(j <= q[i].r) {
            if(mp[A[j]]) {
                // prln(mp[A[j]]);
                seg.update(1, mp[A[j]], A[j], 1, n, 1);
            }
            mp[A[j]] = j;
            j++;
        }
        ans[q[i].num] = seg.query(q[i].l, 1, n, 1);
        // pr(q[i].l); prln(q[i].r);
        // prln(ans[q[i].num]);
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

