#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
queue<pair<int, int>> q;
int dist[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int solution(vector<vector<int>> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();
    
    for(int i = 0; i < n; i++){
        fill(dist[i], dist[i] + m, -1);
    }
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || maps[nx][ny] == 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    
    
    return dist[n - 1][m - 1];
}