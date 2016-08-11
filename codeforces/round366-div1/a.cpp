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

const int MAXN = 3e5 + 5;
int del[MAXN], cnt[MAXN];
int A[MAXN];
int num[MAXN];
int n, q;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    int ans = 0;
    int last = 0;
    int tot = 0;
    for (int i = 1; i <= q; i++) {
        int type, x;
        scanf("%d%d", &type, &x);
        if (type == 1) {
            ++tot;
            A[i] = x;
            cnt[x]++;
            ans++;
        } else if (type == 2) {
            ans -= cnt[x];
            del[x] = i;
            cnt[x] = 0;
        } else if (type == 3) {
            for (; last < i && num[last] <= x; last++) {
                if(A[last] > 0) {
                    int t = A[last];
                    if(del[t] < last) {
                        ans--;
                        del[t] = last;
                        cnt[t]--;
                    }
                }
            }
        }
        num[i] = tot;
        printf("%d\n", ans);
    }
    return 0;
}

