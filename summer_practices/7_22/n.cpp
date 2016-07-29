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
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int MAXN = 2e5 + 5;

struct SegTree {
    int res[MAXN<<2];

    void push_up(int rt) {
        res[rt] = max(res[rt << 1], res[rt << 1 | 1]);
    }

    void build(int l, int r, int rt) {
        if(l == r) {
            scanf("%d", &res[rt]);
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return res[rt];
        }
        int m = (l + r) >> 1;
        int tmp = 0;
        if(L <= m) tmp = max(tmp, query(L, R, lson));
        if(m < R ) tmp = max(tmp, query(L, R, rson));
        return tmp;
    }

    void modify(int p, int x, int l, int r, int rt) {
        if(l == p && r == p) {
            res[rt] = x;
            return;
        }
        int m = (l + r) >> 1;
        if(p <= m) modify(p, x, lson);
        if(m <  p) modify(p, x, rson);
        push_up(rt);
    }
}seg;
int N, M;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2) {
        seg.build(1, N, 1);
        for (int i = 0; i < M; i++) {
            char op[20];
            scanf("%s", op);
            if(op[0] == 'Q') {
                int A, B;
                scanf("%d%d", &A, &B);
                int res = seg.query(A, B, 1, N, 1);
                printf("%d\n", res);
            } else {
                int A, B;
                scanf("%d%d", &A, &B);
                seg.modify(A, B, 1, N, 1);
            }
        }
    }
    return 0;
}

