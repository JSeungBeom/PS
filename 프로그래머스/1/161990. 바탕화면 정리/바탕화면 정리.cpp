#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int mn_x = 100;
    int mn_y = 100;
    int mx_x = 0;
    int mx_y = 0;
    
    for(int i = 0; i < (int)wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                mn_x = min(mn_x, j);
                mn_y = min(mn_y, i);
                mx_x = max(mx_x, j + 1);
                mx_y = max(mx_y, i + 1);
            }
        }
    }
    
    answer.push_back(mn_y);
    answer.push_back(mn_x);
    answer.push_back(mx_y);
    answer.push_back(mx_x);
    
    return answer;
}