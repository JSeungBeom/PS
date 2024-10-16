#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#define X first
#define Y second

using namespace std;

queue<pair<int, int>> q;
int board[505][505];
bool vis[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
unordered_map<int, int> um;

void BFS(){
    int idx = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || board[i][j] == 0) continue;
            
            int cnt = 0;
            vis[i][j] = 1;
            q.push({i, j});
            
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                board[cur.X][cur.Y] = idx;
                cnt++;
                
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] == 0) continue;
                    
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            
            um[idx++] = cnt;
        }
    }
}

int extract(int col){
    bool vis[300000] = {0};
    
    int amount = 0;
    
    for(int i = 0; i < n; i++){
       if(vis[board[i][col]]) continue;
        
        amount += um[board[i][col]];
        vis[board[i][col]] = 1;
    }
            
    return amount;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = (int)land.size();
    m = (int)land[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] = land[i][j];
        }
    }
    
    BFS();
    
    for(int i = 0; i < m; i++){
        answer = max(answer, extract(i));
    }
    
    
    return answer;
}