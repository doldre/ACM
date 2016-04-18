#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod0 = 410338673ll;
const ll mod1 = 386201104ll;
const ll mod2 = 181741696ll;
ll fast_pow(ll x, int n, ll mod) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}


mat mul(mat &A ,mat &B, ll mod)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0;i < A.size();i++)
    {
        for(int k = 0;k < B.size();k++)
        {
            for(int j = 0;j < B[0].size();j++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

mat mat_pow(mat &A, int n, ll mod) {
   mat C(A.size(), vec(A[0].size()));
   int len = A.size();
   for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
        if(i == j) C[i][j] = 1;
        else C[i][j] = 0;
    }
   }
   while(n) {
        if(n & 1) {
            C = mul(C, A, mod);
        }
        A = mul(A, A, mod);
        n >>= 1;
   }
   return C;
}
int main() {
    //mat A = {{4, 2, 1, 0}, {0, 1, 0, 0}, {0, 2, 1, 1}, {0, 0, 0, 1}};
    mat A(4, vec(0, 4));
    A[0][0] = 4;
    A[0][1] = 2;
    A[0][2] = 1;
    A[1][1] = 1;
    A[2][1] = 2;
    A[2][2] = 1;
    A[2][3] = 1;
    A[3][3] = 1;

    ll k;
    while(cin >> k) {
        ll c = fast_pow(10, k, mod1);
        cout << c << endl;
        //mat X = {{0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}, {2, 0, 0, 0}};
        mat X(4, vec(0, 4));
        X[2][0] = 2;
        X[3][0] = 2;
        mat ans = mat_pow(A, c - 1, mod0);
        cout << ans[0][1] << endl;
    }
    return 0;
}
