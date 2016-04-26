/************************************************
 *Author        :mathon
 *Created Time  :四  4/21 20:50:01 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 10000000 + 5;
bool isprime[maxn];
vector<int> primes;
void init() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) {
            for (int j = i + i; j < maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) primes.push_back(i);
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T;
    scanf("%d", &T);
    int Cas = 0;
    while(T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < (int)primes.size() && primes[i] * 2 <= n; i++) {
            int r = n - primes[i];
            if(isprime[r]) ans++;
        }
        printf("Case %d: ", ++Cas);
        cout << ans << endl;
    }
    return 0;
}
