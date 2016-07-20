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
const ll MOD = 998244353ll;
const int maxn = 1e5 + 7;
struct BIT {
    ll bit[maxn];
    int n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }

    void update(int i, ll add) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += add;
        }
    }

    ll sum(int i) {
        ll res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;

int A[maxn], B[maxn];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        bit.init(n);
        for (int i = 1; i <= n; i++) {
            bit.update(i, 1);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        int cur_max = 0, cur_min = n + 1;
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            int a = -1, b = -1;
            if(A[i] > cur_max) {
                a = cur_max = A[i];
            }
            if(A[i] < cur_max) {
                ans = 0;
            }
            if(B[i] < cur_min) {
                b = cur_min = B[i];
            }
            if(B[i] > cur_min) {
                ans = 0;
            }
            if(a != -1 && b != -1) {
                if(a != b) {
                    ans = 0;
                } else {
                    bit.update(a, -1);
                }
            } else if(a != -1 && b == -1) {
                if(a < cur_min) {
                    ans = 0;
                }
                bit.update(a, -1);
            } else if(a == -1 && b != -1) {
                if(b > cur_max) {
                    ans = 0;
                }
                bit.update(b, -1);
            } else {
                ll t = bit.sum(cur_max) - bit.sum(cur_min - 1);
                // prln(cur_max); prln(cur_min);
                // prln(t);
                ans = ans * t % MOD;
                bit.update(cur_min, -1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

