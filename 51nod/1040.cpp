#include <cstdio>
#include <cstdlib>
typedef long long ll;
using namespace std;

int euler_phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			for (; n % i == 0; n /= i);
		}
	}
	if (n != 1) res = res / n * (n - 1);
	return res;
}
const int maxn = 1000;
int euler[maxn];

void euler_phi2() {
	for (int i = 0; i < maxn; i++) euler[i] = i;
	for (int i = 2; i < maxn; i++) {
		if(euler[i] == i) {
			for (int j = i; j < maxn; j += i) {
				euler[j] = euler[j] / i * (i - 1);
			}
		}
	}
}

int main() {
    int N; scanf("%d", &N);
    ll ans = 0;
    for (int i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            ans += (ll) i * euler_phi(N / i);
            int t = N / i;
            if(t != i) {
                ans += (ll) t * euler_phi(N / t);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
