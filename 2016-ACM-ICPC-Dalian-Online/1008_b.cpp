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

const int MAXN = 1e5 + 5;
int A[MAXN];
struct Query {
    int x, l, r, id;
    bool operator < (const Query &b) const {
        return x > b.x;
    }
}qs[MAXN];
int N;
int ans[MAXN];
vector<int> vec[MAXN];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            vec[i].clear();
        }
        int M; scanf("%d", &M);
        multiset<Query> set;
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &qs[i].l, &qs[i].r);
            qs[i].x = A[qs[i].l];
            qs[i].id = i;
            vec[qs[i].l].push_back(i);
        }
        for (int i = 1; i <= N; i++) {
            multiset<Query>::iterator it;
            vector<Query> buf;
            for (it = set.begin(); it != set.end();) {
                if(it->x >= A[i]) {
                    if(it->r < i) {
                        ans[it->id] = it->x;
                        it = set.erase(it);
                        continue;
                    }
                    Query tmp = *it;
                    it = set.erase(it);
                    tmp.x = tmp.x % A[i];
                    if(tmp.x == 0) {
                        ans[tmp.id] = tmp.x;
                    } else set.insert(tmp);
                } else {
                    break;
                }
            }
            for (int j = 0; j < (int)vec[i].size(); j++) {
                set.insert(qs[vec[i][j]]);
            }
        }
        multiset<Query>::iterator it;
        for (it = set.begin(); it != set.end(); it++) {
            ans[it->id] = it->x;
        }
        for (int i = 0; i < M; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

