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

const ll MOD = 1ll<<40;
const int MAXN = 1e5 + 5;

ll multi(ll a, ll b) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % MOD;
        }
        b >>= 1;
        a = (a + a) % MOD;
    }
    return res;
}
struct BIT {
    ll bit[2*MAXN];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
    }
    void add(int i, ll x) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] = (bit[i] + x) % MOD;
        }
    }
    ll sum(int i) {
        ll res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res = (res + bit[i]) % MOD;
        }
        return res;
    }
};
int n, m;
ll A[MAXN], B[MAXN];
ll V[2*MAXN], cnt_v;

int ID(int x) {
    return lower_bound(V, V + cnt_v, x) - V + 1;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        cnt_v = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &A[i]);
            V[cnt_v++] = A[i];
        }
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &B[i]);
            V[cnt_v++] = B[i];
        }
        sort(V, V + cnt_v);
        cnt_v = unique(V, V + cnt_v) - V;
        ll ans = 0;
        BIT bit_cnt, bit_sum_j, bit_sum_bj, bit_sum_bjj;
        ll t_cnt, t_sum_j, t_sum_bj, t_sum_bjj;
        t_cnt = 0, t_sum_j = 0, t_sum_bj = 0, t_sum_bjj = 0;
        bit_cnt.init(cnt_v);
        bit_sum_j.init(cnt_v);
        bit_sum_bj.init(cnt_v);
        bit_sum_bjj.init(cnt_v);
        for (int i = 1; i <= n; i++) {
            if(i <= m) {
                int id = ID(B[i]);
                bit_cnt.add(id, 1);
                t_cnt++;
                bit_sum_j.add(id, i);
                t_sum_j = (t_sum_j + i) % MOD;
                bit_sum_bj.add(id, B[i]);
                t_sum_bj = (t_sum_bj + B[i]) % MOD;
                // bit_sum_bjj.add(id, multi(B[i], i));
                bit_sum_bjj.add(id, B[i] * i);
                // t_sum_bjj = (t_sum_bjj + multi(B[i], i)) % MOD;
                t_sum_bjj = (t_sum_bjj + B[i]* i) % MOD;
            }
            int ai = ID(A[i]);
            ans += A[i] * i *  bit_cnt.sum(ai) - 
                A[i] * bit_sum_j.sum(ai) - 
                i * bit_sum_bj.sum(ai) +
                bit_sum_bjj.sum(ai);
            // ans += multi(A[i], multi(i, bit_cnt.sum(ai))) - 
                // multi(A[i], bit_sum_j.sum(ai)) - 
                // multi(i, bit_sum_bj.sum(ai)) + 
                // bit_sum_bjj.sum(ai);
            ans = (ans % MOD + MOD) % MOD;
            ans += - A[i] * i *  (t_cnt - bit_cnt.sum(ai)) +
                A[i] * (t_sum_j - bit_sum_j.sum(ai)) + 
                i *(t_sum_bj -  bit_sum_bj.sum(ai)) -
                (t_sum_bjj - bit_sum_bjj.sum(ai));
            // ans += - multi(A[i], multi(i, t_cnt - bit_cnt.sum(ai))) +
                // multi(A[i], t_sum_j - bit_sum_j.sum(ai)) + 
                // multi(i, t_sum_bj - bit_sum_bj.sum(ai)) - 
                // (t_sum_bjj - bit_sum_bjj.sum(ai));
            ans = (ans % MOD + MOD) % MOD;
            // pr(A[i]);
            // pr(bit_cnt.sum(ai)); pr(bit_sum_j.sum(ai));
            // pr(bit_sum_bj.sum(ai)); prln(bit_sum_bjj.sum(ai));
            // prln(ans);
        }
        t_cnt = 0, t_sum_j = 0, t_sum_bj = 0, t_sum_bjj = 0;
        bit_cnt.init(cnt_v);
        bit_sum_j.init(cnt_v);
        bit_sum_bj.init(cnt_v);
        bit_sum_bjj.init(cnt_v);
        for (int i = m; i > n; i--) {
            int id = ID(B[i]);
            bit_cnt.add(id, 1);
            t_cnt++;
            bit_sum_j.add(id, i);
            t_sum_j = (t_sum_j + i) % MOD;
            bit_sum_bj.add(id, B[i]);
            t_sum_bj = (t_sum_bj + B[i]) % MOD;
            // bit_sum_bjj.add(id, multi(B[i], i));
            bit_sum_bjj.add(id, B[i] * i);
            t_sum_bjj = (t_sum_bjj + B[i] * i) % MOD;
            // t_sum_bjj = (t_sum_bjj + multi(B[i], i)) % MOD;
        }
        for (int i = n; i >= 1; i--) {
            int ai = ID(A[i]);
            ans += - A[i] * i *  bit_cnt.sum(ai) +
                A[i] * bit_sum_j.sum(ai) + 
                i * bit_sum_bj.sum(ai) -
                bit_sum_bjj.sum(ai);
            // ans += -multi(A[i], multi(i, bit_cnt.sum(ai))) +
                // multi(A[i], bit_sum_j.sum(ai)) + 
                // multi(i, bit_sum_bj.sum(ai)) - 
                // bit_sum_bjj.sum(ai);
            ans = (ans % MOD + MOD) % MOD;
            ans +=  A[i] * i *  (t_cnt - bit_cnt.sum(ai)) -
                A[i] * (t_sum_j - bit_sum_j.sum(ai)) - 
                i *(t_sum_bj -  bit_sum_bj.sum(ai)) +
                (t_sum_bjj - bit_sum_bjj.sum(ai));
            // ans +=  multi(A[i], multi(i, t_cnt - bit_cnt.sum(ai))) -
                // multi(A[i], t_sum_j - bit_sum_j.sum(ai)) - 
                // multi(i, t_sum_bj - bit_sum_bj.sum(ai)) + 
                // (t_sum_bjj - bit_sum_bjj.sum(ai));
            ans = (ans % MOD + MOD) % MOD;
            // prln(ans);
            if(i <= m) {
                int id = ID(B[i]);
                bit_cnt.add(id, 1);
                t_cnt++;
                bit_sum_j.add(id, i);
                t_sum_j = (t_sum_j + i) % MOD;
                bit_sum_bj.add(id, B[i]);
                t_sum_bj = (t_sum_bj + B[i]) % MOD;
                // bit_sum_bjj.add(id, multi(B[i], i));
                // t_sum_bjj = (t_sum_bjj + multi(B[i], i)) % MOD;
                bit_sum_bjj.add(id, B[i] * i);
                t_sum_bjj = (t_sum_bjj + B[i] * i) % MOD;
            }
        }
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

