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
const int maxn = 100 + 5;
int A[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(A, -1, sizeof(A));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            A[x] = y;
        }
        int last = 100;
        for (int i = 1; i <= 2; i++) {
            if(A[i] == -1) {
                A[i] = last;
            }
            last = A[i];
        }
        last = 0;
        for (int i = n; i >= 3; i--) {
            if(A[i] == -1) {
                A[i] = last;
            } 
            last = A[i];
        }
        int p = A[1] + A[2], q = 0;
        for (int i = 1; i <= n; i++) {
            q += A[i];
        }
        int g = __gcd(p, q);
        p /= g; q /= g;
        printf("%d/%d\n", p, q);
    }
    return 0;
}
