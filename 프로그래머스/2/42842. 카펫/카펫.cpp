#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; i * i <= yellow; i++){
        if(yellow % i != 0) continue;\
            
        int x = yellow / i;
        int y = i;
        
        if((x * 2 + y * 2 + 4) == brown){
            answer.push_back(x + 2);
            answer.push_back(y + 2);
        }
    }
    
    return answer;
}