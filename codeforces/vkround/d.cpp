/************************************************
 *Author        :mathon
 *Created Time  :六  5/ 7 23:55:27 2016
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

const int maxn = 1000 + 5;
int cnt[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    sa(n); sa(k);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(n == 4 || k < n + 1) {
        printf("-1\n");
        return 0;
    }
    int f = n;
    for (; f == a || f == b || f == c || f == d; f--);
    cnt[a] = cnt[b] = cnt[c] = cnt[d] = cnt[f] = 1;
    printf("%d ", a);
    for (int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("%d %d %d %d\n", c, f, d, b);
    printf("%d ", c);
    for (int i = n; i >= 1; i--) {
        if(cnt[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("%d %d %d %d\n", a, f, b, d);
    return 0;
}
