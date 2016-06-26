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
int count_base_7(int x) {
    int res = 0;
    while(x > 0) {
        res++;
        x /= 7;
    }
    if(res == 0) res++;
    return res;
}

int A[] = {0, 1, 2, 3, 4, 5, 6};
int buf[7];

int tonum(int a[], int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 7 + a[i];
    }
    return res;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int lena = count_base_7(n - 1), lenb = count_base_7(m - 1);
    if(lena + lenb > 7) {
        printf("0\n");
    } else {
        int res = 0;
        for (int mask = 0; mask < (1<<7); mask++) {
            if(__builtin_popcount(mask) == lena + lenb) {
                int cnt = 0;
                for (int i = 0; i < 7; i++) {
                    if((mask>>i) & 1) {
                        buf[cnt++] = A[i];
                    }
                }
                do {
                    int hour = tonum(buf, lena);
                    int mini = tonum(buf + lena, lenb);
                    if(hour < n && mini < m) res++;
                } while(next_permutation(buf, buf + cnt));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
