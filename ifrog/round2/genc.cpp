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
    freopen("in.txt", "w", stdout);
#endif
    int T = 100;
    int op = 3;
    printf("%d\n", T);
    for (int i = 1; i <= T; i++) {
        int n = 3;
        printf("%d %d\n", n, op);
        for (int j = 1; j <= n; j++) {
            printf("%d ", rand() % 3);
        }
        puts("");
    }
    return 0;
}

