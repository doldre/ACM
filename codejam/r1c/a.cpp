/************************************************
 *Author        :mathon
 *Created Time  :日  5/ 8 17:06:19 2016
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

const int maxn = 100;
int cnt[maxn];

int main(void)
{
#ifdef LOCAL
   freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int N;
        memset(cnt, 0, sizeof(cnt));
        sa(N);
       riority_queue<pii> que;
        int tot = 0;
        for (int i = 0; i < N; i++) {
            int x;
            sa(x);
            tot += x;
            que.push(pii(x, i));
        }
        printf("Case #%d:", Cas);
        while(tot > 0) {
            pii cur = que.top(); que.pop();
            printf(" %c", cur.yy + 'A');
            tot--;
            cur.xx--;
            if(cur.xx != 0) {
                que.push(cur);
            }
            if(tot % 2 == 1) {
                pii cur = que.top(); que.pop();
                printf("%c", cur.yy + 'A');
                tot--;
                cur.xx--;
                if(cur.xx != 0) {
                    que.push(cur);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
