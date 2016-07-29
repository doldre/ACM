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
const int maxn = 1e5 + 5;
int dp[maxn*2];
int S[maxn];
int off;
int n;
int head, tail; 

int bin_search(int x) {
    int l = head - 1, r = tail;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        if(dp[m] + off >= x) {
            r = m;
        } else l = m;
    }
    return r;
}
const int inf = 0x3f3f3f3f;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &S[i]);
        }
        memset(dp, -inf, sizeof(dp));
        head = tail = maxn;
        off = 0;
        for (int i = 0; i < n; i++) {
            int a = S[i];
            if(a == 0) {
                head--;
                off++;
                dp[head] = -off;
            } else {
                int p = bin_search(a);
                if(p == tail) {
                    dp[tail++] = a - off;
                } else {
                    dp[p] = a - off;
                }
            }
        }
        printf("Case #%d: %d\n", Cas, tail - head);
    }
    return 0;
}

