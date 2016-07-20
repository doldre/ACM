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
const int maxn = 2e5 + 5;
struct BIT {
    int bit[maxn + 1];
    int n;
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

    int querry(int l, int r) {
        return sum(r) - sum(l - 1);
    }
}bit;

struct Inter {
    int l, r, num;
    Inter(int l, int r):l(l), r(r) {}
    Inter() {}
    Inter(int l, int r, int num):l(l), r(r), num(num) {}
};
            
bool cmp(const Inter &a, const Inter &b) {
    return a.r < b.r;
}

vector<Inter> Querry, inters[3];
int n, m;
int cnt[3][maxn], tot[maxn];
int A[maxn];
bool isprime[maxn];
int fact_pos[maxn];
int L[maxn], R[maxn];
vector<int> primes;

void get_prime() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}


void cal(int ind) {
    sort(inters[ind].begin(), inters[ind].end(), cmp);
    bit.init(maxn-1);
    for (int i = 0, j = 0; i < (int)Querry.size(); i++) {
        for (; j < (int)inters[ind].size() && inters[ind][j].r <= Querry[i].r; j++) {
            // prln("ok");
            bit.update(inters[ind][j].l + 1, 1);
        }
        cnt[ind][Querry[i].num] = bit.querry(Querry[i].l + 1, Querry[i].r + 1);
    }
}

void solve() {
    memset(fact_pos, 0, sizeof(fact_pos));
    for (int i = 1; i <= n; i++) L[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x = A[i];
        // prln(x);
        for (int j = 0; primes[j] * primes[j] <= x; j++) {
            if(x % primes[j] == 0) {
                L[i] = max(L[i], fact_pos[primes[j]]);
                fact_pos[primes[j]] = i;
            }
            while(x % primes[j] == 0) {
                x /= primes[j];
            }
        }
        if(x > 1) {
            L[i] = max(L[i], fact_pos[x]);
            fact_pos[x] = i;
        }
    }

    for (int i = 0; i < maxn; i++) fact_pos[i] = n + 1;
    for (int i = 1; i <= n; i++) R[i] = n + 1;
    for (int i = n; i >= 1; i--) {
        int x = A[i];
        for (int j = 0; primes[j] * primes[j] <= x; j++) {
            if(x % primes[j] == 0) {
                R[i] = min(R[i], fact_pos[primes[j]]);
                fact_pos[primes[j]] = i;
            }

            while(x % primes[j] == 0) {
                x /= primes[j];
            }
        }
        if(x > 1) {
            R[i] = min(R[i], fact_pos[x]);
            fact_pos[x] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        // pr(L[i]); pr(i); prln(R[i]);
        inters[0].push_back(Inter(L[i], i));
        inters[1].push_back(Inter(i, R[i]));
        inters[2].push_back(Inter(L[i], R[i]));
    }
    for (int i = 0; i < 3; i++) {
        cal(i);
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    get_prime();
    while(scanf("%d%d", &n, &m) == 2 && n && m) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        Querry.clear();
        for (int i = 0; i < 3; i++) {
            inters[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            Querry.push_back(Inter(l, r, i));
            tot[i] = r - l + 1;
        }
        sort(Querry.begin(), Querry.end(), cmp);
        solve();
        for (int i = 1; i <= m; i++) {
            // pr(tot[i]); pr(cnt[0][i]); pr(cnt[1][i]); prln(cnt[2][i]);
            printf("%d\n", tot[i] - cnt[0][i] - cnt[1][i] + cnt[2][i]);
        }
    }
    return 0;
}
