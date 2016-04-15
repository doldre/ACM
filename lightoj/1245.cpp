/************************************************
 *Author        :mathon
 *Created Time  :五  4/15 19:50:06 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;

ll cal(ll x) {
    ll res = 0;
    ll last = x + 1;
    ll i;
    for (i = 1; ; i++) {
        ll t = x / i;
        res += (i - 1) * (last - t);
        if(t < i) {
            break;
        }
        if(t == i) {
            res += i;
            break;
        }
        res += t;
        last = t;
    }
    return res;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int Cas = 1; Cas <= T; Cas++) {
        int n;
        cin >> n;
        printf("Case %d: ", Cas);
        cout << cal(n) << endl;
    }
    return 0;
}
