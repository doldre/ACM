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
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int A[maxn];
pii sum[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    while(scanf("%d%d", &n, &k) == 2) {
        if(n == 0 && k == 0) return 0;
        memset(A, 0, sizeof(A));
        memset(sum, 0, sizeof(sum));
        sum[0] = pii(0, 0);
        for (int i = 1; i <= n; i++) {
           scanf("%d", &A[i]);
           sum[i].xx = sum[i-1].xx + A[i];
           sum[i].yy = i;
        }
        sort(sum, sum + n + 1);
        for (int i = 0; i < k; i++) {
            int t; scanf("%d", &t);
            int tmp = inf, ans = inf, ansl = -1, ansr = -1;
            for (int l = 0, r = 1; r <= n; r++) {
                if(l < r && abs(sum[r].xx - sum[l].xx - t) < tmp) {
                    tmp = abs(sum[r].xx - sum[l].xx - t);
                    ans = sum[r].xx - sum[l].xx;
                    ansl = sum[l].yy, ansr = sum[r].yy;
                }
                while(l < r && sum[r].xx - sum[l].xx >= t) {
                    l++;
                    if(l < r && abs(sum[r].xx - sum[l].xx - t) < tmp) {
                        tmp = abs(sum[r].xx - sum[l].xx - t);
                        ans = sum[r].xx - sum[l].xx;
                        ansl = sum[l].yy; ansr = sum[r].yy;
                    }
                }
            }
            if(ansl > ansr) swap(ansl, ansr);
            printf("%d %d %d\n", ans, ansl + 1, ansr);
        }
    }
    return 0;
}

