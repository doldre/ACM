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


const int AC_SIGMA = 26, AC_N = 210;
struct AC_automaton {
    int next[AC_N][AC_SIGMA], fail[AC_N], end[AC_N];
    int pos[AC_N];
    int root, L;
    int newnode() {
        for (int i = 0; i < AC_SIGMA; i++) {
            next[L][i] = -1;
        }
        end[L] = 0;
        return L++;
    }

    void init() {
        L = 0;
        root = newnode();
    }

    void insert(char buf[], int len, int num) {
        int now = root;
        for (int i = 0; i < len; i++) {
            if(next[now][(int)buf[i]] == -1) {
                next[now][(int)buf[i]] = newnode();
            }
            now = next[now][(int)buf[i]];
        }
        pos[num] = now;
        end[now] ++;
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < AC_SIGMA; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if(next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    int querry(char buf[]) {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = next[now][(int)buf[i]];
            int temp = now;
            while(temp != root) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
}ac_automaton;

const double eps = 1e-9;
const int MAXN = 220;
double a[MAXN][MAXN], x[MAXN];
int equ, var; //方程数和未知数个数

int Gauss() {
    int i,j,k,col,max_r; 
    for(k=0,col=0;k<equ&&col<var;k++,col++) {
        max_r=k; 
        for(i=k+1;i<equ;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col])) 
                max_r=i;
        if(fabs(a[max_r][col])<eps)return 0; 
        if(k!=max_r)
        {
            for(j=col;j<var;j++) 
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col]; 
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col]; 
        a[k][col]=1;
        for(i=0;i<equ;i++)
            if(i!=k) {
                x[i]-=x[k]*a[i][k]; 
                for(j=col+1;j<var;j++)
                    a[i][j]-=a[k][j]*a[i][col]; a[i][col]=0;
            } 
    }
    return 1; 
}

int n, l, m;
double P[MAXN];
char str[MAXN];

void gauss_build() {
    memset(a, 0, sizeof(a));
    memset(x, 0, sizeof(x));
    equ = ac_automaton.L;
    var = ac_automaton.L;
    for (int i = 0; i < var; i++) {
        a[i][i] = -1;
    }
    x[0] = -1;
    for (int i = 0; i < ac_automaton.L; i++) {
        if(ac_automaton.end[i] == 0) {
            for (int j = 0; j < m; j++) {
                int y = ac_automaton.next[i][j];
                // pr(i); prln(y);
                a[y][i] += P[j];
                // if(y != 0) a[y][i] += P[j];
                // else a[y][i] -= P[j];
            }
        }
    }
    // int t = 0;
    // memset(a[t], 0, sizeof(a[t]));
    // for (int i = 0; i < n; i++) {
        // a[t][ac_automaton.pos[i]] = 1;
    // }
    // x[t] = 1;
    // equ++;
    // a[equ][0] = 1;
    // x[equ] = 1;
    // equ++;
    // for (int i = 0; i < equ; i++) {
        // for (int j = 0; j <= var; j++) {
            // printf("%.2f ", a[i][j]);
        // }
        // puts("");
    // }
}
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &l);
        m = 6;
        for (int i = 0; i < 6; i++) {
            P[i] = 1.0 / 6;
        }
        ac_automaton.init();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                int x; scanf("%d", &x);
                x--;
                str[j] = x;
            }
            ac_automaton.insert(str, l, i);
        }
        ac_automaton.build();
        gauss_build();
        Gauss();
        for (int i = 0; i < n; i++) {
            if(i) printf(" ");
            printf("%.6f", fabs(x[ac_automaton.pos[i]]));
        }
        puts("");
    }
    return 0;
}

