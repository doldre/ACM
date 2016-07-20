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
const ll MOD = 1e9 + 7;
const int maxn = 110;
struct Matrix {
    ll a[maxn][maxn];
    int n, m;
    Matrix() {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    
    Matrix(int n, int m): n(n), m(m) {
        memset(a, 0, sizeof(a));
    }

    void I() {
        for (int i = 0; i < n; i++) a[i][i] = 1;
    }

    void zero() {
        memset(a, 0, sizeof(0));
    }
    
    Matrix operator * (const Matrix &b) const {
        Matrix res(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }

        return res;
    }
};

Matrix mat_pow(Matrix a, ll n) {
    Matrix res(a.n, a.m);
    res.I();
    while(n) {
        if(n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    Matrix dp(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(__builtin_popcountll(A[i] ^ A[j]) % 3 == 0) {
                dp.a[i][j] = 1;
            }
        }
    }

    dp = mat_pow(dp, k - 1);
    Matrix ans(n, 1);
    for (int i = 0; i < n; i++) ans.a[i][0] = 1;
    ans = dp * ans;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + ans.a[i][0]) % MOD;
    }
    printf("%lld\n", res);
    return 0;
}

