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

const double eps = 1e-9;

double l, v1, v2;
int n, k;

bool judge(double tt) {
    int nn = n;
    double ll = l;
    while(tt > eps) {
        double t2 = (ll - tt * v1) / (v2 - v1);
        if(t2 <= 0) return true;
        if(t2 > tt) return false;
        nn -= k;
        if(nn <= 0) break;
        ll -= v1 * t2;
        tt -= t2;
        double dist = t2 * (v2 - v1);
        double tmp = dist / (v1 + v2);
        ll -= tmp * v1;
        tt -= tmp;
    }
    return nn <= 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> l >> v1 >> v2 >> k;
    double low = 0, high = 1e9 + 1;
    for (int i = 0; i < 250; i++) {
        double mid = (low + high) / 2;
        if(judge(mid)) {
            high = mid;
        } else low = mid;
    }
    printf("%.9f\n", high);
    return 0;
}

