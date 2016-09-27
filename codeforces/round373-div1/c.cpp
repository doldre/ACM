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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
template<class T> inline T lowbit(T x) { return x & (-x); }
const ll MOD = 1e9 + 7;
struct Matrix {
    ll a[2][2];
    Matrix() {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                a[i][j] = (i == j);
    }
    Matrix operator + (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
            }
        }
        return c;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};

Matrix mat_pow(Matrix a, ll n) {
    Matrix res;
    res.one();
    while(n > 0) {
        if(n & 1) {
        res = res * a;
        }
        n >>= 1;
        a = a * a;
    }
    return res;
}

const int MAXN = 1e5 + 5;

int a[MAXN];
Matrix A, O;
struct Seg {
    Matrix dat[MAXN<<2];
    Matrix lazy[MAXN<<2];
    void push_down(int rt) {
            lazy[rt<<1] = lazy[rt<<1] * lazy[rt];
            lazy[rt<<1|1] = lazy[rt<<1|1] * lazy[rt];
            dat[rt<<1] = lazy[rt] * dat[rt<<1];
            dat[rt<<1|1] = lazy[rt] * dat[rt<<1|1];
            lazy[rt].one();
    }
    void push_up(int rt) {
        dat[rt] = dat[rt<<1] + dat[rt<<1|1];
    }
    void build(int l, int r, int rt) {
        lazy[rt].one();
        if(l == r) {
            dat[rt] = mat_pow(A, a[l] - 1) * O;
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }
    void modify(int L, int R, Matrix x, int l, int r, int rt) {
        if(L <= l && r <= R) {
            dat[rt] = x * dat[rt];
            lazy[rt] = x * lazy[rt];
            return;
        }
        int m = (l + r) >> 1;
        push_down(rt);
        if(L <= m) modify(L, R, x, lson);
        if(m < R) modify(L, R, x, rson);
        push_up(rt);
    }
    Matrix query(int L, int R, int l, int r, int rt) {
        Matrix res;
        if(L <= l && r <= R) {
            return dat[rt];
        }
        int m = (l + r) >> 1;
        push_down(rt);
        if(L <= m) res = res + query(L, R, lson);
        if(m < R) res = res + query(L, R, rson);
        return res;
    }
}seg;

int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    A.a[0][0] = 1; A.a[0][1] = 1;
    A.a[1][0] = 1;
    O.a[0][0] = 1;
    O.a[1][0] = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    seg.build(1, n, 1);
    while(m--) {
        int op, l, r, x;
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d%d", &l, &r, &x);
            seg.modify(l, r, mat_pow(A, x), 1, n, 1);
        } else if(op == 2) {
            scanf("%d%d", &l, &r);
            Matrix res = seg.query(l, r, 1, n, 1);
            printf("%lld\n", res.a[1][0]);
        }
    }
    return 0;
}

