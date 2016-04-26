/************************************************
 *Author        :mathon
 *Created Time  :五  4/22 19:46:15 2016
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

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
ll rev[maxn];
ll h[maxn];
ll ans[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    rev[1] = 1;
    for (int i = 2; i < maxn; i++) {
        rev[i] = 1LL*(mod - (mod / i)) * rev[mod % i] % mod;
    }
    h[0] = 1;
    h[1] = 1;
    ans[1] = 1;
    for (int i = 2; i < maxn - 3; i++) {
        h[i] = ((2 * i + 1) * h[i - 1] % mod + (3 * i - 3) * h[i - 2] % mod) % mod * rev[i + 2] % mod;
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        cout << h[n] << endl;
    }
    return 0;
}
