#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int maxn = 4e6 + 5;
int euler[maxn];
ll ans[maxn];
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
}

	
void init() {
	euler_phi2();
	for (int i = 1; i < maxn; i++) {
		for (int j = 1; j * i < maxn; j++) {
			ans[i*j] += i * euler[j];
		}
	}
	for (int i = 2; i < maxn; i++) {
		ans[i] += ans[i-1];
	}
}

int main() {
	init();
	int x;
	while(cin >> x && x) {
		cout << ans[x] << endl;
	}
	return 0;
}
