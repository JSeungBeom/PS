#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define X first
#define Y second

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[105][105][20005]; 
int turn = 0;

void move_robot(pair<int, int> st, pair<int, int> en, bool chk){
    bool vis[105][105] = { 0 };
    queue<pair<int, int>> q;
    q.push(st);
    
    vis[st.X][st.Y] = 1;
        
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur == en){
            if(chk){
                turn++;
                board[cur.X][cur.Y][turn]++;
            }
            return;
        }
        turn++;
        board[cur.X][cur.Y][turn]++;
                

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
             
            if(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
            if(vis[nx][ny]) continue;
            
            int cur_dist = abs(cur.X - en.X) + abs(cur.Y - en.Y);
            int nxt_dist = abs(nx - en.X) + abs(ny - en.Y);
            
            if(nxt_dist < cur_dist){
                q.push({nx, ny});
                vis[nx][ny] = 1;
                break;
            }
        }
    }
}

int chk_danger(){
    int cnt = 0;
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            for(int turn = 0; turn < 20005; turn++){
                if(board[i][j][turn] >= 2) {
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    for(int i = 0; i < (int)routes.size(); i++){
        turn = 0; 
        bool chk = 0;
        for(int j = 0; j < (int)routes[i].size() - 1; j++){
            pair<int, int> st = {points[routes[i][j] - 1][0] - 1, points[routes[i][j] - 1][1] - 1};
            pair<int, int> en = {points[routes[i][j + 1] - 1][0] - 1, points[routes[i][j + 1] - 1][1] - 1};
            if(j == (int)routes[i].size() - 2){
                chk = 1;
            }
            move_robot(st, en, chk);
        }
    }
    
    answer = chk_danger();
    
    
    
    return answer;
}