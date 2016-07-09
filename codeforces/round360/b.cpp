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
const int maxn = 1e6 + 5;
int c[maxn];
vector<int> fac;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 2; i * i <= k; i++) {
       int t = 1;
       while(k % i == 0) {
           t *= i;
           k /= i;
       }
       if(t > 1) fac.push_back(t);
    }
    if(k > 1) fac.push_back(k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        for (int i = 0; i < (int)fac.size(); i++) {
            if(fac[i] != 1 && x % fac[i] == 0) {
                fac[i] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < (int)fac.size(); i++) {
        cnt += fac[i] == 1;
    }
    if(cnt == (int)fac.size()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

