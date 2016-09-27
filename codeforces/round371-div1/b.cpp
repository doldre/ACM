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

int n;
int query(int x1, int y1, int x2, int y2) {
    if(x1 <= 0 || y1 <= 0 || x2 <= 0 || y2 <= 0) return 0;
    if(x1 >= n || y1 >= n || x2 >= n || y2 >= n) return 0;
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

void solve(int &x1, int &y1, int &x2, int &y2) {
   int l = x1, r = x2 + 1;
   while(l < r - 1) {
       int m = (l + r) >> 1;
        if(query(m, y1, x2, y2) > 0) {
            l = m;
        } else r = m;
   }
   x1 = l;
   l = x1 - 1, r = x2;
   while(l < r - 1) {
       int m = (l + r) >> 1;
       if(query(x1, y1, m, y2) > 0) {
           r = m;
       } else l = m;
   }
   x2 = r;
   l = y1, r = y2 + 1;
   while(l < r - 1) {
       int m = (l + r) >> 1;
       if(query(x1, m, x2, y2) > 0) {
           l = m;
       } else r = m;
   }
   y1 = l;
   l = y1 - 1, r = y2;
   while(l < r - 1) {
       int m = (l + r) >> 1;
       if(query(x1, y1, x2, m) > 0) {
           r = m;
       } else l = m;
   }
   y2 = r;
}

            
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = 1, x2 = n, y1 = 1, y2 = n;
    solve(x1, y1, x2, y2);
    if(query(x2 + 1, 1, n, n) > 0) {
        x3 = x2 + 1;
        x4 = n;
        y3 = 1; y4 = n;
    } else if(query(1, 1, x1 - 1, n) > 0) {
        x3 = 1; x4 = x1 - 1;
        y3 = 1; y4 = n;
    } else if(query(1, y2 + 1, n, n) > 0) {
        x3 = 1; x4 = n;
        y3 = y2 + 1; y4 = n;
    } else if(query(1, 1, n, y1 - 1) > 0) {
        x3 = 1; x4 = n;
        y3 = 1, y4 = y1 - 1;
    }
    solve(x3, y3, x4, y4);
    printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2,
            x3, y3, x4, y4);
    fflush(stdout);
    return 0;
}

