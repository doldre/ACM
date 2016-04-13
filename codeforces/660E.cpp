#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = (ll)(1e9) + 7;

int main() {
    ll n, m;
    cin >> n >> m;
    ll tmp = 1;
    ll ans = 2*m;
    for (int i = 2; i <= n; i++) {
        tmp = tmp * m % mod;
        ans = (ans * (2 * m - 1) % mod + tmp + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
