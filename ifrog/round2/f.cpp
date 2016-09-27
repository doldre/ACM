/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
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

void dfs(Node *rt) {
    if(rt == NULL) return;
    merge_tree(rt->ch[0], rt->ch[1]);
    dfs(rt->ch[0]);
    dfs(rt->ch[1]);
}

int solve_or_2() {
    dfs(root);
    int res = 0;
    for (int k = 1; k <= n; k++) {
        int x = A[k];
        int ans = 0;
        Node *p = root;
        for (int i = 20; i >= 0; i--) {
            int t = (x>>i) & 1;
            if(t) {
                ans |= 1<<i;
                p = p->ch[0];
            } else {
                if(p->ch[1] != NULL) {
                    ans |= 1<<i;
                    p = p->ch[1];
                } else {
                    p = p->ch[0];
                }
            }
        }
        res = max(res, ans);
    }
    return res;
}

int brut(int op) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t;
            if(op == 1) {
                t = A[i] & A[j];
            } else if(op == 2) {
                t = A[i] ^ A[j];
            } else if(op == 3) {
                t = A[i] | A[j];
            }
            ans = max(ans, t);
        }
    }
    return ans;
}

void print_bin(int x) {
    string str;
    while(x > 0) {
        str.push_back(x % 2 + '0');
        x /= 2;
    }
    reverse(str.begin(), str.end());
    cout << str;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
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
            ans = solve_or_2();
        }
        // destroy(root);
        printf("Case #%d: %d\n", Cas, ans);
    }
    return 0;
}

