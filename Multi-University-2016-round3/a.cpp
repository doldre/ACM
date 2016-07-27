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
const int maxn = 100 + 5;
char str[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    vector<ll> V;
    ll x = 2;
    for (int i = 1; i <= 6; i++) {
        // prln(x);
        V.push_back(x);
        x = x * x;
    }
    while(scanf("%s", str) == 1) {
        int len = strlen(str);
        if(len > 12) {
            printf("TAT\n");
        } else {
            sscanf(str, "%lld", &x);
            int p = upper_bound(V.begin(), V.end(), x) - V.begin();
            if(p > 5 || x == 0) {
                printf("TAT\n");
            } else {
                printf("%d\n", p);
            }
        }
    }
    return 0;
}

