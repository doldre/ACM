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
    int x, y;
    scanf("%d%d", &x, &y);
    int A[3];
    int ans = 0;
    for (int i = 0; i < 3; i++) A[i] = y;
    sort(A, A + 3);
    while(A[0] < x) {
        ans ++;
        A[0] = min(A[1] + A[2] - 1, x);
        sort(A, A + 3);
    }
    cout << ans << endl;
    return 0;
}
