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

void solve_row(Node *s1, Node *s2, int w) {
    for (int i = 0; i < w; i++) {
        Node *p = s1->down;
        s1->down = s2->down;
        s2->down = p;
        s1 = s1->right; s2 = s2->right;
    }
    return;
}

void solve_col(Node *s1, Node *s2, int h) {
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
    // for (int i = 0; i <= n; i++) {
        // nds[0][i].right = &nds[0][i+1];
        // nds[0][i].down = &nds[1][i];
    // }
    // for (int i = 0; i <= n; i++) {
        // nds[i][0].down = &nds[i+1][0];
        // nds[i][0].right = &nds[i][1];
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            nds[i][j].num = A[i][j];
            // nds[i][j].right = &nds[i][j+1];
            // nds[i][j].down = &nds[i+1][j];
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
        Node *a1, *a2, *a3, *a4, *b1, *b2, *b3, *b4;
        a1 = &nds[a][0];
        for (int i = 0; i < b - 1; i++) {
            a1 = a1->right;
        }
        a4 = a1;
        for (int i = 0; i < w; i++) {
            a4 = a4->right;
        }
        a2 = &nds[0][b];
        for (int i = 0; i < a - 1; i++) {
            a2 = a2->down;
        }
        a3 = a2;
        for (int i = 0; i < h; i++) {
            a3 = a3->down;
        }
        b1 = &nds[c][0];
        for (int i = 0; i < d - 1; i++) {
            b1 = b1->right;
        }
        b4 = b1;
        for (int i = 0; i < w; i++) {
            b4 = b4->right;
        }
        b2 = &nds[0][d];
        for (int i = 0; i < c - 1; i++) {
            b2 = b2->down;
        }
        b3 = b2;
        for (int i = 0; i < h; i++) {
            b3 = b3->down;
        }
        solve_row(a3, b3, w);
        solve_col(a4, b4, h);
        solve_row(a2, b2, w);
        solve_col(a1, b1, h);
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
