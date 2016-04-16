#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a, b, c, p;
ll mod;
ll cal_cir(ll a, ll p) {
    ll r = a % p;
    int res = 2;
    ll t = a * a% p;
    for (; t != r; t = t * a % p, res++);
    return res - 1;
}

vector<vector<ll> > multi(vector<vector<ll> > A, vector<vector<ll> > B) {
    vector<vector<ll> > res = A;
    int len = A.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return res;
}

ll fast_pow(ll a, ll n) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = res * a % p;
        }
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}
vector<vector<ll> > mat_pow(vector<vector<ll> > mat, ll n) {
    int len = mat.size();
    vector<vector<ll> > res = mat;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(i == j) {
                res[i][j] = 1;
            } else res[i][j] = 0;
        }
    }

    while(n) {
        if(n & 1) {
            res = multi(res, mat);
        }
        mat = multi(mat, mat);
        n >>= 1;
    }
    return res;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> a >> b >> c >> p;
        if(a % p == 0) {
            cout << 0 << endl;
            continue;
        }
        mod = p - 1;
        vector<vector<ll> > mat;
        vector<ll> ta(3);
        ta[0] = 1; ta[1] = 0; ta[2] = 0;
        mat.push_back(ta);
        ta[0] = 1; ta[1] = c; ta[2] = 1;
        mat.push_back(ta);
        ta[0] = 0; ta[1] = 1; ta[2] = 0;
        mat.push_back(ta);
        vector<vector<ll> > A;
        ta[0] = b; ta[1] = 0; ta[2] = 0;
        A.push_back(ta);
        ta[0] = b; ta[1] = 0; ta[2] = 0;
        A.push_back(ta);
        ta[0] = 0; ta[1] = 0; ta[2] = 0;
        A.push_back(ta);
        vector<vector<ll> > B = multi(mat_pow(mat, n - 1), A);
        ll k = B[2][0];
        cout << fast_pow(a, k) << endl;
    }
    return 0;
}
