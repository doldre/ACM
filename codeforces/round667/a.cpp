/************************************************
 *Author        :mathon
 *Created Time  :六  4/30 00:34:57 2016
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

double pi = acos(-1);
const double eps = 1e-9;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    double d, h, v, e;
    cin >> d >> h >> v >> e;
    double vol = pi * (d / 2) * (d / 2) * h;
    double t = pi * (d / 2) * (d / 2) * e;
    double det = v - t;
    if(det <= eps) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        printf("%.9f\n", vol / det);
    }
    return 0;
}
