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
const int MAXN = 49 + 5;
int board[MAXN][MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int cnt = (n*n + 1) / 2 - n / 2 * 4 - 1;
    int mid = cnt / 4;
    for (int i = 0; i < mid; i++) {
        board[i / (n / 2)][i % (n / 2)] = 1;
    }
    for (int i = 0; i <= n / 2; i++) {
        board[n / 2][i] = 1;
        board[i][n / 2] = 1;
    }
    int odd = 1, even = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = j > n / 2 ? n - 1 - j : j;
            int y = i > n / 2 ? n - 1 - i : i;
            if(board[x][y] == 0) {
                printf("%d ", even);
                even += 2;
            } else {
                printf("%d ", odd);
                odd += 2;
            }
        }
        puts("");
    }
    return 0;
}

