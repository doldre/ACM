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
    int A, B, id;
    Node() {}
    Node(int A, int B):A(A), B(B) {};
    bool operator < (const Node &b) const {
        if(A - B != b.A - b.B) {
            return A - B > b.A - b.B;
        } else return A < b.A;
    }
}nds[MAXN];

class Cmp {
    public:
        bool operator () (const Node &a, const Node &b) {
            if(a.A != b.A) return a.A < b.A;
            else return a.id < b.id;
        }
};


int N, L;
int A[MAXN], B[MAXN], C[MAXN];

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &N, &L);
    multiset<Node, Cmp> st;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &A[i], &B[i]);
        nds[i] = Node(A[i], B[i]);
        nds[i].id = i;
        st.insert(nds[i]);
    }
    sort(nds + 1, nds + N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &C[i]);
    }
    int cur = 0, op = 0;
    for (int i = 1; i <= N; i++) {
        if(st.lower_bound(Node(L-cur, 0)) != st.end()) {
            printf("%d\n", i);
            return 0;
        } else {
            cur += nds[i].A - nds[i].B;
            st.erase(nds[i]);
            op += C[i];
            if(cur <= op) {
                puts("-1"); return 0;
            } 
        }
    }
    puts("-1");
    return 0;
}

