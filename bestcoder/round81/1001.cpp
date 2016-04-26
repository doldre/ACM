/************************************************
 *Author        :mathon
 *Created Time  :五  4/22 18:55:19 2016
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

char table[] = "RGB";

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int m;
        ll n;
        cin >> m >> n;
        for (int i = m - 1; i >= 0; i--) {
            if(pow(3.0, (double)i) < double(n) + 0.5) {
                ll t = ll(pow(3.0, (double)i));
                printf("%c", table[(n / t) % 3]);
            } else {
                printf("%c", table[0]);
            }
        }
        printf("\n");
    }
    return 0;
}
