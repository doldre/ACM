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

bool judge(int x1, int y1, int x2, int y2, int a, int b, int c, int d) {
    return (x1 <= a && y1 <= b && x2 >= c && y2 >= d);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, x11, y11, x12, y12, x21, y21, x22, y22;
    cin >> n >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2) {
        int cnt = judge(x1, y1, x2, y2, x11, y11, x12, y12) +
            judge(x1, y1, x2, y2, x21, y21, x22, y22);
        cout << cnt << endl;
    }
    return 0;
}

