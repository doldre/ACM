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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int MAXN = 1e5 + 5;
int A[MAXN];
int N, M;
struct RMQ {
    int dat[20][MAXN];
    void build() {
        for (int i = 1; i <= N; i++) {
            dat[0][i] = A[i];
        }
        for (int k = 1; 1<<k <= N; k++) {
            for (int i = 1; i + (1<<k) - 1 <= N; i++) {
                dat[k][i] = min(dat[k-1][i], dat[k-1][i+(1<<(k-1))]);
            }
        }
    }
    int query(int l, int r) {
        int k = 0;
        while((1 << (k + 1)) <= r - l + 1) k++;
        return min(dat[k][l], dat[k][r-(1<<k)+1]);
    }
} rmq;

int bin_search(int s, int e, int x) {
    int l = s - 1, r = e + 1;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        // int t = seg.query(s, m, 1, N, 1);
        int t = rmq.query(s, m);
        // pr(l); prln(r);
        // pr(x); pr(m); prln(t);
        if(t <= x) {
            r = m;
        } else l = m;
    }
    // prln(r);
    return r;
}

int main() {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        rmq.build();
        scanf("%d", &M);
        while(M--) {
            int L, R;
            scanf("%d%d", &L, &R);
            int x = A[L], pos = L + 1;
            while(x > 0 && pos <= R) {
                int t = bin_search(pos, R, x);
                if(t > R) break;
                x %= A[t];
                // pr(x); prln(t);
                pos = t + 1;
            }
            printf("%d\n", x);
        }
    }
    return 0;
}
