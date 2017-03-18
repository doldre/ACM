#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

// num 为棋盘大小：num*num
// i0 为棋子起始行号（1~num）
// j0 为棋子起始列号（1~num）
// in 为棋子终止行号（1~num）
// jn 为棋子终止列号（1~num）
// step 为最大移动步数
// data 为棋盘格子分数，data[i][j]为第(i-1)行，第(j-1)列的分数。
// 返回值为获得的最大分数。如果无法移动到终止位置，则输出-1
// path 为棋子最佳移动路线。如果有多条，则输出路径最短的一条。如果路径最短的有多条，则输出任意一条。初始位置和终止位置也需要输出。如果无法移动到终止位置，则不输出path

struct Node {
    int x, y, step;
    Node() {}
    Node(int x, int y, int step):x(x), y(y), step(step) {}
};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dp[15][15][15*15]; // dp[i][j][k]
Node last[15][15][15*15];
int used[15][15];
int n, m;
bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int step, int max_step, int score, const vector<vector<int> >& data) {
    if (step > max_step) return;
    // printf("x = %d, y = %d, step = %d\n", x, y, step);
    dp[x][y][step] = score;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        int old_used = used[nx][ny];
        if(inside(nx, ny)) {
            int nscore =  score + (1 - used[nx][ny]) * data[nx][ny];
            if (nscore > dp[nx][ny][step + 1]) {
                used[nx][ny] = 1;
                last[nx][ny][step + 1] = Node(x, y, step);
                dfs(nx, ny, step + 1, max_step, nscore, data);
            }
        }
        used[nx][ny] = old_used;
    }
}

int FindPath(int num, int i0, int j0, int in, int jn, int step, const vector< vector<int> >& data, vector< pair<int,int> >& path)
{
    n = m = num;
    memset(dp, -1, sizeof(-1));
    memset(last, -1, sizeof(-1));
    dfs(i0, j0, 0, step, data[i0][j0], data);
    int best_score = 0, best_step = 0x3f3f3f3f;
    for (int s = step; s >= 0; s--) {
        // printf("s = %d, dp = %d\n", s, dp[in][jn][s]);
        if (dp[in][jn][s] >= best_score) {
            best_score = dp[in][jn][s];
            best_step = s;
        }
    }
    int x = in, y = jn, s = best_step;
    while(s >= 0) {
        path.push_back(make_pair(x + 1, y + 1));
        x = last[x][y][s].x;
        y = last[x][y][s].y;
        s--;
    }
    reverse(path.begin(), path.end());
    return best_score;
}                   
                    
int main(int argc, char* argv[])
{                   
    int num = 3;
    int step = 0;
    int i0 = 0;     
    int j0 = 0;     
    int in = 0;         
    int jn = 0;         
    vector< vector<int> > data(num);
    for (int i = 0; i < num; ++i) {
        data[i].resize(num);
        for (int j = 0; j < num; ++j) {
            cin >> data[i][j];
        }       
    }       
    cin >> i0 >> j0 >> in >> jn >> step;
    i0--; j0--; in--; jn--; 
    vector< pair<int,int> > path;
    int maxscore = FindPath(num, i0, j0, in, jn, step, data, path);
    
    cout << maxscore << endl;
    if (maxscore >= 0) {
        // printf("path.size %d", (int)path.size());
        for (int i = 0; i < (int)path.size(); ++i) {
            if (i>0) cout << " ";
            cout << path[i].first << "," << path[i].second;
        }
    }
    cout << endl;

    return 0;
}
