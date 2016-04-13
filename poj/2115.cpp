
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#define abs(x) (x >= 0 ? x : -x)
using namespace std;
typedef long long ll;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll res = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return res;
}

//ax = c mod (b)
ll solve(ll a, ll b, ll c) {
    ll x, y;
    ll g =  ex_gcd(a, b, x, y);
    if (c % g != 0) return -1;
    x *= c / g;
    b /= g;
    b = abs(b);
    x = (x % b + b) % b;
    return x;
}

int main() {
    ll A, B, C, k;
    while(cin >> A >> B >> C >> k) {
        if(A == 0 && B == 0 && C == 0 && k == 0) break;
        ll D = (1ll<<k);
        ll x = solve(C, D, B - A);
        if(x == -1) {
            printf("FOREVER\n");
        } else {
            cout << x << endl;
        }
    }
    return 0;
}
