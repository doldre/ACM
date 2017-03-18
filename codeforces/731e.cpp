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

const int MAXN = 2e5 + 5;
int A[MAXN];
int sum[MAXN];
int dp[MAXN];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    A[1] += A[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + A[i];
    }
    int ma = sum[n-1];
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = ma;
        ma = max(ma, sum[i-1] - dp[i]);
    }
    cout << dp[1] << endl;
    return 0;
}

