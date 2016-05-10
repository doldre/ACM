/************************************************
 *Author        :mathon
 *Created Time  :六  5/ 7 23:27:28 2016
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
const int maxn = 5000 + 5;
pii cmp(pii a, pii b) {
    if(a.xx != b.xx) {
        if(a.xx > b.xx) return a;
        else return b;
    }
    if(a.yy < b.yy) return a;
    else return b;
}

struct Bit {
    pii bit[maxn];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            bit[i] = pii(0, 0);
        }
    }
    pii querry(int i) {
        pii res(0, 0);
        for (; i > 0; i -= lowbit(i)) {
            res = cmp(res, bit[i]);
        }
        return res;
    }
    void modify(int i, pii x) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] = cmp(x, bit[i]);
        }
    }
}bit;

int A[maxn];
int cnt[maxn];
int res[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    for (int i = 1; i <= n; i++) {
        sa(A[i]);
    }
    for (int i = 1; i <= n; i++) {
        bit.init(n);
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j <= n; j++) {
            cnt[A[j]]++;
            bit.modify(A[j], pii(cnt[A[j]], A[j]));
            pii q = bit.querry(n);
            res[q.yy]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", res[i], i == n ? '\n' : ' ');
    }
    return 0;
}
