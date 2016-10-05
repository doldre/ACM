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


void get_next(int x[], int m, int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}

/* 优化版本 */
void get_next_o(int x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = kmpNext[j];
        if(x[++i] == x[++j]) kmpNext[i] = kmpNext[j];
        else kmpNext[i] = j;
    }
}

const int MAXN = 1e6 + 5;
int _next[MAXN];
int used[MAXN];
int n, m, p;
int B[MAXN], A[MAXN];
int buf[MAXN];
/* x 为模式串， y 为待匹配串 */
int kmp_count(int x[], int m, int y[], int n) {
    int i, j;
    int ans = 0;
    // get_next(x, m, _next);
    i = j = 0;
    while(i < n) {
        while(j != -1 && y[i] != x[j]) j = _next[j];
        i++; j++;
        if(j >= m) {
            ans++;
            j = _next[j];
        }
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
        scanf("%d%d%d", &n, &m, &p); 
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            used[i] = 0;
        }
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[j]);
        }
        B[m] = -1;
        int ans = 0;
        get_next_o(B, m, _next);
        for (int i = 0; i < n; i++) {
            if(!used[i]) {
                int cnt = 0;
                for (int j = i; j < n; j += p) {
                    used[j] = true;
                    buf[cnt++] = A[j];
                }
                ans += kmp_count(B, m, buf, cnt);
                // prln(ans);
            }
        }
        printf("Case #%d: %d\n", Cas, ans);
    }
    return 0;
}
