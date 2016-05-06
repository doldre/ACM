/************************************************
 *Author        :mathon
 *Created Time  :五  5/ 6 00:19:20 2016
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 500000 + 5;
int a[maxn], b[maxn], c[maxn];
int cnt[maxn];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        sa(x);
        if(mp[x] == 0) {
            mp[x] = ++tot;
        }
        int t = mp[x];
        cnt[t]++;
    }
    int m;
    sa(m);
    for (int i = 0; i < m; i++) {
        sa(b[i]);
        b[i] = mp[b[i]];
    }
    for (int i = 0; i < m; i++) {
        sa(c[i]);
        c[i] = mp[c[i]];
    }
    pii ans(0, 0);
    int id = 0;
    for (int i = 0; i < m; i++) {
        pii t(cnt[b[i]], cnt[c[i]]);
        if(t > ans) {
            ans = t;
            id = i;
        }
    }
    printf("%d\n", id + 1);
    return 0;
}
