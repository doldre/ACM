/************************************************
 *Author        :mathon
 *Created Time  :五  4/15 21:41:11 2016
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
int n, k, mod;

ll fast_pow(ll x, int n) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
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
        cin >> n >> k >> mod;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            res = (res + x) % mod;
        }
        res = (res * fast_pow(n, k - 1) % mod ) * k % mod;
        printf("Case %d: ", Cas);
        cout << res << endl;
    }
    return 0;
}
