/************************************************
 *Author        :mathon
 *Created Time  :六  4/16 07:20:23 2016
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e6 + 5;

double ans[maxn];
const double det = 0.577215666490975;
void init() {
    for (int i = 1; i < maxn; i++) {
        ans[i] = ans[i - 1] + 1.0 / i;
    }
//    printf("%.15f\n", ans[maxn-1] - log(maxn));
    //printf("%.9f %.9f\n", ans[maxn-1], log(maxn));
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T;
    cin >> T;
    for (int Cas = 1; Cas <= T; Cas++) {
        int x;
        scanf("%d", &x);
        printf("Case %d: ", Cas);
        if(x < maxn) {
            printf("%.10f\n", ans[x]);
        } else {
            printf("%.10f\n", log(x + 0.5) + det);
        }
    }
    return 0;
}
