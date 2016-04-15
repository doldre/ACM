/************************************************
 *Author        :mathon
 *Created Time  :五  4/15 15:05:15 2016
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;


int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    string str;
    int b;
    for (int Cas = 1; Cas <= T; Cas++) {
        cin >> str >> b;
        b = abs(b);
        int p = 0;
        if(str[0] == '-') {
            p = 1;
        }
        ll res = 0;
        for (; p < (int)str.size(); p++) {
            res = (res * 10 + str[p] - '0') % b;
        }
        printf("Case %d: ", Cas);
        if(res == 0) {
            printf("divisible\n");
        } else {
            printf("not divisible\n");
        }
    }
    return 0;
}
