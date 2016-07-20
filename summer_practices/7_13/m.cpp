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
const int maxn = 1e6 + 5;
int N;
int sta[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &N) == 1) {
        memset(sta, 0, sizeof(sta));
        for (int i = 0; i < N; i++) {
            int l, p; scanf("%d%d", &l, &p);
            sta[l] = p;
            // prln(sta[l]);
        }
        priority_queue<int> que;
        int L, P; scanf("%d%d", &L, &P);
        int ans = 0;
        for (int i = L; i > 0; i--) {
            if(sta[i] > 0) {
                que.push(sta[i]);
            }
            while(P <= 0 && !que.empty()) {
                int cur = que.top(); que.pop();
                P += cur;
                ans++;
            }
            if(P <= 0) {
                ans = -1;
                break;
            }
            P--;
        }
        printf("%d\n", ans);
    }
    return 0;
}

