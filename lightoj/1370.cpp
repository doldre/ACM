#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1500000;
int euler[maxn];
vector<pii> A;
void euler_phi2() {
	for (int i = 0; i < maxn; i++) euler[i] = i;
	for (int i = 2; i < maxn; i++) {
		if(euler[i] == i) {
			for (int j = i; j < maxn; j += i) {
				euler[j] = euler[j] / i * (i - 1);
			}
		}
	}
    euler[1] = 0;
    A.push_back(pii(0, 0));
    for (int i = 1; i < maxn; i++) {
        if (euler[i] > (*A.rbegin()).first) {
            A.push_back(pii(euler[i], i));
        }
    }
}

int main() {
    euler_phi2();
    int T;
    scanf("%d\n", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n;
        scanf("%d", &n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            int p = lower_bound(A.begin(), A.end(), pii(x, 0)) - A.begin();
            ans += A[p].second;
        }
        printf("Case %d: %lld Xukha\n", Cas, ans);
    }
	return 0;
}
