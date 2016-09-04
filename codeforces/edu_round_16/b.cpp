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
const int MAXN = 3 * 1e5 + 5;
ll ans;
int A[MAXN];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    sort(A, A + n);
    ll pre = 0;
    ll ans = INF, ans_x = -1;
    for (int i = 0; i < n; i++) {
        pre += A[i];
        ll t = A[i] * (ll)(i + 1)  - pre + (sum - pre) - (ll)(n - i - 1) * A[i];
        if(t < ans) {
            ans = t;
            ans_x = A[i];
        }
    }
    cout << ans_x << endl;
    return 0;
}

