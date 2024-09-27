#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int xnum[10];
int ynum[10];

string solution(string X, string Y) {
    string answer = "";
    
    for(int i = 0; i < X.length(); i++){
        xnum[X[i] - '0']++;
    }  
    
    for(int i = 0; i < Y.length(); i++){
        ynum[Y[i] - '0']++;
    }
    
    for(int i = 9; i >= 0; i--){
        if(i == 0 && xnum[i] && ynum[i] && answer == ""){
            answer = "0";
            break;
        }
        
        if(xnum[i] && ynum[i]){
            int mn = min(xnum[i], ynum[i]);
            
            for(int j = 0; j < mn; j++){
                answer += i + '0';
            }
        }
        
    }
    
    if(answer == "")
        answer = "-1";
    
    return answer;
}