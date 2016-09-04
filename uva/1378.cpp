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

const int MAXN = 24;
bool used[2*MAXN*MAXN];
int n;
int sg[MAXN];
void init() {
    sg[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        memset(used, 0, sizeof(used));
        for (int j = 0; j < i; j++) {
            for (int k = 0; k <= j; k++) {
                used[sg[j] ^ sg[k]] = true;
            }
        }
        int t = 0;
        while(used[t]) t++;
        sg[i] = t;
    }
}

int S[MAXN];
int buf[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int n;
    int Cas = 0;
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &S[i]);
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if(S[i] > 0) for (int j = i + 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    S[i]--;
                    S[j]++;
                    S[k]++;
                    int res = 0;
                    for (int t = 1; t <= n; t++) {
                        if(S[t] & 1) {
                            res ^= sg[n - t];
                        }
                    }
                    if(!res) {
                        printf("Game %d: %d %d %d\n", ++Cas, i - 1, 
                                j - 1, k - 1);
                        flag = true;
                        break;
                    }
                    S[i]++;
                    S[j]--;
                    S[k]--;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) printf("Game %d: -1 -1 -1\n", ++Cas);
    }
    return 0;
}

