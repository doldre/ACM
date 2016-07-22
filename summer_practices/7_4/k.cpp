#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " " 
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 5;
ll f[maxn];
ll c(ll x) {
    return ((x - 2) * (x - 1) / 2 - (x - 1) / 2) / 2;
}

void init() {
    f[3] = 0;
    for (int i = 4; i < maxn; i++) {
        f[i] = f[i - 1] + c(i);
    }
}
int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    init();
    int n;
    while(cin >> n && n >= 3) {
        printf("%lld\n", f[n]);
    }
	return 0;
}
