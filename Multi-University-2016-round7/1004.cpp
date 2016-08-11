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

const int MAXX = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int cnt[MAXX];
bool is_prime[MAXX];
void init() {
    memset(is_prime, true, sizeof(is_prime));
    cnt[1] = 0;
    for (int i = 2; i < MAXX; i++) {
        if(is_prime[i]) {
            cnt[i] = 1;
            for (int j = i + i; j < MAXX; j += i) {
                is_prime[j] = false;
                int t = j, tmp = 0;
                while(t % i == 0) {
                    tmp++;
                    t /= i;
                }
                cnt[j] += tmp;
            }
        }
    }
}

multiset<int> S[MAXX];
multiset<int> all;

int main(void) {
#ifdef MATHON
    freopen("1004.in", "r", stdin);
    freopen("1004.txt", "w", stdout);
#endif
    init();
    int Q;
    int Cas = 0;
    while(scanf("%d", &Q) == 1 && Q) {
        printf("Case #%d:\n", ++Cas);
        for (int i = 0; i < MAXX; i++) {
            S[i].clear();
        }
        all.clear();
        char op[20]; int x;
        for (int i = 0; i < Q; i++) {
            scanf("%s%d", op, &x);
            if(op[0] == 'I') {
                if(all.find(x) != all.end()) continue;
                for (int i = 1; i * i <= x; i++) {
                    if(x % i == 0) {
                        S[i].insert(cnt[x / i]);
                        if(x / i != i) {
                            S[x / i].insert(cnt[i]);
                        }
                    }
                }
                all.insert(x);
            } else if(op[0] == 'D') {
                if(all.find(x) != all.end()) {
                    all.erase(all.find(x));
                    for (int i = 1; i * i <= x; i++) {
                        if(x % i == 0) {
                            S[i].erase(S[i].find(cnt[x / i]));
                            if(x / i != i) {
                                S[x / i].erase(S[x / i].find(cnt[i]));
                            }
                        } 
                    }
                }
            } else {
                int ans = INF; 
                for (int i = 1; i * i <= x; i++) {
                    if(x % i == 0) {
                        if(!S[i].empty()) ans = min(ans, *S[i].begin() + cnt[x / i]);
                        if(x / i != i) {
                            if(!S[x / i].empty()) ans = min(ans, *S[x / i].begin() + cnt[i]);
                        }
                    }
                }
                if(ans == INF) ans = -1;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

