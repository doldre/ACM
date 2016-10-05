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

bool is_ok(int x) {
    int last = x % 10;
    x /= 10;
    while(x > 0) {
        int t = x % 10;
        x /= 10;
        if(t != last - 1) return false;
        else last = t;
    }
    return true;
}

const int MAXN = 1000 + 5;
int A[MAXN];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = A[i] * A[j];
            if(is_ok(x)) ans = max(ans, x);
        }
    }
    printf("%d\n", ans);
    return 0;
}

