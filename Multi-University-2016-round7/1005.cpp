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
pii ps[MAXN];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    int n; 
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            ps[i] = pii(x, i);
        }
        sort(ps + 1, ps + n + 1);
        vector<pii> ans;
        bool suc = true;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j < i && cnt < ps[i].xx && ps[j].xx < ps[i].xx; j++) {
                ans.push_back(pii(ps[i].yy, ps[j].yy));
                cnt++;
            }
            if(cnt != ps[i].xx) {
                suc = false;
                break;
            }
        }
        printf("Case #%d: ", Cas);
        if(suc) puts("Yes");
        else puts("No");
        if(suc) {
            printf("%d\n", (int)ans.size());
            for (int i = 0; i < (int)ans.size(); i++) {
                printf("%d %d\n", ans[i].xx, ans[i].yy);
            }
        }
    }
    return 0;
}

