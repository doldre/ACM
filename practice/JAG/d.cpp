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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int x; scanf("%d", &x);
    ll l = 0, r = 1e5 + 1;
    while(l < r - 1) {
        ll m = (l + r) >> 1;
        if(m * (m + 1) / 2 >= x) {
            r = m;
        } else l = m;
    }
    int len = r;
    int base = 0;
    string ans;
    for (int i = 0; i < len; i++) {
        ans.push_back(')');
    }
    for (int i = 0; i < len; i++) {
        ans.push_back('(');
    }
    int res = r * (r + 1) / 2 - x;
    while(res > 0) {
        if(res >= len) {
            res -= len;
            swap(ans[base], ans[base+len]);
            base += 2;
            len--;
        } else {
            swap(ans[base+len-res], ans[base+len]);
            res -= res;
        }
    }
    cout << ans << endl;
    return 0;
}

