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

const int MAXN = 1e3 + 5;
int A[MAXN], B[MAXN];
int buf[MAXN];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        queue<int> que[MAXN];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
        }
        for (int i = 1; i <= n; i++) {
            int x = B[i];
            que[x].push(i);
        }
        bool suc = true;
        for (int i = 1; i <= n; i++) {
            int x = A[i];
            if(!que[x].empty()) {
                buf[i] = que[x].front();
                que[x].pop();
            } else {
                suc = false;
            }
        }
        for (int i = 0; i < m; i++) {
            int l, r; scanf("%d%d", &l, &r);
            sort(buf + l, buf + r + 1);
        }
        for (int i = 1; i <= n; i++) {
            if(buf[i] != i) {
                suc = false;
                break;
            }
        }
        if(suc) puts("Yes");
        else puts("No");
    }
    return 0;
}

