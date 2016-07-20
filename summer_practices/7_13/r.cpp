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

const int maxn = 1e7 + 5;
int used[maxn];
pii work(int n) {
    for (int i = 0; i <= n; i++) used[i] = -1;
    int cnt = 0;
    int x = 1 % n;
    while(true) {
        if(used[x] != -1) {
            return pii(used[x], cnt - used[x]);
        }
        if(x == 0) {
            return pii(cnt, 0);
        } 
        used[x] = cnt;
        x = x * 10 % n;
        cnt++;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        pii ans = work(n);
        printf("%d %d\n", ans.xx, ans.yy);
    }
    return 0;
}

