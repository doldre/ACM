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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n, k; scanf("%d%d", &n, &k);
        printf("Case #%d: ", Cas);
        printf("%d %d", 2*k, k);
        for (int i = k - 1; i >= 1; i--) {
            printf(" %d", i);
        }
        for (int i = k + 1; i <= 2*k - 1; i++) {
            printf(" %d", i);
        }
        for (int i = 2*k + 1; i <= n; i++) {
            printf(" %d", i);
        }
        puts("");
    }
    return 0;
}

