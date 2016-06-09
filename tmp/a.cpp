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

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        set<int> s;
        for (int i = 0; i < 26; i++) {
            int x; scanf("%d", &x);
            if(x != 0) s.insert(x);
        }
        if(s.size() == 0) printf("%d\n", 0);
        else if(s.size() == 1) {
            int t = *s.begin();
            printf("%d\n", t * (t - 1) / 2);
        } else {
            int t = *s.begin();
            printf("%d\n", t - 1);
        }
    }
    return 0;
}
