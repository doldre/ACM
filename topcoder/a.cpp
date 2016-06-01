#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define prln(x) cout << #x << " = " << x << endl
const ll mod = 1e9 + 7;

class TriangleTriples {
public:
    int count(int A, int B, int C) {
        ll sum = ll(A) + ll(B) + ll(C);
        sum /= 2;
        ll x1 = (A + C - 1) / 2;
        ll y1 = (A + B - 1) / 2;
        ll z1 = (B + C - 1) / 2;
        prln(x1);
        prln(y1);
        prln(z1);
        return (x1) * (y1) % mod * (z1) % mod;
    }
};

int main() {
    TriangleTriples test;
    int a, b, c;
    cin >> a >> b >> c;
    cout << test.count(a, b, c) << endl;
}
