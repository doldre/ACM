#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 10000 + 5;
int A[MAXN];
int used[MAXN];
int n;
void dfs(int pos) {
    if(pos == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%5d", A[i]);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if(!used[i]) {
            used[i] = 1;
            A[pos] = i;
            dfs(pos + 1);
            used[i] = false;
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
