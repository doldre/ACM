#include <vector>
#include <set>
#include <cstdio>
using namespace std;
const int MAXN = 3e5 + 5;
vector<int> v[MAXN];
set<int> st;
int n, q;
int main(void) {
    scanf("%d%d", &n, &q);
    int tot = 0;
    for (int i = 1; i <= q; i++) {
        int t, x; scanf("%d%d", &t, &x);
        if(t == 1) {
            ++tot;
            v[x].push_back(tot);
            st.insert(tot);
        }
        if(t == 2) {
            for (int y: v[x]) {
                st.erase(y);
            }
            v[x].clear();
        }
        if(t == 3) {
            while(!st.empty() && *st.begin() <= x) 
                st.erase(st.begin());
        }
        printf("%d\n", (int)st.size());
    }
    return 0;
}

