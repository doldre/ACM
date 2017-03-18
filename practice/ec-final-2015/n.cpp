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
vector<int> R[MAXN];
int r, c;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            R[i].clear();
            R[i].push_back(c);
        }
        int b; scanf("%d", &b);
        for (int i = 1; i <= b; i++) {
            int a, b; scanf("%d%d", &a, &b);
            R[a].push_back(b);
        }
        int ma = 0, mi = 0;
        for (int i = 0; i < r; i++) {
            sort(R[i].begin(), R[i].end());
            int last = -1;
            for (int j = 0; j < (int)R[i].size(); j++) {
                int t = R[i][j] - last - 1;
                last = R[i][j];
                ma += (t + 1) / 2; mi += (t + 2) / 3;
            }
        }
        printf("Case #%d: %d %d\n", Cas, ma, mi);
    }
    return 0;
}

