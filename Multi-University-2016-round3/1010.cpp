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
    int a, v1, v2;
    while(scanf("%d%d%d", &a, &v1, &v2) == 3) {
        if(a == 0) {
            printf("0\n");
        } else {
            if(v1 <= v2) {
                printf("Infinity\n");
            } else {
                printf("%.10f\n", double(a) * v1 / (v1 * v1 - v2 * v2));
            }
        }
    }
    return 0;
}
