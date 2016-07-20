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

const int maxn = 1e5 + 5;
int A[maxn];
int N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct SegT {
    int a[maxn<<2];

    void push_up(int rt) {
        a[rt] = gcd(a[rt<<1], a[rt<<1|1]);
        // pr(rt);
        // prln(a[rt]);
    }

    void init() {
        memset(a, 0, sizeof(a));
    }

    void build(int l, int r, int rt) {
        if(l == r) {
            a[rt] = A[l - 1];
            // pr(rt); prln(a[rt]);
            return;
        }
        int m = (l + r) >> 1;
        if(l <= m) build(l, m, rt << 1);
        if(m < r) build(m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    int querry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return a[rt];
        }
        int m = (l + r) >> 1;
        int res = 0;
        if(L <= m) res = gcd(res, querry(L, R, l, m, rt << 1));
        if(m < R) res = gcd(res, querry(L, R, m + 1, r, rt << 1 | 1));
        return res;
    }
}seg;
int nxt[maxn];
long long sum[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        map<int, long long> m;
        int q, j, pre;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            nxt[i] = i + 1;
        }
        seg.init();
        seg.build(1, N, 1);
        for (int i = N - 1; i >= 0; i--) {
            pre = i;
            for (j = i; j < N; j = nxt[j]) {
                A[j] = gcd(A[j], A[pre]);
                if(A[j] == A[pre]) nxt[pre] = nxt[j];
                m[A[j]] += (nxt[j] - j);
                pre = j;
            }
        }
        scanf("%d", &q);
        printf("Case #%d:\n", Cas);
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            int a = seg.querry(l, r, 1, N, 1);
            int b = m[a];
            printf("%d %d\n", a, b);
        }
    }
    return 0;
}

