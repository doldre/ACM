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

int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    int n;
    scanf("%d", &n);
    map<int, int> cur, tmp;
    map<int, ll> ans;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        cur[a]++;
        tmp.clear();
        for (auto &x: cur) {
            tmp[__gcd(x.first, a)] += x.second;
            ans[__gcd(x.first, a)] += x.second;
        }
        cur = tmp;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x; scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
	return 0;
}
