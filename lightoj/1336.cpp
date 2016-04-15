/************************************************
 *Author        :mathon
 *Created Time  :五  4/15 12:16:10 2016
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const ll maxn = 1e12 + 5;
const ll maxk = 1e6 + 5;
bool isprime[maxk];
vector<ll> A;
set<ll> S;

void init() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxk; i++) {
       if(isprime[i]) for (int j = i + i; j < maxk; j += i) {
            isprime[j] = false;
        }
    }
    S.insert(1);
    for (int i = 2; i < maxk; i++) {
        if(isprime[i]) {
            ll t;
            if(i % 2 == 0) {
                t = i;
            } else t = (ll)i * (ll)i;
            for (; (double)t < maxn;) {
                set<ll>::iterator it;
                for (it = S.begin(); it != S.end(); it++) {
                    ll x = *it;
                    if((double)t * x > maxn) break;
                    S.insert(t * x);
                }
                if(double(t)*i*i > maxn) {
                    break;
                } else t =t * i * i;
            }
        }
    }
    set<ll>::iterator it;
    for (it = S.begin(); it != S.end(); it++) {
        ll x = *it;
        A.push_back(x);
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        ll n;
        cin >> n;
        int p = upper_bound(A.begin(), A.end(), n) - A.begin();
        printf("Case %d: ", Cas);
        cout << n - p << endl;
    }
    return 0;
}
