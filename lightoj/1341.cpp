/************************************************
 *Author        :mathon
 *Created Time  :四  4/21 21:22:04 2016
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

const int maxn = 1e6 + 5;
int primes[maxn];
bool isprime[maxn];
int cntp = 0;
void init() {
    memset(isprime, true, sizeof(isprime));

    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) {
            primes[cntp++] = i;
            for (int j = i + i; j < maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    init();
    cin >> T;
    for (int Cas = 1; Cas <= T; Cas++) {
        ll a, b;
        cin >> a >> b;
        ll t = a;
        if(a / b <= b) {
            printf("Case %d: %d\n", Cas, 0);
            continue;
        }
        int ans = 1;
        for (int i = 0; i < cntp && primes[i] * primes[i] <= a; i++) {
            int cnt = 0;
            int x = primes[i];
            while(a % x == 0) {
                cnt++;
                a /= x;
            }
            ans *= (cnt + 1);
        }
        if(a > 1) ans *= 2;
        ans /= 2;
        for (int i = 1; i < b; i++) {
            if(t % i == 0) ans--;
        }
        printf("Case %d: %d\n", Cas, ans);
    }
    return 0;
}
