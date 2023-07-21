#include <iostream>
using namespace std;

int N, M;
int board[500][500];
bool visited[500][500];
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

const int fuckShape[4][4][2] = {
    { {1,0},{0,1},{1,1},{1,2} },
    { {0,0},{0,1},{1,1},{0,2} },
    { {1,0},{0,1},{1,1},{2,1} },
    { {0,0},{1,0},{1,1},{2,0} }
};

bool isValid(int y, int x) {
    return !(y < 0 || y >= N || x < 0 || x >= M);
}
int fuck(int y, int x) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int cand = 0;
        for (int j = 0; j < 4; j++) {
            int ny = y + fuckShape[i][j][0];
            int nx = x + fuckShape[i][j][1];
            if (!isValid(ny, nx)) {
                cand = 0; break;
            }
            else
                cand += board[ny][nx];
        }
        ret = max(ret, cand);
    }
    return ret;
}

int dfs(int y, int x, int depth) {
    if (depth == 3) return board[y][x];
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isValid(ny, nx) && !visited[ny][nx]) {
            visited[ny][nx] = true;
            ret = max(ret, board[y][x] + dfs(ny, nx, depth + 1));
            visited[ny][nx] = false;
        }
    }
    return ret;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            visited[i][j] = true;
            ret = max(ret, dfs(i, j, 0));
            visited[i][j] = false;

            ret = max(ret, fuck(i, j));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    cout << solve();

    return 0;
}
