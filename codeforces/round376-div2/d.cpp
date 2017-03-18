#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x << " "

const int MAXN = 5e5 + 5;
vector<int> words[MAXN];
int n, c;

vector<pii> V;
void get_inter(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < (int)a.size() && i < (int)b.size(); i++) {
        if(a[i] != b[i]) {
            int x = (b[i] - a[i] + c) % c;
            int t1 = -a[i], t2 = c - x - 1 - a[i];
            t1 = (t1 + c) % c, t2 = (t2 + c) % c;
            // pr(t1); prln(t2);
            if(t1 <= t2) {
                V.push_back(pii(t1, 1));
                V.push_back(pii(t2 + 1, -1));
            } else {
                V.push_back(pii(t1, 1));
                V.push_back(pii(c, -1));
                V.push_back(pii(0, 1));
                V.push_back(pii(t2 + 1, -1));
            }
            return;
        }
    }
    if(a.size() <= b.size()) {
        V.push_back(pii(0, 1));
        V.push_back(pii(c, -1));
        // pr(0); prln(c);
    }
}

int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        int l; scanf("%d", &l);
        for (int j = 1; j <= l; j++) {
            int x; scanf("%d", &x);
            words[i].push_back(x-1);
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        get_inter(words[i], words[i+1]);
    }
    int ans = -1;
    int sum = 0;
    sort(V.begin(), V.end());
    for (int i = 0; i < (int)V.size(); i++) {
        // pr(V[i].first); prln(V[i].second);
        sum += V[i].second;
        if(sum >= n - 1) {
            ans = V[i].first;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
