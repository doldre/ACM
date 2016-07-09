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
const int maxn = 2e5 + 5;
int A[maxn], B[maxn];

struct ST {
    int f[maxn][30];
    int n, flag;
    void init(int *a, int n, int flag) {
        this->flag = flag;
        this->n = n;
        int K = ceil(log(n) / log(2));
        for (int i = 0; i < n; i++) {
            f[i][0] = a[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; j < n; j++) {
                f[j][i] = f[j][i-1];
                if(j+(1<<(i-1)) < n) {
                    if(flag) {
                        f[j][i] = max(f[j][i], f[j+(1<<(i-1))][i-1]);
                    } else {
                        f[j][i] = min(f[j][i], f[j+(1<<(i-1))][i-1]);
                    }
                }
            }
        }
    }

    int querry(int l, int r) {
        int t = floor(log(r - l + 1) / log(2));
        if(flag) {
            return max(f[l][t], f[r - (1<<t) + 1][t]);
        } else {
            return min(f[l][t], f[r - (1<<t) + 1][t]);
        }
    }
};

ST sta, stb;
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    sta.init(A, n, 1);
    stb.init(B, n, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = n;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            if(sta.querry(i, m) - stb.querry(i, m) < 0) {
                l = m;
            } else r = m;
        }
        int r0 = l;
        l = i - 1, r = n;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            // printf("i %d m %d\n", i, m);
            // printf("%d %d\n", sta.querry(i, m), stb.querry(i, m));
            if(sta.querry(i, m) - stb.querry(i, m) > 0) {
                r = m;
            } else l = m;
        }
        int r1 = r;
        // prln(i); pr(r0), prln(r1);
        ans += (r1 - r0 - 1);
    }
    cout << ans << endl;
    return 0;
}

