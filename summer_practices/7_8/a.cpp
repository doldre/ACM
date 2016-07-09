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
const int mod = 835672545;
const int maxn = 1000 + 5;
char words[maxn][maxn];
char str[maxn];
int match[maxn][maxn];
int n;
int dp[maxn];
int wordlen[maxn];
int lenstr;

struct KMP {
    int nxt[maxn];
    void get_next(int words_num) {
        char *s = words[words_num];
        int len = wordlen[words_num];
        int i, k;
        nxt[0] = k = -1;
        for (i = 0; i < len;) {
            if(k == -1 || s[i] == s[k]) {
                k++; i++;
                nxt[i] = k;
            } else k = nxt[k];
        }
    }

    void solve(int words_num) {
        char *w = words[words_num];
        int lw = wordlen[words_num], lstr = lenstr;
        int j = 0;
        for (int i = 0; i < lstr;) {
            if(j == -1 || w[j] ==str[i]) {
                i++; j++;
                if(j == lw) {
                    match[words_num][i-1] = 1;
                    j = nxt[j];
                    // pr(j);
                    // pr(words_num), prln(i);
                }
            } else {
                j = nxt[j];
            }
        }
    }
}kmp;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            wordlen[i] = strlen(words[i]);
        }
        scanf("%s", str);
        lenstr = strlen(str);
        memset(match, 0, sizeof(match));
        for (int i = 0; i < n; i++) {
            kmp.get_next(i);
            kmp.solve(i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int len = strlen(str);
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < n; j++) {
                if(match[j][i-1]) {
                    dp[i] = (dp[i] + dp[i-wordlen[j]]) % mod;
                }
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}

