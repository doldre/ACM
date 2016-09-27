#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
struct Matrix {
    ll a[4][4];
    Matrix () {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                a[i][j] = i == j;
            }
        }
    }
    Matrix operator * (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};

Matrix mat_pow(Matrix A, ll n) {
    Matrix res;
    res.one();
    while(n > 0) {
        if(n & 1) {
            res = res * A;
        }
        n >>= 1;
        A = A * A;
    }
    return res;
}

int main() {
    Matrix A;
    A.a[0][0]  = A.a[0][2] = 1;
    A.a[1][0]  = A.a[1][2] = 1;
    A.a[2][3] = A.a[3][1] = A.a[3][3] = 1;
    Matrix o;
    for (int i = 0; i < 4; i++) {
        o.a[i][0] = 1;
    }
    ll n;
    cin >> n;
    if(n < 2) puts("1");
    else {
        Matrix res = mat_pow(A, n-2) * o;
        ll ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = (ans + res.a[i][0]) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
