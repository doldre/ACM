/************************************************
 *Author        :mathon
 *Created Time  :六  4/16 19:07:22 2016
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



int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        ll Q, P;
        cin >> Q >> P;
        __int128 q = Q;
        __int128 tot;
        tot = (__int128)(q + 1) * (__int128)(q + 1) - (q + 1);
        tot /= 2;
        tot = tot - (q - 1) * 2 - 1;
        if(q % 2 == 0) {
            tot -= (q / 2 - 1);
        }
        ll ans = tot % P;
        cout << ans << endl;
    }
    return 0;
}
