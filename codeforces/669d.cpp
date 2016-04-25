/************************************************
 *Author        :mathon
 *Created Time  :一  4/25 14:42:23 2016
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
int ans[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    int even = 0, odd = 0;
    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int x;
            scanf("%d", &x);
            even += x, odd += x;
            even %= n, odd %= n;
        } else {
            if(even % 2 == 0) {
                even += 1;
                odd -= 1;
            } else {
                even -= 1;
                odd += 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int t = ((i + (i % 2 == 0 ? even : odd)) % n + n) % n + 1;
        ans[t] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
