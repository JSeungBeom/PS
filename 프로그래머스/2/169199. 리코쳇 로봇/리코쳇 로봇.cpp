#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[105][105];
queue<pair<int, int>> q;

int solution(vector<string> board) {
    int answer = -1;
    
    int n = (int)board.size();
    int m = board[0].length();
    
    // 거리를 나타내는 2차원 배열 초기화
    for(int i = 0; i < n; i++){
        fill(dist[i], dist[i] + m + 1, -1);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'R'){ // 시작지점 큐에 삽입 및 거리 = 0
                q.push({i, j});
                dist[i][j] = 0; 
            }
        }
    }
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(board[cur.X][cur.Y] == 'G'){
            return dist[cur.X][cur.Y];
        }
            
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X;
            int ny = cur.Y;
            
            while(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 'D'){
                nx += dx[dir];
                ny += dy[dir];
            }
            
            nx -= dx[dir];
            ny -= dy[dir];
            
            if(dist[nx][ny] >= 0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    
    return answer;
}