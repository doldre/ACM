/************************************************
 *Author        :mathon
 *Created Time  :五  5/ 6 00:13:13 2016
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 2e5 + 5;
int A[maxn];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll n, k;
    cin >> n >> k;
    vector<ll> xx;
    xx.push_back(0);
    ll p = 0;
    for (int i = 1; i <= n; i++) {
        p += i;
        xx.push_back(p);
        scanf("%d", &A[i]);
    }
    int t = lower_bound(xx.begin(), xx.end(), k) - xx.begin();
    int x = k - xx[t-1];
    cout << A[x] << endl;
    return 0;
}
