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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T); 
    for (int Cas = 1; Cas <= T; Cas++) {
        if(Cas > 1) printf("\n");
        printf("Case #%d:\n", Cas);
        int n; scanf("%d", &n);
        multiset<pii> S;
        while(n--) {
            pii p;
            scanf("%d%d", &p.xx, &p.yy);
            auto it = S.lower_bound(p);
            if(it == S.begin() || (--it)->yy > p.yy) {
                S.insert(p);
                it = S.upper_bound(p);
                while(it != S.end() && it->yy >= p.yy) {
                    S.erase(it++);
                }
            }
            printf("%d\n", (int)S.size());
        }
    }
    return 0;
}

