#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int n = (int)sequence.size();
    
    int en = 0;
    int sum = 0;
    int mn = 0x7fffffff;
    int st_idx = 0;
    int en_idx = 0;
    
    for(int st = 0; st < n; st++){
        while(en < n && sum < k){
            sum += sequence[en]; 
            en++;
            
            if(en >= n)
                break;
        }
        
        if(sum == k){
            if(mn > en - st + 1){
                mn = en - st + 1;
                st_idx = st;
                en_idx = en - 1;
            }
        }
        
        sum -= sequence[st];
    }
    
    answer.push_back(st_idx);
    answer.push_back(en_idx);
    
    return answer;
}