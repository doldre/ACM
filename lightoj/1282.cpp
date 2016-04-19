/************************************************
 *Author        :mathon
 *Created Time  :二  4/19 09:00:30 2016
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

ll quick_pow(ll x, ll n, ll mod) {
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

double pow2(double x, ll n) {
    double res = 1;
    while(n) {
        if(n & 1) {
            res = res * x;
            if(res > 1e9) {
                int t = log(res) / log(10);
                res *= pow(res, -t + 8);
            }
        }
        x = x * x;
        if(x > 1e9) {
            int t = log(x) / log(10);
            res *= pow(x, -t + 8);
        }
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
    int n;
    cin >> n;
    char str[10];
    for (int Cas = 1; Cas <= n; Cas++) {
        ll n, k;
        cin >> n >> k;
        printf("Case %d: ", Cas);
        double t = k * log(double(n));
        t = t - floor(t);
        sprintf(str, "%f", pow(10, t));
        str[3] = '\0';
        printf("%s %03lld\n", str, quick_pow(n, k, 1000));
    }
    return 0;
}
