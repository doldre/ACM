#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    while(k > 0 && n >= 2) {
        ans += n - 1 + n - 2;
        n -= 2;
        k--;
    }
    cout << ans << endl;
    return 0;
}
