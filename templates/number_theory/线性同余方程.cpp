//POJ 1061 青蛙的约会
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
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll ans = solve(m - n, L, y - x);
    if(ans == -1) cout << "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}
