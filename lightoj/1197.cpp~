/************************************************
 *Author        :mathon
 *Created Time  :2016年04月19日 星期二 10时53分20秒
 ***********************************************/
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;

int flag[maxn];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int Cas = 1; Cas <= T; Cas++) {
        ll a, b;
        memset(flag, 0, sizeof(flag));
        cin >> a >> b;
        for (ll i = 2; i*i <= b; i++) {
            for (ll j = max(i + i, (a + i - 1) / i * i); j <= b; j += i) {
//                printf("%d\n", j);
                flag[j-a] = 1;
            }
        }
        int cnt = 0;
        for (int i = 0; i <= b - a; i++) {
            if(flag[i] != 0) cnt++;
        }
        cout << "Case " << Cas << ": ";
        if(a == 1) cnt++;
        cout << b - a + 1 - cnt << endl;
    }
    return 0;
}
