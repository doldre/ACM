#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
const int MAXN = 1e4 + 5;
short dp[MAXN][MAXN];
int A[MAXN];
int n;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) A[i] = read();
    sort(A + 1, A + n + 1);
    short ans = 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = 2;
    }
    for (int j = 2; j <= n - 1; j++) {
        int i = j - 1, k = j + 1;
        while(true) {
            if(i <= 0 || k > n) break;
            if((ans) * (A[j] - A[i]) > A[n] - A[1]) break;
            if((ans) * (A[k] - A[j]) > A[n] - A[1]) break;
            if(A[j] - A[i] < A[k] - A[j]) i--;
            if(A[j] - A[i] > A[k] - A[j]) k++;
            if(A[j] - A[i] == A[k] - A[j]) {
                dp[j][k] = max((int)dp[j][k], 2);
                dp[j][k] = max(dp[i][j] + 1, (int)dp[j][k]);
                ans = max(ans, dp[j][k]);
                i--; k++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

