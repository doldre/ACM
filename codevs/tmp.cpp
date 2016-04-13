#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;
int A[maxn];
ll f(ll x) {
    return x*(x + 1) / 2;
}
int main() {
    ll n;
    cin >> n;
    if(n == 1) {
        cout << "1/1" << endl;
        return 0;
    }
    ll l = 1, r = 1e5;
    n--;
    while(l < r - 1) {
        ll m = (l + r) / 2;
        if(f(m) <= n) {
            l = m;
        } else r = m;
    }
    ll t = n - f(l);
    if(l % 2) {
        cout << (t + 1) << "/"<< (l + 1 - t) << endl;
    } else {
        cout << (l + 1 - t) << "/" << (t + 1) << endl;
    }
    return 0;
}
