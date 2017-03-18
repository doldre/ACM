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

const ll MOD = 2147493647ll;

struct Matrix {
    ll m[7][7];
    Matrix() {
        memset(m, 0, sizeof(m));
    }
    void one() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                m[i][j] = i == j;
            }
        }
    }

    Matrix operator * (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 7; k++) {
                    c.m[i][j] = (c.m[i][j] + m[i][k] * b.m[k][j]) % MOD;
                }
            }
        }
        return c;
    }
    void debug_print() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                printf("%lld ", m[i][j]);
            }
            puts("");
        }
    }
};

Matrix fast_pow( Matrix a, ll n) {
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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    Matrix A;
    A.m[0][0] = 1; A.m[0][1] = 2; A.m[0][2] = 1;
    A.m[1][0] = 1;
    A.m[2][2] = 1; A.m[2][3] = 4; 
    A.m[2][4] = 6; A.m[2][5] = 4; A.m[2][6] = 1;
    A.m[3][3] = 1; A.m[3][4] = 3; A.m[3][5] = 3; A.m[3][6] = 1;
    A.m[4][4] = 1; A.m[4][5] = 2; A.m[4][6] = 1;
    A.m[5][5] = 1; A.m[5][6] = 1;
    A.m[6][6] = 1;
    int T; scanf("%d", &T);
    while(T--) {
        int n, a, b; 
        scanf("%d%d%d", &n, &a, &b);
        Matrix x;
        x.m[0][0] = b; 
        x.m[1][0] = a;
        x.m[2][0] = 3*3*3*3;
        x.m[3][0] = 3*3*3;
        x.m[4][0] = 3*3;
        x.m[5][0] = 3;
        x.m[6][0] = 1;
        if(n <= 2) {
            if(n == 1) {
                printf("%d\n", a);
            } else if(n == 2) {
                printf("%d\n", b);
            }
        } else {
            // fast_pow(A, n - 2).debug_print();
            // puts("");
            // x.debug_print();
            // puts("");
            Matrix res = fast_pow(A, n - 2) * x;
            // res.debug_print();
            printf("%lld\n", res.m[0][0]);
        }
    }
    return 0;
}
