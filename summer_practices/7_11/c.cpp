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
const int maxn = 30 + 5;
int A[maxn][maxn], B[maxn][maxn];
int n;
int cal() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(A[i][j] == B[i][j]) {
                res++;
            }
        }
    }
    return res;
}

void turn() {
    int buf[maxn][maxn];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buf[j][n - 1 - i] = A[i][j];
        }
    }
    memcpy(A, buf, sizeof(buf));
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &B[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = max(ans, cal());
            turn();
        }
        cout << ans << endl;
    }
    return 0;
}

