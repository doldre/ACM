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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) == 1) {
        if(n == 1) {
            double x;
            scanf("%lf", &x);
            printf("%.9f\n", x);
            continue;
        }
        double p1 = 0;
        for (int i = 1; i <= n; i++) {
            p1 += 1.0 * (i - 1);
        }
        p1 /= double(n) * (n - 1);
        double p2 = 0;
        for (int i = 1; i <= n; i++) {
            p2 += 1.0 * (i - 1) * (i - 2);
        }
        p2 /= double(n) * (n - 1) * (n - 2);
        double ans = 0;
        double x;
        scanf("%lf", &x);
        ans += x * p1;
        for (int i = 2; i <= n - 1; i++) {
            scanf("%lf", &x);
            ans += x * p2;
        }
        scanf("%lf", &x);
        ans += x * p1;
        printf("%.9f\n", ans);
    }
    return 0;
}

