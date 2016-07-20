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
const int maxn = 3e6 + 5;
int cnt[maxn];
ll sum[maxn];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            if((ll)i * j >= maxn) {
                break;
            }
            if(i == j) sum[i*j] += (ll)cnt[i]*(cnt[i] - 1);
            else sum[i*j] += (ll)cnt[i] * cnt[j];
        }
    }
    for (int i = 1; i < maxn; i++) {
        sum[i] = sum[i] + sum[i-1];
    }
    
    scanf("%d", &m);
    ll tot = (ll)n * (n - 1);
    for (int i = 0; i < m; i++) {
        int p; scanf("%d", &p);
        printf("%lld\n", tot - sum[p-1]);
    }
    return 0;
}

