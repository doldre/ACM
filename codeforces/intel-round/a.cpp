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
    int n;
    int a, b;
    scanf("%d", &n);
    scanf("%d:%d", &a, &b);
    if(n == 12) {
        if(a == 0) a++;
        else if(a > 12) {
            a -= a / 10 * 10;
            if(a == 0) a += 10;
        }
        if(b > 59) {
            b -= b / 10 * 10;
        }
    } else {
        if(a > 23) {
            a -= a / 10 * 10;
        }
        if(b > 59) {
            b -= b / 10 * 10;
        }
    }
    printf("%02d:%02d\n", a, b);
    return 0;
}

