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

const int MAXA = 1e5 + 5, MAXC = 1e3 + 5;
struct BIT2 {
    int bit[MAXC][MAXC];
    int tim[MAXC][MAXC];
    int stamp;
    int n, m;
    void init(int n, int m) {
        this->n = n; this->m = m;
        stamp++;
    }
    void add(int x, int y, int z) {
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                if(tim[i][j] != stamp) {
                    tim[i][j] = stamp;
                    bit[i][j] = 0;
                }
                bit[i][j] += z;
            }
        }
    }

    int sum(int x, int y) {
        int ans = 0;
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                if(tim[i][j] == stamp) ans += bit[i][j];
            }
        }
        return ans;
    }
}bit2;

int A[MAXA];
int cntA[MAXA];
vector<pii> B[MAXA];
vector<pair<int, pair<pii, int> > > vec;
int n, m;

ll solve() {
    vec.clear();
    for (int i = 1; i < MAXA; i++) {
        sort(B[i].begin(), B[i].end(), greater<pii>() );
        int maxy = 0;
        int last = 0;
        for (int j = 0; j < (int)B[i].size(); j++) {
            pii x = B[i][j];
            if(j > 0 && x == B[i][j-1]) {
                if(last) {
                    vec.push_back(make_pair(A[i], make_pair(x, cntA[i])));
                }
                continue;
            }
            if(x.yy > maxy) {
                if(A[i] != 0) {
                    vec.push_back(make_pair(A[i], make_pair(x, cntA[i])));
                }
                last = 1;
                maxy = x.yy;
            } else last = 0;
        }
    }
    sort(vec.begin(), vec.end(), greater<pair<int, pair<pii, int> > >());
    bit2.init(1e3, 1e3);
    ll ans = 0;
    int last = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        pair<int, pair<pii, int> > x = vec[i];
        // printf("%d %d %d\n", x.xx, x.yy.xx.xx, x.yy.xx.yy);
        pii y = x.yy.xx;
        if(i > 0 && vec[i] == vec[i-1]) {
            ans += last;
            continue;
        }
        if(bit2.sum(y.xx, y.yy) == 0) {
            // printf("OK\n");
            ans += x.yy.yy;
            last = x.yy.yy;
        } else last = 0;
        bit2.add(y.xx, y.yy, 1);
    }
    return ans;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        memset(A, 0, sizeof(A));
        memset(cntA, 0, sizeof(cntA));
        for (int i = 0; i < MAXA; i++) {
            B[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a == A[b]) {
                cntA[b]++;
            } else if(a > A[b]) {
                A[b] = a;
                cntA[b] = 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            int c, d, e;
            scanf("%d%d%d", &c, &d, &e);
            B[e].push_back(pii(c, d));
        }
        ll ans = solve();
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

