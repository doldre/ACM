/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const ull seed1 = 10007;
const ull seed2 = 131;
const ull mod1 = 1e9 + 7;
const ull mod2 = 1e9 + 9;
const int MAXN = 1e5 + 5;
const int MAXL = 2e6 + 5;
int n, k;

string str;
string words[MAXN];
int flag[MAXL];

map<pair<ull, ull>, int> hash2word;

pair<ull, ull> cal_hash(string s) {
    int len = (int)s.size();
    ull _hash1 = 0, _hash2 = 0;
    for (int i = 0; i < len; i++) {
        _hash1 = (_hash1 * seed1 % mod1 + s[i]) % mod1;
        _hash2 = (_hash2 * seed2 % mod2 + s[i]) % mod2;
    }
    return make_pair(_hash1, _hash2);
}

void pre_solve() {
    ull C1 = 1, C2 = 1;
    for (int i = 0; i < k - 1; i++) {
        C1 = C1 * seed1 % mod1;
        C2 = C2 * seed2 % mod2;
    }

    ull _hash1 = 0, _hash2 = 0;
    for (int i = 0; i < k; i++) {
        _hash1 = (_hash1 * seed1 % mod1 + str[i]) % mod1;
        _hash2 = (_hash2 * seed2 % mod2 + str[i]) % mod2;
    }

    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < n * k; i++) {
        pair<ull, ull> t = make_pair(_hash1, _hash2);
        if(hash2word.count(t) == 0) flag[i] = 0;
        else flag[i] = hash2word[t];
        _hash1 = (((_hash1 - C1 * str[i]) % mod1 + mod1) % mod1 * seed1 + str[(i+k) % str.size()]) % mod1;
        _hash2 = (((_hash2 - C2 * str[i]) % mod2 + mod2) % mod2 * seed2 + str[(i+k) % str.size()]) % mod2;
    }
}

int used[MAXN];
int tim; 
bool solve(int s, bool print) {
    for (int i = 0; i < n; i++) {
        int t = flag[s + i * k];
        if(t == 0) return false;
        if(used[t] == tim) return false;
        used[t] = tim;
        if(print) printf("%d ", t);
    }
    return true;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    cin >> str;
    int g;
    cin >> g;
    for (int i = 1; i <= g; i++) {
        cin >> words[i];
        pair<ull, ull> _hash = cal_hash(words[i]);
        hash2word[_hash] = i;
    }

    pre_solve();
    tim = 0;
    for (int s = 0; s < k; s++) {
        tim++;
        if(solve(s, false)) {
            tim++;
            printf("YES\n");
            solve(s, true);
            puts("");
            return 0;
        }
    }

    puts("NO"); 
    return 0;
}

