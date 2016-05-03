/************************************************
 *Author        :mathon
 *Created Time  :四  4/28 10:35:01 2016
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

struct Node {
    Node *next[2];
    int v;
    Node() {
        next[0] = next[1] = NULL;
        v = 0;
    }
};

struct Trie {
    Node *root;
    void init() {
        if(root != NULL) {
            destroy(root);
        }
        root = new Node();
    }
    void insert(string s) {
        Node *p = root;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if(p->next[(int)s[i]] == NULL) {
                p->next[(int)s[i]] = new Node();
            }
            p = p->next[(int)s[i]];
        }
        p->v = 1;
    }

    void destroy(Node *rt) {
        for (int i = 0; i < 2; i++) {
            if(rt->next[i] != NULL) {
                destroy(rt->next[i]);
            }
        }
        delete rt;
    }

    int querry(string s) {
        int len = s.size();
        string ans;
        Node *p = root;
        for (int i = 0; i < len; i++) {
            if(p->next[(int)s[i] ^ 1] != NULL) {
                ans.push_back(1);
                p = p->next[(int)s[i] ^ 1];
            } else {
                ans.push_back(0);
                p = p->next[(int)s[i]];
            }
        }
        int res = 0;
        for (int i = 0; i < (int)ans.size(); i++) {
            res = res * 2 + ans[i];
        }
        return res;
    }

}trie;

string convert(int x) {
    string res;
    for (int i = 30; i >= 0; i--) {
        res.push_back((x>>i) & 1);
    }
    return res;
}

int main(void)
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("outpu.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        int n, m;
        sa(n); sa(m);
//        pr(n); prln(m);
        trie.init();
        for (int i = 0; i < n; i++) {
            int x;
            sa(x);
            string tmp = convert(x);
            trie.insert(tmp);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x;
            sa(x);
            string tmp = convert(x);
            ans = max(ans, trie.querry(tmp));
        }
        printf("%d\n", ans);
    }
    return 0;
}
