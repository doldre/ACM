#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
int A[maxn];
int dp[maxn][maxn];
int N;

ll dfs(int i, int j, int age) {
    if(dp[i][j]) return dp[i][j];
    if(i == j) return dp[i][j] = A[i] * age;
    return dp[i][j] = max(dfs(i + 1, j, age + 1) + age * A[i], dfs(i, j - 1, age + 1) + age * A[j]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    ll ans = dfs(0, N - 1, 1);
    cout << ans << endl;
    return 0;
}
