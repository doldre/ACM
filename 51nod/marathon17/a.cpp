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
const ll INF = 1e18 + 5;
const int MAXN = 1e5 + 5;
ll A[MAXN];
ll k;
ll sg(ll x) {
    if(x <= 1) return 0;
    if((x - 1) % k != 0) {
        return x - (x - 1) / k - 1;
    } else {
        return sg((x - 1) / k);
    }
}

ll solve(ll x, ll low) {
   if(x >= low) return x;
   else return solve(x * k + 1, low);
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d%lld", &n, &k);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
        res ^= sg(A[i]);
    }
    int id = 0;
    ll y = 0;
    for (int i = 1; i <= n; i++) {
        ll t = res ^ sg(A[i]);
        if (t == 0) t = 1;
        else if(t % (k - 1) == 0) t = t / (k - 1) * k;
        else t = t / (k - 1) * k + t % (k - 1) + 1;
        t = solve(t, (A[i] + k - 1) / k);
        if(t < A[i]) {
            id = i; y = t;
            break;
        }
    }
    if(res) {
        printf("Alice %d %lld\n", id, y);
    } else printf("Bob\n");
    return 0;
}

