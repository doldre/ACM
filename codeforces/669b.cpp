/************************************************
 *Author        :mathon
 *Created Time  :一  4/25 14:09:41 2016
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

const int maxn = 1e5 + 5;
char dir[maxn];
int d[maxn];
bool used[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    scanf("%s", dir);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    bool ok = true;
    int cur = 0;
    while(true) {
        if(cur < 0 || cur >= n) {
            ok = true;
            break;
        }
        if(used[cur]) {
            ok = false;
            break;
        }
        used[cur] = true;;
        if(dir[cur] == '>') {
            cur += d[cur];
        } else cur -= d[cur];
    }
    if(ok) {
        cout << "FINITE" << endl;
    } else cout << "INFINITE" << endl;
    return 0;
}
