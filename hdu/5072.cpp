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
vector<int> fact[MAXN];
int prime[MAXN], cnt_prime;
bool is_prime[MAXN];
int cnt[MAXN];
int A[MAXN];
int n;

void init() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < MAXN; i++) {
        if(is_prime[i]) {
            fact[i].push_back(i);
            prime[cnt_prime++] = i;
            for (int j = i + i; j < MAXN; j += i) {
                is_prime[j] = false;
                fact[j].push_back(i);
            }
        }
    }
}

int count(int x) {
    if(x == 1) return 1;
    int len = fact[x].size();
    int ans = 0;
    for (int mask = 1; mask < 1<<len; mask++) {
        int t = 1;
        int c = 0;
        for (int i = 0; i < len; i++) {
            if((mask>>i) & 1) {
                c++;
                t *= fact[x][i];
            }
        }
        if(c & 1) {
            ans += cnt[t];
        } else ans -= cnt[t];
    }
    return ans;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            cnt[A[i]]++;
        }
        for (int i = 2; i < MAXN; i++) {
            for (int j = i + i; j < MAXN; j += i) {
                cnt[i] += cnt[j];
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll t = count(A[i]);
            // prln(t);
            ans += (t - 1) * (n - t);
        }
        ans = (ll)n * (n - 1) * (n - 2) / 6 - ans / 2;
        printf("%lld\n", ans);
    }
    return 0;
}

