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
const int maxn = 1e6 + 6;
int A[maxn];
int V[maxn];
int n;
int cnt[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            V[i-1] = A[i]; 
        }
        sort(V, V + n);
        int m = unique(V, V + n) - V;
        for (int i = 1; i <= n; i++) {
            A[i] = lower_bound(V, V + m, A[i]) - V;
        }
        int ans = inf; 
        memset(cnt, 0, sizeof(cnt));
        for (int l = 1, r = 1, c = 0; r <= n; r++) {
            if(cnt[A[r]]++ == 0) c++;
            while(c == m) {
                ans = min(ans, r - l + 1);
                cnt[A[l]]--;
                if(cnt[A[l]] == 0) c--;
                l++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

