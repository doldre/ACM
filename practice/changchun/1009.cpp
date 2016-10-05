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
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 2e5 + 5;
struct SegT {
    struct Node {
        int ch[2], v;
        Node() {
            memset(ch, 0, sizeof(ch));
            v = 0;
        }
    }nds[MAXN*50];
    int tot; 
    int root[MAXN<<1];
    void init() {
        memset(root, 0, sizeof(root));
        tot = 0;
    }
    int new_node() {
        nds[++tot] = Node();
        return tot;
    }
   
    void push_up(int rt) {
        nds[rt].v = nds[nds[rt].ch[0]].v + nds[nds[rt].ch[1]].v;
    }

    void update(int p, int x, int l, int r, int &a, int b) {
        // pr(p); pr(l); prln(r);
        a = new_node();
        nds[a] = nds[b];
        if(l == r) {
            nds[a].v += x;
            return;
        }
        int m = (l + r) >> 1;
        if(p <= m) update(p, x, l, m, nds[a].ch[0], nds[b].ch[0]);
        else if(p > m) update(p, x, m+1, r, nds[a].ch[1], nds[b].ch[1]);
        push_up(a);
    }
    
    int query_cnt(int rt, int L, int R, int l, int r) {
        if(L <= l && r <= R) {
            return nds[rt].v;
        }
        int m = (l + r) >> 1;
        int ans = 0;
        if(L <= m) ans += query_cnt(nds[rt].ch[0], L, R, l, m);
        if(m < R) ans += query_cnt(nds[rt].ch[1], L, R, m+1, r);
        return ans;
    }

    int query(int rt, int x, int l, int r) {
        if(l == r) return l;
        int m = (l + r) >> 1;
        if(x > nds[nds[rt].ch[0]].v) {
            x -= nds[nds[rt].ch[0]].v;
            return query(nds[rt].ch[1], x, m+1, r);
        } else {
            return query(nds[rt].ch[0], x, l, m);
        }
    }
}seg;
int n, m;
int A[MAXN], last[MAXN];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        seg.init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        memset(last, -1, sizeof(last));
        for (int i = n; i >= 1; i--) {
            if(last[A[i]] == -1) {
                seg.update(1, 0, 1, n, seg.root[2*i], seg.root[2*i+1]);
            } else {
                seg.update(last[A[i]], -1, 1, n, seg.root[2*i], seg.root[2*i+1]);
            }
            last[A[i]] = i;
            seg.update(i, 1, 1, n, seg.root[2*i-1], seg.root[2*i]);
        }
        int last_ans = 0;
        printf("Case #%d:", Cas);
        while(m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            int nl = min((l + last_ans) % n + 1, (r + last_ans) % n + 1);
            int nr = max((l + last_ans) % n + 1, (r + last_ans) % n + 1);
            int k = seg.query_cnt(seg.root[2*nl-1], nl, nr, 1, n);
            k = (k + 1) / 2;
            last_ans = seg.query(seg.root[2*nl-1], k, 1, n);
            printf(" %d", last_ans);
        }
        puts("");
    }
    return 0;
}

