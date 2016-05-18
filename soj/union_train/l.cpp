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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        int n;
        sa(n);
        int maxk = 0;
        int g = 0;
        bool has_zero = false;
        for (int i = 1; i <= n; i++) {
            int x;
            sa(x);
            if(x == 0) has_zero = true;
            g = gcd(g, x);
            maxk = max(x, maxk);
        }
        double res = maxk / g - n;
        int t = maxk / g;
        if(has_zero) {
            res += 1;
            t += 1;
        }
        for (int i = 1; i <= t; i++) {
            res += (double)(t) / (double)(i);
        }
        printf("%.0f\n", floor(res));
    }
    return 0;
}
