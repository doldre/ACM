#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int x[3], l;
    cin >> x[0] >> x[1] >> x[2] >> l;
    ll ans = ll(l+3) * (l + 2) * (l + 1) / 6;
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= 2; j++) {
            int t = l - i;
            if(j == 0) t = min(t, x[0] - x[1] - x[2] + i);
            if(j == 1) t = min(t, x[1] - x[2] - x[0] + i);
            if(j == 2) t = min(t, x[2] - x[1] - x[0] + i);
            if(t >= 0) ans -= ll(t + 2) * (t + 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}

