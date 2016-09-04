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
const int MAXN = 1e3 + 5;
char str[MAXN][10];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
        if(!ok) {
            if(str[i][0] == 'O' && str[i][1] == 'O') {
                str[i][0] = '+';
                str[i][1] = '+';
                ok = true;
            }
        }
        if(!ok) {
            if(str[i][3] == 'O' && str[i][4] == 'O') {
                str[i][3] = '+';
                str[i][4] = '+';
                ok = true;
            }
        }
    }
    if(!ok) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%s\n", str[i]);
        }
    }
    return 0;
}

