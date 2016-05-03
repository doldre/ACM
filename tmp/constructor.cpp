/************************************************
 *Author        :mathon
 *Created Time  :四  4/28 11:09:00 2016
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1e5;
const int mod = 1e9;
int A[3] = {1000, 10000, 100000};
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 3;
    cout << T << endl;
    while(T--) {
        int n = A[2 - T], m = A[2 - T];
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            cout << rand() % mod << " ";
        }
        cout << endl;
        for (int i = 0; i < m; i++) {
            cout << rand() % mod << " ";
        }
        cout << endl;
    }
    return 0;
}
