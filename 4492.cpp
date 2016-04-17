#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef ll mat[4][4];
const ll mod0 = 410338673ll;
const ll mod1 = 386201104ll;
const ll mod2 = 181741696ll;
ll fast_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}


void mul(mat A ,mat B, ll mod)
{
    int len = 4;
    mat C;
    for(int i = 0;i < len; i++)
    {
        for(int j = 0;j < len; j++) {
            C[i][j] = 0;
            for(int k = 0;k < len; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    memcpy(A, C, sizeof(C));
}

void mat_pow(mat A, ll n, ll mod) {
    mat C;
    int len = 4;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(i == j) C[i][j] = 1;
            else C[i][j] = 0;
        }
    }
    while(n > 0) {
        if(n & 1) {
            mul(C, A, mod);
        }
        mul(A, A, mod);
        n >>= 1;
    }
    memcpy(A, C, sizeof(C));
}

ll solve(ll k) {
    ll c = fast_pow(10, k, mod1);
    //cout << c << endl;
    //mat X = {{0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}, {2, 0, 0, 0}};
    mat A;
    memset(A, 0, sizeof(A));
    A[0][0] = 4;
    A[0][1] = 2;
    A[0][2] = 1;
    A[1][2] = 1;
    A[2][1] = 2;
    A[2][2] = 1;
    A[2][3] = 1;
    A[3][3] = 1;
    mat X;
    memset(X, 0, sizeof(X));
    X[2][0] = 2;
    X[3][0] = 2;
    mat_pow(A, c - 1, mod0);
    mul(A, X, mod0);
    return A[0][0];
}
int main() {
    //mat A = {{4, 2, 1, 0}, {0, 1, 0, 0}, {0, 2, 1, 1}, {0, 0, 0, 1}};

    ll k;
    /* for (ll k = 2; k <= 1e8; k++) { */
    /*     if(k % 10000 == 0) { */
    /*         cout << k << endl; */
    /*     } */
    /*     if(solve(k) == 418066) { */
    /*         cout << k << endl; */
    /*         break; */
    /*     } */
    /* } */
    /* cout << "YES\n" << endl; */
    while(scanf("%lld", &k) == 1) {
        printf("%lld\n", solve(k));
    }
    return 0;
}


