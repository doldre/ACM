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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        set<pii> st;
        while(n--) {
            int x, y; scanf("%d%d", &x, &y);
            x -= a; y -= b;
            int g = abs(gcd(x, y));
            x /= g; y /= g;
            st.insert(pii(x, y));
        }
        printf("%d\n", (int)st.size());
    }
    return 0;
}

