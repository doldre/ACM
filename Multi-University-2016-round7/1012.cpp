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
const int MAXN = 5e5 + 5;
const int INF = 0x3f3f3f3f;
struct BIT {
    int bit[MAXN + 5], n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }
    void update(int i, int add) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += add;
        }
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;

int ocur[MAXN];
int N;
pii ps[MAXN];
vector<int> V[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &N) == 1 && N) {
        memset(ocur, 0, sizeof(ocur));
        bit.init(MAXN);
        for (int i = 0; i < MAXN; i++) {
            V[i].clear();
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &ps[i].xx, &ps[i].yy);
        }
        sort(ps, ps + N);
        for (int i = 0; i < N; i++) {
            V[ps[i].xx].push_back(ps[i].yy);
        }
        int last = 0;
        for (int i = 0; i < MAXN; i++) {
            if(V[i].size() > 0) {
                last = i;
                break;
            }
        }
        for (int i = 0; i < (int)V[last].size(); i++) {
            ocur[V[last][i]] = last;
            bit.update(V[last][i], 1);
        }
        bool suc = true;
        for (int i = last + 1; i < MAXN; i++) {
            if(V[i].size() > 0) {
                vector<int> up(V[i].size(), 0), down(V[i].size(), MAXN);
                for (int j = 0; j < (int)V[i].size(); j++) {
                    if(ocur[V[i][j]] == last) {
                        up[j] = V[i][j];
                        down[j] = V[i][j];
                    } else {
                        up[j] = j == 0 ? 0 : up[j-1];
                    }
                }
                for (int j = V[i].size() - 1; j >= 0; j--) {
                    if(ocur[V[i][j]] == last) {
                        up[j] = V[i][j];
                        down[j] = V[i][j];
                    } else {
                        down[j] = (j == (int)V[i].size() - 1) ? MAXN : up[j+1];
                    }
                }
                for (int j = 0; j < (int)V[i].size(); j++) {
                    if(up[j] < down[j]) {
                        if(bit.sum(down[j]) - bit.sum(up[j]) > 0) {
                            suc = false;
                            break;
                        }
                    }
                    ocur[V[i][j]] = i;
                    bit.update(V[i][j], 1);
                }
                last = i;
                if(!suc) break;
            }
            if(!suc) break;
        }
        if(suc) puts("YES");
        else puts("NO");
    }
    return 0;
}

