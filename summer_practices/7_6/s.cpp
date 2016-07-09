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
const int maxn = 2e5 + 5;
int A[maxn], dp[maxn];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if(A[i] == A[i-1]) dp[i] = dp[i-1]; 
        else dp[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if(A[r] == x) {
            if(dp[r] <= l) {
                printf("%d\n", -1);
            } else printf("%d\n", dp[r] - 1);
        } else {
            printf("%d\n", r);
        }
    }
    return 0;
}

