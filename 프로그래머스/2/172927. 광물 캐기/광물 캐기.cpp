#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<tuple<int, int, int>> cost; // 돌, 철, 다이아몬드 순 저장

// picks : [dia, iron, stone]
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int tot;
    int tot_picks = (picks[0] + picks[1] + picks[2]) * 5;
        
    if((int)minerals.size() % 5) // 5로 나누어 떨어지지 X 
        tot = (int)minerals.size() / 5 + 1;
    else
        tot = (int)minerals.size() / 5;
    
    
    
    for(int i = 0; i < tot; i++){
        int dia = 0, iron = 0, stone = 0;
        for(int j = i * 5; j < (i * 5) + 5; j++){
            if(j == (int)minerals.size() || j == tot_picks) break;
        
            if(minerals[j] == "diamond"){
                dia += 1;
                iron += 5;
                stone += 25;
            }
            else if(minerals[j] == "iron"){
                dia += 1;
                iron += 1;
                stone += 5;
            }
            else{
                dia += 1;
                iron += 1;
                stone += 1;
            }
        }
                
        cost.push_back({stone, iron, dia});
    }
    
    sort(cost.begin(), cost.end(), greater<>());
    
    for(int i = 0; i < (int)cost.size(); i++){
        int dia, iron, stone;
        tie(stone, iron, dia) = cost[i];
        
        if(picks[0]){
            answer += dia;
            picks[0]--;
        }
        else if(picks[1]){
            answer += iron;
            picks[1]--;
        }
        else{
            answer += stone;
            picks[2]--;
        }
    }
    
    
    return answer;
}