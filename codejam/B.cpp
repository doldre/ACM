/************************************************
 *Author        :mathon
 *Created Time  :六  4/16 09:55:50 2016
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 2500 + 12;

int cnt[maxn];

int main(void)
{
#ifdef LOCAL
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n -1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < maxn; i++) {
            if(cnt[i] % 2 == 1) {
                ans.push_back(i);
            }
        }
        printf("Case #%d:", Cas);
        sort(ans.begin(), ans.end());
        for (int x: ans) {
            printf(" %d", x);
        }
        printf("\n");
    }
    return 0;
}
