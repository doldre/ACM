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

const int MAXN = 400 + 5;
int A[MAXN][MAXN];
int flag[MAXN];
int n, m;
char str[MAXN];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf("%s", str);
            for (int j = 0; j < n; j++) {
                A[i][j] = str[j] - '0';
            }
        }
        memset(flag, 0, sizeof(flag));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int last = 1, cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                A[i][j] ^= flag[j];
                if(A[i][j] != last) {
                    cnt++;
                    last = A[i][j];
                    flag[j] ^= 1;
                }
            }
            ans += cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}

