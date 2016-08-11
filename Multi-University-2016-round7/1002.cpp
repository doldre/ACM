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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll n, m;
    while(scanf("%lld%lld", &n, &m) == 2) {
        if(n == 0 && m == 0) return 0;
        ll p = (m * n - n), q = m * m;
        ll g = gcd(p, q);
        p /= g, q /= g;
        printf("%lld/%lld\n", p, q);
    }
    return 0;
}

