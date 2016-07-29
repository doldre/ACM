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
const int maxn = 50000 + 5;

struct Bit {
    int bit[maxn];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
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



struct SegTree {
    int sum[maxn << 2];

    void init() {
        memset(sum, 0, sizeof(sum));
    }

    void push_up(int rt) {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }

    void build(int l, int r, int rt) {
        if(l == r) {
            scanf("%d", &sum[rt]);
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }

    void modify(int p, int add, int l, int r, int rt) {
        if(l == p && r == p) {
            sum[rt] += add;
            return;
        }
        int m = (l + r) >> 1;
        if(p <= m) modify(p, add, lson);
        if(m < p) modify(p, add, rson);
        push_up(rt);
    }

    int querry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return sum[rt];
        }
        int m = (l + r) >> 1;
        int res = 0;
        if(L <= m) res += querry(L, R, lson);
        if(m <  R) res += querry(L, R, rson);
        return res;
    }
}segtree;

int A[maxn];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        printf("Case %d:\n", Cas);
        int n; scanf("%d", &n);
        // segtree.build(1, n, 1);
        bit.init(n);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            bit.add(i, x);
        }
        char op[200];
        while(scanf("%s", op) == 1) {
            if(op[0] == 'Q') {
                int i, j;
                scanf("%d%d", &i, &j);
                printf("%d\n", bit.sum(j) - bit.sum(i-1));
            } else if(op[0] == 'A') {
                int i, j;
                scanf("%d%d", &i, &j);
                bit.add(i, j);
            } else if(op[0] == 'S') {
                int i, j;
                scanf("%d%d", &i, &j);
                bit.add(i, -j);
            } else {
                break;
            }
        }
    }
    return 0;
}

