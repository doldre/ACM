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

const int MAXN = 1000 + 5;
struct Node {
    Node *right, *down;
    Node() {
        right = down = NULL;
    }
    int num;
};

Node nds[MAXN][MAXN];
int A[MAXN][MAXN];

void solve_row(int row1, int row2, int st1, int st2, int w) {
    Node *s1 = &nds[row1][0], *s2 = &nds[row2][0];
    for (int i = 0; i < st1; i++) {
        s1 = s1->right;
    }
    for (int i = 0; i < st2; i++) {
        s2 = s2->right;
    }
    for (int i = 0; i < w; i++) {
        Node *p = s1->down;
        s1->down = s2->down;
        s2->down = p;
        s1 = s1->right; s2 = s2->right;
    }
    return;
}

void solve_col(int col1, int col2, int st1, int st2, int h) {
    Node *s1 = &nds[0][col1], *s2 = &nds[0][col2];
    for (int i = 0; i < st1; i++) {
        s1 = s1->down; 
    }
    for (int i = 0; i < st2; i++) {
        s2 = s2->down;
    }
    for (int i = 0; i < h; i++) {
        Node *p = s1->right;
        s1->right = s2->right;
        s2->right = p;
        s1 = s1->down; s2 = s2->down;
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            nds[i][j].num = A[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            nds[i][j].right = &nds[i][j+1];
            nds[i][j].down = &nds[i+1][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b, c, d, h, w;
        scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
        solve_row(a - 1, c - 1, b, d, w);
        solve_row(a + h - 1, c + h - 1, b, d, w);
        solve_col(b - 1, d - 1, a, c, h);
        solve_col(b + w - 1, d + w - 1, a, c, h);
    }
    for (int i = 1; i <= n; i++) {
        Node *p = nds[i][0].right;
        for (int j = 1; j <= m; j++) {
            printf("%d ", p->num);
            p = p->right;
        }
        puts("");
    }
    return 0;
}
