#include <string>
#include <vector>
#include <cmath>
#define X first
#define Y second

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    int N = (int)balls.size();    
    // 선대칭 길이 활용
    for(int i = 0; i < N; i++){
        int mn = 0x7fffffff;
        
        pair<int, int> spot1 = {-startX, startY};
        pair<int, int> spot2 = {startX, -startY};
        pair<int, int> spot3 = {m + (m - startX), startY};
        pair<int, int> spot4 = {startX, n + (n - startY)};
        
        if(startY != balls[i][1] || startX < balls[i][0])
            mn = min(mn, (abs(spot1.X - balls[i][0]) * abs(spot1.X - balls[i][0]) + 
            abs(spot1.Y - balls[i][1]) * abs(spot1.Y - balls[i][1])));
            
        if(startX != balls[i][0] || startY < balls[i][1])
            mn = min(mn, (abs(spot2.X - balls[i][0]) * abs(spot2.X - balls[i][0]) + 
                abs(spot2.Y - balls[i][1]) * abs(spot2.Y - balls[i][1])));
        
        if(startY != balls[i][1] || startX > balls[i][0])
            mn = min(mn, (abs(spot3.X - balls[i][0]) * abs(spot3.X - balls[i][0]) + 
                abs(spot3.Y - balls[i][1]) * abs(spot3.Y - balls[i][1])));
            
        if(startX != balls[i][0] || startY > balls[i][1])
            mn = min(mn, (abs(spot4.X - balls[i][0]) * abs(spot4.X - balls[i][0]) + 
                abs(spot4.Y - balls[i][1]) * abs(spot4.Y - balls[i][1])));

        answer.push_back(mn);
    }
    
    return answer;
}