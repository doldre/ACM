#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;
int A[maxn];
int cnt = 0;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if(c == '0') A[cnt++] = i;
    }
    int res = inf;
    if(k % 2 == 0) {
        for (int i = k / 2; i < cnt - k / 2; i++) {
            res = min(res, max(A[i] - A[i-k/2], A[i+k/2] - A[i]));
        }
    } else {
        res = min(res, max(A[k/2] - A[0], A[k] - A[k/2]));
        for (int i = k/2 + 1; i < cnt - k / 2 - 1; i++) {
            res = min(res, max(A[i] - A[i-k/2], A[i+k/2+1] - A[i]));
            res = min(res, max(A[i] - A[i-k/2-1], A[i+k/2] - A[i]));
        }
        res = min(res, max(A[cnt-1] - A[cnt-k/2], A[cnt-k/2] - A[cnt-k-1]));
    }
    cout << res << endl;
}
