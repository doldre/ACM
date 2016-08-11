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

const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
struct Manacher {
    char s[MAXN << 1];
    int n, p[MAXN << 1];
    void init(char *a, int len) {
        s[0] = '@'; s[1] = '#'; n = 2;
        for (int i = 0; i < len; i++) {
            s[n++] = a[i];
            s[n++] = '#';
        }
        s[n] = '\0';
    }

    int run() {
        int mx = 0, id = 0, ret = 0;
        for (int i = 1; i < n; i++) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(s[i - p[i]] == s[i + p[i]]) p[i]++;
            if(i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            ret = max(ret, p[i] - 1);
        }
        return ret;
    }
} manacher;


char str[MAXN];
ll cnt_pre[MAXN<<1], cnt_back[MAXN<<1];
ll flag[MAXN<<1], flag2[MAXN<<1];
int main(void) {
#ifdef MATHON
    freopen("1005.in", "r", stdin);
    freopen("1005.txt", "w", stdout);
#endif
    while(scanf("%s", str) == 1) {
        int len = strlen(str);
        manacher.init(str, len);
        manacher.run();
        int *p = manacher.p, n = manacher.n;
        memset(cnt_pre, 0, sizeof(ll) * n);
        memset(cnt_back,0, sizeof(ll) * n);
        memset(flag, 0, sizeof(ll) * n);
        memset(flag2, 0, sizeof(ll) * n); 

        for (int i = 1; i < n; i++) {
            flag[i] += i;
            flag[i + p[i]] -= i;
            flag2[i] += 1;
            flag2[i + p[i]] -= 1;
        }

        ll tmp = 0, tmp2 = 0;
        for (int i = 1; i < n; i++) {
            // pr(i);
            // prln(flag[i]);
            tmp += flag[i];                
            tmp2 += flag2[i];
            if(i % 2 == 0) {
                cnt_pre[i/2] = tmp  - i * tmp2 / 2;
            }
        }
        memset(flag, 0, sizeof(ll) * n);
        memset(flag2, 0, sizeof(ll) * n);
        for (int i = 1; i < n; i++) {
            flag[i] += i;
            flag[i - p[i]] -= i;
            flag2[i] += 1;
            flag2[i - p[i]] -= 1;
        }
        tmp = 0, tmp2 = 0;
        for (int i = n - 1; i >= 1; i--) {
            tmp += flag[i];
            tmp2 += flag2[i];
            if(i % 2 == 0) {
                cnt_back[i / 2] = tmp - i * tmp2/ 2;
            }
        }
        ll ans = 0;
        for (int i = 1; i < len; i++) {
            ans = (ans + (cnt_pre[i] % mod) * (cnt_back[i+1] % mod)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}

