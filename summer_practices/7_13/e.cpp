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
const double pi = acos(-1.0);
const int maxn = 1e4 + 5;
double R[maxn];
int N, F;
bool judge(double v) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += floor(R[i] * R[i] * pi / v);
    }
    return cnt >= (F+1);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Case = 1; Case <= T; Case++) {
        scanf("%d%d", &N, &F);
        for (int i = 0; i < N; i++) {
            scanf("%lf", &R[i]);
        }

        double l = 0, r = 1e15;
        for (int i = 0; i < 250; i++) {
            double m = (l + r) / 2;
            if(judge(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        printf("%.4lf\n", l);
    }
    return 0;
}

