#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
int r, s, p;
int N, R, S, P;
const char char_set[] = "PRS";
void dfs(int deep, char c) {
    if(deep == N) {
        if(c == 'R') r++;
        if(c == 'S') s++;
        if(c == 'P') p++;
        return;
    }
    if(c == 'R') {
        dfs(deep + 1, 'R');
        dfs(deep + 1, 'S');
    }
    if(c == 'S') {
        dfs(deep + 1, 'S');
        dfs(deep + 1, 'P');
    }
    if(c == 'P') {
        dfs(deep + 1, 'P');
        dfs(deep + 1, 'R');
    }
}

string print(int deep, int i) {
    /* pr(deep); */
    /* prln(i); */
    if(deep == N) {
        /* prln(char_set[i]); */
        string res;
        res.push_back(char_set[i]);
        return res;
    }
    string a, b;
    if(i < 2) {
        a = print(deep + 1, i);
        b = print(deep + 1, i + 1);
    } else {
        a = print(deep + 1, 0);
        b = print(deep + 1, 2);
    }
    if(a > b) {
        swap(a, b);
    }
    return a + b;
}

int main() {
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d%d%d", &N, &R, &P, &S);
        printf("Case #%d: ", Cas);
        r = s = p = 0;
        dfs(0, 'P');
        string res;
        if(r == R && s == S && p == P) {
            /* printf("fuck P\n"); */
            res = print(0, 0);
            cout << res << endl;
            continue;
        }
        r = s = p = 0;
        dfs(0, 'R');
        if(r == R && s == S && p == P) {
            /* printf("fuck R\n"); */
            res = print(0, 1);
            cout << res << endl;
            continue;
        }
        r = s = p = 0;
        dfs(0, 'S');
        if(r == R && s == S && p == P) {
            /* printf("fuck S\n"); */
            res = print(0, 2);
            cout << res << endl;
            continue;
        }
        printf("IMPOSSIBLE\n");
    }
}
