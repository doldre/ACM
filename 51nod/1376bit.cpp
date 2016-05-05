/************************************************
 *Author        :mathon
 *Created Time  :2016年04月26日 星期二 10时41分41秒
 ***********************************************/
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
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;

const int maxn = 1e5 + 5;
int A[maxn], buf[maxn];
int cnt;

void Modify(pii &a, pii b) {
    if(a.xx < b.xx) {
        a = b;
    } else if(a.xx == b.xx) {
        a.yy = (a.yy + b.yy) % mod;
    }
}

class Bit {
    public:
        pii bit[maxn];
        int n;
        void init(int n) {
            this->n = n;
            for (int i = 0; i <= n; i++) {
                bit[i] = pii(0, 0);
            }
        }

        void add(int p, pii x) {
            for (int i = p; i <= n; i += lowbit(i)) {
                Modify(bit[i], x);
            }
        }

        pii querry(int p) {
            pii res(0, 1);
            for (int i = p; i > 0; i -= lowbit(i)) {
                Modify(res, bit[i]);
            }
            return res;
        }
};

Bit bit;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    for (int i = 0; i < n; i++) {
        sa(A[i]);
        buf[i] = A[i];
    }
    sort(buf, buf + n);
    cnt = unique(buf, buf + n) - buf;
    bit.init(cnt);
    pii ans(0, 0);
    for (int i = 0; i < n; i++) {
        int x = A[i];
        int idx = lower_bound(buf, buf + cnt, x) - buf +1;
        pii t = bit.querry(idx - 1);
        t.xx++;
        Modify(ans, t);
        bit.add(idx, t);
    }
    ans = bit.querry(cnt);
    printf("%d\n", ans.yy);
    return 0;
}
