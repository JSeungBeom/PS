#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[105][105];
int dist[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void draw_line(vector<vector<int>> rectangle){
    for(int i = 0; i < rectangle.size(); i++){
        int rdx = rectangle[i][0];
        int rdy = rectangle[i][1];
        int lux = rectangle[i][2];
        int luy = rectangle[i][3];
        
        for(int j = rdx * 2; j <= lux * 2; j++){
            for(int k = rdy * 2; k <= luy * 2; k++){
                board[j][k] = 1;
            }
        }
    }
    
    for(int i = 0; i < rectangle.size(); i++){
        int rdx = rectangle[i][0];
        int rdy = rectangle[i][1];
        int lux = rectangle[i][2];
        int luy = rectangle[i][3];
        
        for(int j = rdx * 2 + 1; j <= lux * 2 - 1; j++){
            for(int k = rdy * 2 + 1; k <= luy * 2 - 1; k++){
                board[j][k] = 0;
            }
        }
    }
}

void BFS(int st_x, int st_y, int en_x, int en_y){
    queue<pair<int, int>> q;
    
    q.push({st_x, st_y});
    
    for(int i = 0; i <= 100; i++){
        fill(dist[i], dist[i] + 101, -1);
    }
    dist[st_x][st_y] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
                
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(board[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    draw_line(rectangle);
    
    BFS(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return (dist[itemX * 2][itemY * 2] / 2);
}