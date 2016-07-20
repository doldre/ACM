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
const int maxn = 1000 + 5;
int A[maxn];
inline void shiftr(int l, int r, int pass) {
    int last = A[l];
    A[l] = A[r];
    for (int i = l + 1; i <= r; i++) {
        if(i == pass) continue;
        int t = A[i];
        A[i] = last;
        last = t;
    }
}

inline void shiftl(int l, int r, int pass) {
    int last = A[r];
    A[r] = A[l];
    for (int i = r - 1; i >= l; i--) {
        if(i == pass) continue;
        int t = A[i];
        A[i] = last;
        last = t;
    }
}
    
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(scanf("%d", &n) == 1) {
        if(n % 4 == 2 || n % 4 == 3) {
            puts("0");
        } else {
            for (int i = 1; i <= n; i++) {
                A[i] = n - i + 1;
            }
            int mid = n / 2, len = n / 4;
            if(n % 2 == 1) mid++;
            shiftl(1, mid, -1);
            if(n % 2 == 0) {
                shiftr(mid - len, mid + len, mid);
            } else {
                shiftr(mid - len, mid + len, mid);
            }
            for (int i = 1; i <= n; i++) {
                printf("%d%c", A[i], i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}

