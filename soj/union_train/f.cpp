/************************************************
 *Author        :mathon
 *Created Time  :二  5/ 3 10:25:17 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;
int buf[maxn];
int n, maxstep;
bool ok = false;

bool judge(int cur, int step) {
    int res = cur;
    int t = maxstep - step;
    while(t--) {
        res += res;
    }
    if(res < n) return false;
    else return true;
}

void dfs(int cur,  int step) {
    if(ok || step > maxstep) return;
    if(cur == n) {
        ok = true;
        return;
    }

    if(!judge(cur, step)) return;
    for (int i = 0; i <= step; i++) {
        buf[step + 1] = cur + buf[i]; dfs(buf[step + 1], step + 1);
        buf[step + 1] = cur - buf[i]; dfs(buf[step + 1], step + 1);
    }

}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    buf[0] = 1;
    while(T--) {
        sa(n);
        ok = false;
        for (int i = 0; i <= 20; i++) {
            maxstep = i;
            dfs(1, 0);
            if(ok) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
