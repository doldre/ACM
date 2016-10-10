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

const int MAXN = 20 + 5;
int n, m;

bool judge(int A[]) {
    for (int i = 1; i <= m; i++) {
        if(A[i] != i) return false;
    }
    return true;
}

bool check(int A[]) {
    if(judge(A)) return true;
    bool ans = false;;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            swap(A[i], A[j]);
            if(judge(A)) ans = true;
            swap(A[i], A[j]);
        }
    }
    return ans;
    return false;
}

int A[MAXN][MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    bool ans = false;
    bool ok = true;;
    for (int i = 1; i <= n; i++) {
        if(!check(A[i])) {
            ok = false;
        }
    }
    ans |= ok;
    for (int k1 = 1; k1 <= m; k1++) {
        for (int k2 = 1; k2 <= m; k2++) {
            for (int i = 1; i <= n; i++) {
                swap(A[i][k1], A[i][k2]);
            }
            ok = true;
            for (int i = 1; i <= n; i++) {
                if(!check(A[i])) ok = false;
            }
            ans |= ok;
            for (int i = 1; i <= n; i++) {
                swap(A[i][k1], A[i][k2]);
            }
        }
    }
    if(ans) puts("YES");
    else puts("NO");
    return 0;
}

