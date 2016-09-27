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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAXN = 100 + 5;
int G[MAXN][MAXN];
int mp[MAXN][MAXN];
int used[MAXN][MAXN], stamp;
struct Character {
    int hp, at, mv, ad1, ad2, x, y, gr;
}chs[MAXN];

int N, M, C, E;

bool check_illegal(int mv, int x, int y) {
    if(x < 1 || x > N || y < 1 || y > M) return false;
    if(mp[x][y] != 0) return false;
    if(G[x][y] > mv) return false;
    return true;
}

bool is_enemy_around(int gr, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        if(mp[nx][ny] != 0 && chs[mp[nx][ny]].gr != gr) return true;
    }
    return false;
}

int can_go(int id, int sx, int sy) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            used[i][j] = -1;
        }
    }
    int cur_mv = chs[id].mv;
    if(chs[id].x == sx && chs[id].y == sy) {
        return cur_mv;
    }
    used[chs[id].x][chs[id].y] = cur_mv;
    priority_queue<pair<int, pii> > que; // mv值，坐标
    que.push(make_pair(cur_mv, pii(chs[id].x, chs[id].y)));
    while(!que.empty()) {
        pair<int, pii> cur = que.top(); que.pop();
        int mv = cur.xx, x = cur.yy.xx, y = cur.yy.yy;
        // pr(id); pr(x); pr(y); prln(mv);
        if(x == sx && y == sy) {
            return mv;
        }
        if(mv < used[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            // pr(nx); prln(ny);
            if(!check_illegal(mv, nx, ny)) {
                continue;
            }
            int nmv = mv - G[nx][ny];
            if(is_enemy_around(chs[id].gr, nx, ny)) nmv = 0;
            if(nmv > used[nx][ny]) {
                used[nx][ny] = nmv;
                que.push(make_pair(nmv, pii(nx, ny)));
            }
        }
    }
    return -1;
}

int dist(int a, int b) {
    return abs(chs[a].x - chs[b].x) + abs(chs[a].y - chs[b].y);
}

char buf[MAXN];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d%d%d", &N, &M, &C, &E) == 4) {
        memset(G, 0, sizeof(G));
        memset(mp, 0, sizeof(mp));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        for (int i = 1; i <= C; i++) {
            scanf("%d%d%d%d%d%d%d%d", &chs[i].hp, &chs[i].at, &chs[i].mv,
                  &chs[i].ad1, &chs[i].ad2, &chs[i].x, &chs[i].y, &chs[i].gr);
            mp[chs[i].x][chs[i].y] = i;
        }
        
        while(E--) {
            int round = 0, charater = 0;
            scanf("%s", buf);
            if(strcmp(buf, "Round") == 0) {
                scanf("%s%d", buf, &round);
            } else if(strcmp(buf, "Action") == 0) {
                scanf("%s%s%d", buf, buf, &charater);
                // if(chs[charater].hp <= 0) {
                    // charater = -1;
                // }
            } else if(strcmp(buf, "Move") == 0) {
                // prln(buf);
                int x, y;
                scanf("%s%s", buf, buf);
                sscanf(buf, "(%d,%d)", &x, &y);
                // pr(x); prln(y);
                if(charater == -1) {
                    puts("INVALID");
                    continue;
                }
                int res = can_go(charater, x, y);
                // prln(res);
                if(res == -1) {
                    puts("INVALID");
                } else {
                    mp[chs[charater].x][chs[charater].y] = 0;
                    chs[charater].x = x;
                    chs[charater].y = y;
                    mp[x][y] = charater;
                    printf("%d\n", res);
                }
            } else if(strcmp(buf, "Attack") == 0) {
                // prln(buf);
                int id;
                scanf("%d", &id);
                if(charater == -1 || chs[id].hp <= 0) {
                    puts("INVALID");
                    continue;
                }
                int d = dist(id, charater);
                if(d >= chs[charater].ad1 && d <= chs[charater].ad2) {
                    if(chs[id].hp <= chs[charater].at) {
                        puts("INVALID");
                    } else {
                        chs[id].hp -= chs[charater].at;
                        printf("%d\n", chs[id].hp);
                    }
                } else {
                    puts("INVALID");
                }
            } else if(strcmp(buf, "Drive") == 0) {
                // prln(buf);
                int id;
                scanf("%s%d", buf, &id);
                if(charater == -1 || chs[id].hp <= 0) {
                    puts("INVALID");
                    continue;
                }
                int d = dist(id, charater);
                if(d >= chs[charater].ad1 && d <= chs[charater].ad2) {
                    if(chs[id].hp > chs[charater].at) {
                        puts("INVALID");
                    } else {
                        chs[id].hp -= chs[charater].at;
                        printf("%d\n", chs[id].hp);
                        mp[chs[id].x][chs[id].y] = 0;
                    }
                } else {
                    puts("INVALID");
                }
            }
        }
    }
    return 0;
}

