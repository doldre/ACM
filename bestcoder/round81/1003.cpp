/************************************************
 *Author        :mathon
 *Created Time  :五  4/22 19:20:39 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e6 + 5;

char str[maxn];
ll dp[maxn];
int pre[maxn];
int cnt[26];

int count() {
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if(cnt[i] > 0) res++;
    }
    return res;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        int k;
        scanf("%d", &k);
        int len = strlen(str);
        str[len] = 'a', str[len + 1] = '\0';
        for (int i = 0; i < len; i++) pre[i] = -1;
        for (int i = 0; i < 26; i++) cnt[i] = 0;
        int l = 0, r = 0;
        while(count() < k && r <= len) {
            cnt[str[r] - 'a']++;
            r++;
        }

        for (; r <= len; r++) {
            while(count() >= k) {
                cnt[str[l] - 'a']--;
                l++;
            }
            pre[r - 1] = l - 1;
            cnt[str[r] - 'a']++;
        }

        ll ans = 0;
        for (int i = 0; i < len; i++) {
            if(pre[i] != -1) {
//                printf("i %d pre[i] %d\n", i, pre[i]);
                ans += pre[i] + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
