#include <string>
#include <vector>

using namespace std;

int cnt;

class Time{
public:
    int h, m, s;
    
    Time(int sec){
        this->h = sec / 3600;
        this->m = (sec % 3600) / 60;
        this->s = (sec % 3600) % 60;
    }
    
    vector<double> getDegree(){
        double hdegree = (h % 12) * 30 + m * 0.5 + s * (1 / 120);
        double mdegree = 6 * m + 0.1 * s;
        double sdegree = 6 * s;
        
        return vector<double>{hdegree, mdegree, sdegree};
    }
};

int to_seconds(int h, int m, int s){
    int sec = 0;
    
    sec += h * 3600;
    sec += m * 60;
    sec += s;
    
    return sec;
}

bool hour_match(vector<double> cur, vector<double> nxt){
    if(cur[0] > cur[2] && nxt[0] <= nxt[2]) // 현재 시침 > 초침, 다음 시침 <= 초침
        return true;
    
    if(cur[2] == 354 && cur[0] > 354)
        return true;
    
    return false;
}

bool min_match(vector<double> cur, vector<double> nxt){
    if(cur[1] > cur[2] && nxt[1] <= nxt[2]) // 현재 분침 > 초침, 다음 분침 <= 초침
        return true;
    
    if(cur[2] == 354 && cur[1] > 354)
        return true;
    
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int st = to_seconds(h1, m1, s1);
    int en = to_seconds(h2, m2, s2);
    
    for(int i = st; i < en; i++){
        vector<double> cur = Time(i).getDegree();
        vector<double> nxt = Time(i + 1).getDegree();
        
        bool hflag = hour_match(cur, nxt);
        bool mflag = min_match(cur, nxt);
        
        if(hflag && mflag){
            if(nxt[0] == nxt[1]) answer++;
            else answer += 2;
        }
        else if(hflag || mflag) answer++;
    }
    
    if(st == 0 || st == 43200) answer++;    
    
    return answer;
}