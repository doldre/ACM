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
typedef pair<ll, ll> pll;
const int maxn = 1e5 + 5;
const ll inf = 1e15 + 7;
pll buf[maxn*2];
pll buf2[maxn*2];
int n, m;
bool is_covered[maxn*2];
int tot, tot2;

bool judge(ll r) {
    int last = -inf;
    memset(is_covered, false, sizeof(is_covered));
   for (int i = 1; i <= tot; i++) {
        if(buf[i].yy == 1) {
            if((ll)buf[i].xx - last <= r) {
                is_covered[i] = true;
            }
        } else {
            last = buf[i].xx;
            is_covered[i] = true;
        }
   }
   last = inf;
   for (int i = tot; i >= 1; i--) {
       if(buf2[i].yy == 0) {
           if((ll)last - buf2[i].xx <= r) {
               is_covered[i] = true;
           }
       } else {
           last = buf2[i].xx;
           is_covered[i] = true;
       }
   }
   for (int i = 1; i <= tot; i++) {
       if(!is_covered[i]) {
           return false;
       }
   }
   return true;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        buf[++tot] = pll(x, 1);
        buf2[++tot2] = pll(x, 0);
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        buf[++tot] = pll(x, 0);
        buf2[++tot2] = pll(x, 1);
    }
    sort(buf + 1, buf + tot + 1);
    sort(buf2 + 1, buf2 + tot2 + 1);
    ll l = -1, r = inf;
    while(l < r - 1) {
        ll m = (l + r) >> 1;
        if(judge(m)) {
            r = m;
        } else l = m;
    }
    printf("%lld\n", r);
    return 0;
}

