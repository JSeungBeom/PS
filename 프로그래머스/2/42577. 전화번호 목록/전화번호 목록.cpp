#include <bits/stdc++.h>

using namespace std;

unordered_set<string> us;

bool solution(vector<string> phone_book) {
    for(int i = 0; i < (int)phone_book.size(); i++){
        us.insert(phone_book[i]);
    }
    
    for(int i =0 ; i < (int)phone_book.size(); i++){
        string tmp = "";
        for(int j = 0; j < phone_book[i].length(); j++){
            tmp += phone_book[i][j];
            if(us.find(tmp) != us.end() && tmp != phone_book[i]){
                return 0;
            }
        }
    }
    
    return 1;
}