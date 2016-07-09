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
const int maxn = 100 + 5;
int dp[maxn][maxn];
int ans[maxn];
char str[maxn];

int dfs(int i, int j) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    else {
        if((str[i] == '(' && str[j] == ')') || 
                (str[i] == '[' && str[j] == ']')) {
            dp[i][j] = max(dp[i][j], dfs(i+1, j-1) + 2);
        }
        for (int k = i; k <= j; k++) {
            dp[i][j] = max(dp[i][j], (dfs(i, k) + dfs(k+1, j)));
        }
        return dp[i][j];
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%s", str) == 1) {
        if(strcmp(str, "end") == 0) {
            return 0;
        }
        int len = strlen(str);
        memset(dp, -1, sizeof(dp));
        dfs(0, len - 1);
        printf("%d\n", dfs(0, len-1));
    }
    return 0;
}

