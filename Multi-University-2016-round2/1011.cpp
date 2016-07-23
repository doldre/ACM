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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int sum = 0, cnt_odd = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            if(x % 2) {
                cnt_odd++;
                sum += x - 1;
            } else {
                sum += x;
            }
        }
        if(cnt_odd == 0) {
            printf("%d\n", sum);
        } else {
            printf("%d\n", sum / (2 * cnt_odd) * 2 + 1);
        }
    }
    return 0;
}

