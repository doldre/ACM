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
const ll MOD = 1e9 + 7;

struct Matrix {
    ll a[4][4];
    int n, m;
    Matrix() {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        memset(a, 0, sizeof(a));
    }
    void I() {
        for (int i = 0; i < n; i++) {
            a[i][i] = 1;
        }
    }

    Matrix operator * (const Matrix rhs) const {
        Matrix res(n, rhs.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rhs.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};
   
Matrix mat_pow(Matrix a, ll n) {
    Matrix res(a.n, a.m);
    res.I();
    while(n > 0) {
        if(n & 1) {
            res = res * a;
        }
        n >>= 1;
        a = a * a;
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        ll k;
        scanf("%lld", &k);
        Matrix A(4, 4);
        A.a[0][0] = 4, A.a[0][1] = 1; A.a[0][2] = 1; A.a[0][3] = 0;
        A.a[1][0] = 1, A.a[1][1] = 4; A.a[1][2] = 0; A.a[1][3] = 1;
        A.a[2][0] = 1, A.a[2][1] = 0; A.a[2][2] = 4; A.a[2][3] = 1;
        A.a[3][0] = 0, A.a[3][1] = 1; A.a[3][2] = 1; A.a[3][3] = 4;
        Matrix res(4, 1);
        res.a[0][0] = 1;
        res = mat_pow(A, k) * res;
        printf("Case #%d: %lld\n", Cas, res.a[0][0]);
    }
    return 0;
}

