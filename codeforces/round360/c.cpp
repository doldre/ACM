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
const int maxn = 500 + 5;
int dp1[maxn], dp2[maxn][maxn];
int c[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, K;
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    dp1[0] = 1;
    dp2[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int x = c[i];
        for (int j = K; j >= x; j--) {
            if(dp1[j - x]) {
                dp1[j] = 1;
                for (int k = K; k >= 0; k--) {
                    if(dp2[j-x][k]) {
                        dp2[j][k] = 1;
                        if(k + x <= K) {
                            dp2[j][k+x] = 1;
                        }
                    }
                }
            }
        }
    }
    vector<int> ans;
    for (int k = 0; k <= K; k++) {
        if(dp2[K][k]) {
            ans.push_back(k);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto x: ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}

