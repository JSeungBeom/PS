#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;

vector<int> v;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;    
    
    for(int i = 0; i < (int)dungeons.size(); i++){
        v.push_back(i);
    }
    
    do{
        int cnt = 0;
        int tmp = k;
        
        for(int i = 0; i < (int)dungeons.size(); i++){
            if(tmp >= dungeons[v[i]][0]){
                tmp -= dungeons[v[i]][1]; cnt++;
            }
        }    
        
        answer = max(answer, cnt);
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}