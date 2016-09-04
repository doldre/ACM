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

double delta(int x) {
    return sqrt(1.0 + 8.0 * x);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    int n = (1 + delta(a00)) / 2 + 0.5, m = (1 + delta(a11)) / 2 + 0.5;
    bool flag = true;
    if(n * (n - 1) / 2 != a00) flag = false;
    if(m * (m - 1) / 2 != a11) flag = false;
    if(n == 1 && a10 == 0 && a01 == 0) n = 0;
    else if(m == 1 && a10 == 0 && a01 == 0) m = 0;
    if(a01 + a10 != n * m) flag = false;
    int len = n + m;
    if(flag) {
        for (int i = 0; i < len; i++) {
            if(a01 >= m) {
                printf("0");
                a01 -= m;
                n--;
            } else if(a10 >= n) {
                printf("1");
                a10 -= n;
                m--;
            }
        }
        puts("");
    } else {
        printf("Impossible\n");
    }
    return 0;
}

