#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const ll inf = 1e15;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll res = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return res;
}

int main() {
	ll a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

	ll x0, y0, g;
	if(a == 0 && b == 0 && c != 0) {
		cout << 0 << endl;
		return 0;
	} else if(a == 0 && b == 0 && c == 0) {
		cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
		return 0;
	}
	g = ex_gcd(a, b, x0, y0);
	c = -c;
	if(c % g != 0) {
		cout << 0 << endl;
	} else {
		x0 *= c / g, y0 *= c / g;
		ll k1 = -inf, k2 = inf;
		double t1, t2;
		if(b != 0) {
			t1 = (double)(x2 - x0) * g / b;
			t2 = (double)(x1 - x0) * g / b;
			if(t2 < t1) swap(t1, t2);
			k2 = min(k2, (ll)floor(t2));
			k1 = max(k1, (ll)ceil(t1));
		}
		if(a != 0) {
			t1 = (double)(y0 - y1) * g / a;
			t2 = (double)(y0 - y2) * g / a;
			if(t2 < t1) swap(t1, t2);
			k2 = min(k2, (ll)floor(t2));
			k1 = max(k1, (ll)ceil(t1));
		}
		cout << k2 - k1 + 1 << endl;
	}
	return 0;
}
