/************************************************
 *Author        :mathon
 *Created Time  :日  4/17 07:59:07 2016
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

ll q, p;

ll mul_mod(ll a, ll n) {
    ll res = 0;
    while(n) {
        if(n & 1) {
            res = (res + a) % p;
        }
        a = (a + a) % p;
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
    scanf("%d", &T);
    while(T--) {
        cin >> q >> p;
        ll t;
        if((q + 1) % 2 == 0) {
            t = mul_mod(q + 2, (q + 1) / 2);
        } else t = mul_mod((q + 2) / 2, q + 1);
        t -= mul_mod(q, 3);
        cout << (t % p + p) % p << endl;;
    }
    return 0;
}
