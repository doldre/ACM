/************************************************
 *Author        :mathon
 *Created Time  :三  4/13 20:35:18 2016
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

class FilipTheFrog {
public:
    int countReachableIslands(vector<int> positions, int L) {
        int res = 1;
        bool reachable[100];
        memset(reachable, 0, sizeof(reachable));
        for (int i  = 1; i < positions.size(); i++) {
            for (int j = 0; j < i; j++) {
                if(reachable[j] && positions[i] - positions[j] <= L) {
                    reachable[i] = true;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

/* int main(void) */
/* { */
/* #ifdef LOCAL */
/*     //freopen("in.txt", "r", stdin); */
/*     //freopen("out.txt", "w", stdout); */
/* #endif */

/*     return 0; */
/* } */
