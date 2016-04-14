/************************************************
 *Author        :mathon
 *Created Time  :2016年04月14日 星期四 20时27分02秒
 ***********************************************/
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 4e8 + 1000;

int f(int x) {
    int res = 0;
    for (int t = 5; t <= x; t *= 5) {
        res += x / t;
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
        printf("Case %d: ", Cas);
        int x;
        cin >> x;
        int l = 0, r = maxn;
        while(r - l > 1) {
            int m = (r + l) >> 1;
            if(f(m) >= x) {
                r = m;
            } else {
                l = m;
            }
        }
        if(f(r) != x) {
            printf("impossible\n");
        } else {
            printf("%d\n", r);
        }
    }
    return 0;
}
