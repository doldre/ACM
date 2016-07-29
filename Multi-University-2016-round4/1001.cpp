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

void get_next(char x[], int m, int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}

/* 优化版本 */
void get_next_o(char x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = kmpNext[j];
        if(x[++i] == x[++j]) kmpNext[i] = kmpNext[j];
        else kmpNext[i] = j;
    }
}

const int maxn = 1e5 + 5;
int nxt[maxn];
bool vised[maxn];
int kmp_count(char x[], int m, char y[], int n) {
    int i, j;
    int ans = 0;
    get_next_o(x, m, nxt);
    i = j = 0;
    while(i < n) {
        while(j != -1 && y[i] != x[j]) j = nxt[j];
        i++; j++;
        if(j >= m) {
            vised[i] = true;
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}

char A[maxn], B[maxn];
ll dp[maxn][2];
const ll mod = 1e9 + 7;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%s%s", A, B);
        int lena = strlen(A), lenb = strlen(B);
        memset(vised, 0, sizeof(vised));
        kmp_count(B, lenb, A, lena);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= lena; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
            if(vised[i]) {
                dp[i][1] = (dp[i-lenb][0] + dp[i-lenb][1]) % mod;
            }
        }
        printf("Case #%d: %lld\n", Cas, (dp[lena][0] + dp[lena][1]) % mod);
    }
    return 0;
}

