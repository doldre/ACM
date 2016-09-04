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

const int MAXN = 1e5 + 5;
struct Node {
    Node* ch[2];
    int s;
    Node() {
        ch[0] = ch[1] = NULL;
        s = 0;
    }
}ns[MAXN * 50];
int tot = 0;
Node * newNode() {
    ns[tot] = Node();
    return &ns[tot++];
}

void destroy(Node *rt) {
    if(rt->ch[0] != NULL) destroy(rt->ch[0]);
    if(rt->ch[1] != NULL) destroy(rt->ch[1]);
    delete rt;
}

void cpy_tree(Node *&dest, Node *src) {
    dest = newNode();
    dest->s = src->s;
    if(src->ch[0] != NULL) cpy_tree(dest->ch[0], src->ch[0]);
    if(src->ch[1] != NULL) cpy_tree(dest->ch[1], src->ch[1]);
}

void merge_tree(Node *&dest, Node *src) {
    if(src == NULL) return;
    if(dest == NULL) dest = newNode();
    dest->s += src->s;
    merge_tree(dest->ch[0], src->ch[0]);
    merge_tree(dest->ch[1], src->ch[1]);
}

int n;
int A[MAXN];

Node *root;
void insert(int x) {
    Node *p = root;
    for (int i = 20; i >= 0; i--) {
        if(p->ch[(x>>i)&1] == NULL) {
            p->ch[(x>>i) & 1] = newNode();
        }
        p = p->ch[(x>>i) & 1];
        p->s++;
    }
}

int solve_and() {
    int ans = 0;
    Node *p = root;
    for (int i = 20; i >= 0; i--) {
        if(p->ch[1] != NULL && p->ch[1]->s > 1) {
            ans |= 1 << i;
            p = p->ch[1];
        } else {
            merge_tree(p->ch[0], p->ch[1]);
            p = p->ch[0];
        }
    }
    return ans;
}

int solve_xor() {
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        int x = A[k];
        int res = 0;
        Node *p = root;
        for (int i = 20; i >= 0; i--) {
            int t = (x >> i) & 1;
            if(p->ch[!t] != NULL) {
                res |= 1 << i;
                p = p->ch[!t];
            } else {
                p = p->ch[t];
            }
        }
        ans = max(ans, res);
    }
    return ans;
}

int solve_or() {
    Node *root2 = newNode();
    cpy_tree(root2, root);
    Node *p1 = root, *p2 = root2;
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
        if(p1->ch[1] != NULL) {
            ans |= 1 << i;
            p1 = p1->ch[1];
            int t0 = p2->ch[0] == NULL ? 0 : p2->ch[0]->s;
            int t1 = p2->ch[1] == NULL ? 0 : p2->ch[1]->s;
            if(t0 < t1) {
                merge_tree(p2->ch[1], p2->ch[0]);
                p2 = p2->ch[1];
            } else {
                merge_tree(p2->ch[0], p2->ch[1]);
                p2 = p2->ch[0];
            }
        } else {
            p1 = p1->ch[0];
            if(p2->ch[1] != NULL) {
                ans |= 1 << i;
                p2 = p2->ch[1];
            } else {
                p2 = p2->ch[0];
            }
        }
    }
    // destroy(root2);
    return ans;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int type;
        scanf("%d%d", &n, &type);
        tot = 0;
        root = newNode();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            insert(A[i]);
        }
        int ans = 0;
        if(type == 1) {
            ans = solve_and();
        } else if(type == 2) {
            ans = solve_xor();
        } else if(type == 3) {
            ans = solve_or();
        }
        // destroy(root);
        printf("Case #%d: %d\n", Cas, ans);
    }
    return 0;
}

