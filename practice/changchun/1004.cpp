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

const int MAXN = 20 + 5;
int dp[MAXN];
void init() {
    vector<int> v;
    v.push_back(1); v.push_back(2);
    while(true) {
        int x = v[v.size() - 1] + v[v.size() - 2];
        if(x > 20) break;
        v.push_back(x);
    }
    for (int i = 0; i < (int)v.size(); i++) {
        dp[v[i]] = 1;
    }
    for (int i = 1; i <= 20; i++) {
        dp[i] = dp[i-1] + dp[i];
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    init();
    for (int Cas = 1; Cas <= T; Cas++) {
        int n; scanf("%d", &n);
        printf("Case #%d: %d\n", Cas, n - dp[n]);
    }
    return 0;
}

