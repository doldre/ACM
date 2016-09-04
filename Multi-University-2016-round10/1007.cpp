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
const ll mod = 1e9 + 7;
const int N = 30;
struct Matrix {
    ll a[N][N];
    int n, m;
    Matrix() {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix(int n, int m):n(n), m(m) {
        memset(a, 0, sizeof(a));
    }
    void show() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%lld ", a[i][j]);
            }
            puts("");
        }
    }
    void I() {
        for (int i = 0; i < n; i++) {
            a[i][i] = 1;
        }
    }
    Matrix operator * (const Matrix &b) const {
        Matrix c(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                c.a[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return c;
    }
};

Matrix mat_pow(Matrix x, int n) {
    Matrix res(x.n, x.m);
    res.I();
    while(n > 0) {
        if(n & 1) {
            res = res * x;
        }
        n >>= 1;
        x = x * x;
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        Matrix A(2 * (m + 1), 2 * (m + 1));
        for (int i = 0; i < m; i++) {
            A.a[0][i] = k * (k - 1);
        }
        for (int i = 1; i <= m; i++) {
            A.a[i][i-1] = k;
        }
        for (int i = m; i <= 2 * (m + 1); i++) {
            A.a[m+1][i] = k * (k - 1);
        }
        for (int i = m + 2; i <= 2*m + 1; i++) {
            A.a[i][i-1] = k;
        }
        Matrix res(2 * (m + 1), 1);
        res.a[0][0] = 1;
        res = mat_pow(A, n) * res;
        ll ans = 0;
        for (int i = m; i <= 2 * m + 1; i++) {
            ans = (ans + res.a[i][0]) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

