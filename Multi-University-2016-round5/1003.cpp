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
const int maxn = 1e6 + 5;
int A[maxn];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        ll sum = 0;
        for (int i = n; i > 0; i--) {
           sum += A[i];
           if(sum >= 0) {
               ans++;
               sum = 0;
           }
        }
        printf("%d\n", ans);
    }
    return 0;
}

