
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
const int maxn = 2e5 + 7;
int to[maxn];
int d[maxn];
int n;
void bfs() {
    queue<int> que;
    que.push(1);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        if(u + 1 <= n && d[u+1] == -1) {
            d[u+1] = d[u] + 1;
            que.push(u+1);
        }
        if(u - 1 >= 1 && d[u-1] == -1) {
            d[u-1] = d[u] + 1;
            que.push(u-1);
        }
        if(d[to[u]] == -1) {
            d[to[u]] = d[u] + 1;
            que.push(to[u]);
        }
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &to[i]);
    }
    memset(d, -1, sizeof(d));
    d[1] = 0;
    bfs();
    for (int i = 1; i <= n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}

