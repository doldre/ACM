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

const int MAXN = 1e5 + 5;
int n, k;
int A[MAXN];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &k);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }
        printf("Case #%d: ", Cas);
        if(sum % k != 0) {
            puts("-1");
        } else {
            ll cur = 0;
            ll block = sum / k;
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if(cur > 0) {
                    ans++;
                }
                cur += A[i];
                while(cur > block) {
                    cur -= block;
                    ans++;
                }
                if(cur == block) cur = 0;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

