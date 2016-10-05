#include <set>
#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

set<int> st;
bool solve(int x) {
    st.erase(st.find(x));
    int b = x;
    x >>= 1;
    while(x > 0) {
        if(st.find(x) == st.end()) {
            st.insert(x);
            return true;
        }
        x >>= 1;
    }
    st.insert(b);
    return false;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        st.insert(x);
    }
    while(solve(*st.rbegin()));
    for (auto x: st) {
        printf("%d ", x);
    }
    return 0;
}

