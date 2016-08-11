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

const ll INF = 1e16;
ll cnt[20][20];
int d[20];
ll ans;
int ans_x;
int maxi;

void dfs(int i, ll sum, int x) {
    if(i == maxi) {
        if(sum < ans) {
            ans = sum; ans_x = x;
        } else if(sum == ans && x < ans_x) {
            ans_x = x;
        }
        return;
    }
    for (d[i] = 0; d[i] < 2; d[i]++) {
        ll nsum = sum + cnt[i][i];
        for (int j = 0; j < i; j++) {
            if(d[i] ^ d[j]) {
                nsum -= cnt[i][j];
            } else nsum += cnt[i][j];
        }
        dfs(i + 1, nsum,  x | (d[i] << i));
    }
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        int a, b;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &a);
        for (int i = 2; i <= n; i++) {
            scanf("%d", &b);
            int mx = max(a, b);
            int mi = min(a, b);
            int high = 20;
            while(high >= 0 && ~(a ^ b) >> high & 1) high--;
            for (int i = 0; i <= high; i++) {
                cnt[high][i] += (mx >> i & 1) - (mi >> i & 1);
            }
            a = b;
        }
        maxi = 20;
        while(maxi > 0 && !cnt[maxi-1][maxi-1]) maxi--;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j <= i; j++) {
                cnt[i][j] <<= j;
            }
        }
        ans = INF;
        dfs(0, 0, 0);
        printf("%d %lld\n", ans_x, ans);
    }
    return 0;
}

