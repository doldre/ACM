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
ll inf = 1e15;
ll ans;
void dfs(int S, int T, int last, int step, int max_step) {
    if(S <= T) {
        ans = min(ans, (ll)step + T - S);
        return;
    }
    if(step > max_step) return;
    dfs(S + 1, T, 0, step + 1, max_step);
    if(last == 0) last = 1;
    else last <<= 1;
    dfs(max(0, S - last), T, last, step + 1, max_step);
    dfs(S, T, 0, step + 1, max_step);
}

ll cal(int P, int Q) {
    ans = inf;
    for (int i = 0; i <= 20; i++) {
        dfs(P, Q, 0, 0, i);
        if(ans == i) return ans;
    }
    return ans;
}
    
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int P, Q;
    while(scanf("%d%d", &P, &Q) == 2) {
        printf("%lld\n", cal(P, Q));
    }
    return 0;
}

