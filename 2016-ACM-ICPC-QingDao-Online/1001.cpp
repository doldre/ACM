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
const ll MAX = 2e9;
vector<ll> V;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    for (ll i = 1; i <= MAX; i *= 2) {
        for (ll j = 1; j <= MAX; j *= 3) {
            if(i * j > MAX) continue;
            for (ll k = 1; k <= MAX; k *= 5) {
                if(i * j * k > MAX) continue;
                for (ll l = 1; l <= MAX; l *= 7) {
                    if(i * j * k * l > MAX) continue;
                    V.push_back(i*j*k*l);
                }
            }
        }
    }
    sort(V.begin(), V.end());
    int T; scanf("%d", &T);
    while(T--) {
        ll n;
        scanf("%lld", &n);
        ll p = *lower_bound(V.begin(), V.end(), n);
        printf("%lld\n", p);
    }
    return 0;
}

