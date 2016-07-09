/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

ll m;
ll count(ll n) {
    ll cnt = 0;
    for (ll i = 2; i <= 2e5; i++) {
        if(i * i * i > n) break;
        cnt += n / (i * i * i);
    }
    return cnt;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> m;
    ll l = 0, r = 8 * 1e15 + 1;
    while(l < r - 1) {
        ll mid = (l + r) >> 1;
        if(count(mid) >= m) {
            r = mid;
        } else l = mid;
    }
    if(count(r) == m) {
        cout << r << endl;
    } else cout << -1 << endl;
    return 0;
}

