/************************************************
 *Author        :mathon
 *Created Time  :五  5/ 6 01:29:06 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn =3e6 + 5;

int dec_pop_count(int x) {
    int t = 0;
    while(x) {
        t++;
        x /= 10;
    }
    return t;
}

char str[maxn];
char sub[maxn];
string buf[maxn];
int ind[maxn];
int cnt[20];
bool cmp(const int x, const int y) {
    string *a = &buf[x], *b = &buf[y];
    bool flag = false;
    if(a->size() > b->size()) {
        swap(a, b);
        flag = true;
    }
    char c = (*a)[0];
    for (int i = 0; i < (int)(*b).size(); i++) {
        if(c != (*b)[i]) {
            return ((c < (*b)[i]) ^ flag);
        }
    }
    return true;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> str;
    cin >> sub;
    int slen = strlen(str);
    int len = 0;
    for (; len < slen; len++) {
        if(slen - dec_pop_count(len) == len) {
            break;
        }
    }
    for (int i = 0; i < slen; i++) {
        cnt[str[i] - '0']++;
    }
    int t = len;
    while(t) {
        int m = t % 10;
        cnt[m]--;
        t /= 10;
    }
    int sublen = strlen(sub);
    for (int i = 0; i < sublen; i++) {
        cnt[sub[i] - '0']--;
    }
    int tot = 0;
    buf[tot++] = sub;
    for (int i = 0; i < 10; i++) {
        /* prln(cnt[i]); */
        while(cnt[i] > 0) {
            string a;
            a.push_back('0' + i);
            buf[tot++] = a;
            cnt[i]--;
        }
    }
    /* prln(len); */
    /* prln(sublen); */
    /* prln(tot); */
    for (int i = 0; i < tot; i++) ind[i] = i;
    if(tot > 1) sort(ind + 1, ind + tot, cmp);
    /* for (int i = 0; i < tot; i++) { */
    /*     printf("i = %d ind[i] = %d\n", i, ind[i]); */
    /* } */
    /* puts(""); */
    /* pr(ind[0]); */
    /* prln(buf[ind[0]]); */
    if(buf[ind[1]][0] == '0') {
        for (int i = 1; i < tot; i++) {
            if(buf[ind[i]][0] != '0') {
                /* pr(ind[i]); */
                /* prln(buf[ind[i]]); */
                swap(ind[1], ind[i]);
                break;
            }
        }
    }
    /* for (int i = 0; i < tot; i++) { */
    /*     printf("i = %d ind[i] = %d\n", i, ind[i]); */
    /* } */
    /* puts(""); */
    /* pr(ind[0]); */
    /* prln(buf[ind[0]]); */
    if(tot > 2) sort(ind + 2, ind + tot, cmp);

    /* for (int i = 0; i < tot; i++) { */
    /*     printf("i = %d ind[i] = %d\n", i, ind[i]); */
    /* } */
    /* puts(""); */
    /* pr(ind[0]); */
    /* prln(buf[ind[0]]); */
    if(len > 1 && buf[ind[1]][0] == '0') {
        cout << buf[ind[0]] << endl;
        cout << "FUCK" << endl;
        return 0;
    }
    /* puts(""); */
    bool tmp = buf[ind[0]][0] == '0';
    bool flag = true;
    for (int i = 1; i < tot; i++) {
        if(flag && i >= tmp + 1 && cmp(ind[0], ind[i])) {
            cout << buf[ind[0]];
            flag = false;
        }
        /* prln(buf[i]); */
        cout << buf[ind[i]];
    }
    if(flag) cout << buf[ind[0]];
    printf("\n");
    return 0;
}
