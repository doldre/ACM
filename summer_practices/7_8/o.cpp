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

const int MaxM = 60 + 5, MaxN = 60 + 5;
const int maxnode = MaxM * MaxN;

struct DLX {
    // n 个雷达，m个城市，能否用 K 个雷达 覆盖所有的m个城市。
    // 可重复覆盖
    int n, m, size;
    int K;
    int U[maxnode], D[maxnode], R[maxnode], L[maxnode];
    int Row[maxnode], Col[maxnode];
    int H[MaxN], S[MaxN];
    int ind[MaxN];

    int ands, ans[MaxN];
    void init(int _n, int _m) {
        n = _n;
        m = _m;
        for (int i = 0; i <= m; i++) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for (int i = 1; i <= n; i++) {
            H[i] = -1;
        }
    }

    void Link(int r, int c) {
        ++S[Col[++size] = c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0) {
            H[r] = L[size] = R[size] = size;
        } else {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }

    void remove(int c) {
        for (int i = D[c]; i != c; i = D[i]) {
            L[R[i]] = L[i], R[L[i]] = R[i];
        }
    }
    
    void resume(int c) {
        for (int i = U[c]; i != c; i = U[i]) {
            L[R[i]] = R[L[i]] = i;
        }
    }

    bool v[maxnode];

    int f() {
        int ret = 0;
        for (int c = R[0]; c != 0; c = R[c]) v[c] = true;
        for (int c = R[0]; c != 0; c = R[c]) {
            if(v[c]) {
                ret++;
                v[c] = false;
                for (int i = D[c]; i != c; i = D[i]) {
                    for (int j = R[i]; j != i; j = R[j]) {
                        v[Col[j]] = false;
                    }
                }
            }
        }
        return ret;
    }

    bool Dance(int d) {
        if (d + f() > K) return false;
        if (R[0] == 0) return d <= K;
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if(S[i] < S[c]) {
                c = i;
            }
        }
        for (int i = D[c]; i != c; i = D[i]) {
            remove(i);
            for (int j = R[i]; j != i; j = R[j]) remove(j);
            if(Dance(d + 1)) return true;
            for (int j = L[i]; j != i; j = L[j]) resume(j);
            resume(i);
        }
        return false;
    }
}dlx;


const int maxn = 60 + 5;
int X[maxn], Y[maxn];
ll dis[maxn*maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    int N, K;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; Case++) {
        scanf("%d%d", &N, &K);
        dlx.K = K;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &X[i], &Y[i]);
        }
        int cnt_d = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dis[cnt_d++] = (ll)abs(X[i] - X[j]) + (ll)abs(Y[i] - Y[j]);
            }
        }
        sort(dis, dis + cnt_d);
        cnt_d = unique(dis, dis + cnt_d) - dis;
        int l = -1, r = cnt_d;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            ll mid = dis[m];
            dlx.init(N, N);
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if((ll)abs(X[i] - X[j]) + (ll)abs(Y[i] - Y[j]) <= mid) {
                        dlx.Link(i, j);
                    }
                }
            }
            if(dlx.Dance(0)) r = m;
            else l = m;
        }
        printf("Case #%d: %lld\n", Case, dis[r]);
    }
    return 0;
}
