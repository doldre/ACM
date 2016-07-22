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
const int maxn = 1000 + 5;
int A[maxn];
int n, m;

int solve(int a, int b) {
    int tot = a + b;
    int last_zero = -1;
    int cnt_zero = 0;
    pii s, t;
    s = pii(0, 0); t = pii(0, 0);
    int sum = 0;
    for (; s.xx < n && t.xx < n;) {
        // pr(s.xx); prln(s.yy);
        // prln(sum);
        // prln(cnt_zero);
        for (int i = t.xx; sum < tot && i < n; i++) {
            int dt = A[i] - t.yy;
            if(sum + dt > tot) {
                dt = tot - sum;
                t.yy += dt;
                t.xx = i;
                sum = tot;
                if(i % 2 == 0) {
                    cnt_zero += dt;
                    // pr("ok");
                    // prln(cnt_zero);
                }
            } else {
                sum += dt;
                if(i % 2 == 0) {
                    cnt_zero += dt;
                }
                t.xx = i + 1;
                t.yy = 0;
            }
            if(sum == tot) {
                break;
            }
        }
        if(last_zero == -1) last_zero = cnt_zero;
        if(sum == tot) {
            // prln(cnt_zero);
            int small = min(last_zero, cnt_zero);
            int large =  max(last_zero, cnt_zero);
            if(small <= a && a <= large) {
                return 1;
            }
        }
        int dx = min(A[s.xx] - s.yy, A[t.xx] - t.yy);
        s.yy += dx;
        sum -= dx;
        last_zero = cnt_zero;
        if(s.xx % 2 == 0) cnt_zero -= dx;
        if(s.yy == A[s.xx]) {
            s.xx++;
            s.yy = 0;
        }
    }
    return 0;
}




int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            int res = solve(a, b);
            printf("%d", res);
        }
        puts("");
    }
    return 0;
}

