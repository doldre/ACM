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
int cnt[MAXN];
int sum_cnt[MAXN];
int n;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        cnt[A[i]]++;
    }
    for (int i = MAXN - 2; i >= 1; i--) {
        sum_cnt[i] = sum_cnt[i+1] + cnt[i];
    }
    ll ans = 0;
    for (int i = 1; i < MAXN; i++) {
        if(cnt[i] == 0) continue;
        int last_cnt = sum_cnt[i];
        ll tmp = 0;
        for (int j = i + i; ; j += i) {
            int t = last_cnt - (j < MAXN ? sum_cnt[j] : 0);
            tmp += (ll)(j - i) * t;
            if(j >= MAXN) break;
            last_cnt = sum_cnt[j];
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}

