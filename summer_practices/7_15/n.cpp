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
    int n;
    scanf("%d", &n);
    int not_fastened = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if(x == 0) {
            not_fastened++;
        }
    }
    bool ok = true;
    if(n == 1 && not_fastened == 1) {
        ok = false;
    }
    if(n > 1 && not_fastened != 1) {
        ok = false;
    }
    if(ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

