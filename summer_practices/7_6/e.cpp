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
const int maxn = 1e3 + 5;
int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        while(n) {
            if(n <= 2) {
                ans += A[n - 1]; n = 0;
            } else if(n == 3) {
                ans += A[0] + A[1] + A[2]; n = 0;
            } else {
                ans += min(A[0] + A[n-1] + A[n-2] + A[0],
                        A[1] + A[0] + A[1] + A[n-1]);
                n -= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

