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
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 1100;
struct Node {
    string name;
    map<string, int> mp;
}nds[MAXN];
int tot, root;

int newnode() {
    nds[tot].mp.clear();
    nds[tot].name.clear();
    //prln(tot);
    return tot++;
}

void insert(string str) {
    int p = root;
    int i = 0;
    while(i < (int)str.size()) {
        int j = i;
        while(j < (int)str.size() && str[j] != '/') j++;
        string buf = str.substr(i, j - i);
        if(j == (int)str.size()) {
            buf = '{' + buf;
        }
        i = j + 1;
        if(nds[p].mp.find(buf) == nds[p].mp.end()) {
            int nxt = newnode();
            nds[p].mp[buf] = nxt;
            nds[nxt].name = buf;
        }
        p = nds[p].mp[buf];
    }
}

void print_tab() {
    for (int i = 0; i < 4; i++) {
        putchar(' ');
    }
}

void print(int p, int pos) {
    for (int i = 0; i < pos; i++) {
        print_tab();
    }
    if(nds[p].name[0] == '{') {
        nds[p].name = nds[p].name.substr(1, nds[p].name.size() - 1);
    }
    cout << nds[p].name << endl;
    map<string, int>::iterator it;
    for (it = nds[p].mp.begin(); it != nds[p].mp.end(); it++) {
        print(it->second, pos+1);
    }
}

char buf[MAXN];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Cas = 0;
    do {
        tot = 0; root = newnode();
        int cnt = 0;
        while(gets(buf)) {
            if(buf[0] == '0' && strlen(buf) == 1) break;
            cnt++;
            insert(string(buf));
        }
        if(cnt == 0) break;
        printf("Case %d:\n", ++Cas);
        map<string, int>::iterator it;
        for (it = nds[root].mp.begin(); it != nds[root].mp.end(); it++) {
            print(it->second, 0);
        }
    } while(true);
    return 0;
}

