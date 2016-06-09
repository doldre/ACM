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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100000 + 5;
int A[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, h, k;
    cin >> n >> h >> k;
    ll t = 0;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        r += A[i];
        if(r + A[i+1] > h) {
            ll det = A[i+1] - (h - r);
            ll ti = max(1ll, (det + k - 1) / k);
            t += ti;
            /* pr(i); */
            /* prln(ti); */
            r -= min(r, ti * k);
        }
    }
    t += (r + k - 1) / k;
    cout << t << endl;
    return 0;
}
