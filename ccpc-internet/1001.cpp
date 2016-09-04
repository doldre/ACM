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
const int MOD = 73 * 137;
const int MAXN = 1e7 + 10;
char str[MAXN]; 
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Cas = 0;
    while(scanf("%s", str) == 1) {
        int res = 0;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            res = (res * 10 + str[i] - '0') % MOD;
        }
        printf("Case #%d: ", ++Cas);
        if(res == 0) puts("YES");
        else puts("NO");
    }
    return 0;
}

