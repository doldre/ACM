#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
typedef long long ll;
using namespace std;
const ll inf = (ll)1e15 + 7;
const int maxn = 100000 + 5;
struct Node {
    string str;
    ll t;
}A[maxn];

bool cmp(const Node &a, const Node &b) {
    return a.t < b.t;
}
int main() {
    cin.sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i].str >> A[i].t;
        }

        string a, b;
        int pa, pb;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if(A[i].str == a) {
                pa = i;
            }
            if(A[i].str == b) {
                pb = i;
            }
        }
        if(A[pa].t <= A[pb].t) {
            sort(A, A + n, cmp);
            for (int i = 0; i < n; i++) {
                cout << A[i].str << endl;
            }
        } else {
            A[pb].t = inf;
            sort(A, A + n, cmp);
            for (int i = 0; i < n - 1; i++) {
                cout << A[i].str << endl;
                if(A[i].str == a) cout << b << endl;
            }
        }
    }
    return 0;
}
