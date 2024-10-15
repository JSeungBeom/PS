#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int candidates[10];

int select_max(vector<string> expressions){
    int mx = 0;
    for(int i = 0; i < (int)expressions.size(); i++){
        for(int j = 0; j < expressions[i].length(); j++){
            if(1 <= expressions[i][j] - '0' && expressions[i][j] - '0' <= 9){
                mx = max(mx, expressions[i][j] - '0');
            }
        }
    }
    
    return mx + 1;
}

int transform(int num, int method){
    int mul = 1;
    int ret = 0;
    
    while(num != 0){
        ret += (num % 10) * mul;
        num /= 10;
        mul *= method;
    }
    
    return ret;
}

int transform_rev(int num, int method){
    int div = method * method;
    string ret = "";
    
    if(num == 0)
        return 0;
    
    while(div > num){
        div /= method;
    }
    

    
    while(div != 0){
        if(num == 0){
            ret.push_back('0');
        }
        else {
            ret.push_back(((char)((num / div) + '0')));
            num %= div;
        }
        div /= method;
    }
    
    
    return stoi(ret);
}

void reduce_candidates(string expr, int mx){
    string tmp = ""; 
    char op;
    vector<int> v;
    
    for(int i = 0; i < expr.length(); i++){
        if(0 <= expr[i] - '0' && expr[i] - '0' <= 9){
            tmp += expr[i];
        }
        else if(expr[i] == '+'){
            op = '+';
        }
        else if(expr[i] == '-'){
            op = '-';
        }
        else{
            if(!tmp.empty()){
                v.push_back(stoi(tmp));
            }
            tmp = "";
        }
        
    }
    
    v.push_back(stoi(tmp));

    for(int i = mx; i <= 9; i++){
        int a = transform(v[0], i);
        int b = transform(v[1], i);
        int result = transform(v[2], i);
                    
        if(op == '+'){
            if(a + b != result){
                candidates[i] = 0;
            }
        }
        else{
            if(a - b != result){
                candidates[i] = 0;
            }
        }
    }
}

string calc(string expr, int mx){
    string tmp = ""; 
    char op;
    vector<int> v;
    
    for(int i = 0; i < expr.length(); i++){
        if(0 <= expr[i] - '0' && expr[i] - '0' <= 9){
            tmp += expr[i];
        }
        else if(expr[i] == '+'){
            op = '+';
        }
        else if(expr[i] == '-'){
            op = '-';
        }
        else{
            if(!tmp.empty()){
                v.push_back(stoi(tmp));
            }
            tmp = "";
        }
    }
    
    unordered_set<int> us;
    
    for(int i = mx; i <= 9; i++){
        if(candidates[i] == 0) continue;
        
        int a = transform(v[0], i);
        int b = transform(v[1], i);
        int result = 0;
        
        if(op == '+'){
            result = a + b;
        }
        else{
            result = a - b;
        }
        
        result = transform_rev(result, i);
        
        cout << a << ' ' << b << ' ' << result << '\n';
        
        us.insert(result);
    }
    
    expr.pop_back();
    
    if((int)us.size() == 1){
        for(auto e : us){
            expr.append(to_string(e));
        }                    
    }
    else{
        expr += '?';
    }
    
    return expr;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    int mx = select_max(expressions);
    for(int i = mx; i <= 9; i++){
        candidates[i] = 1;
    }
    
    for(int i = 0; i < (int)expressions.size(); i++){
        if(expressions[i][expressions[i].length() - 1] != 'X'){
            reduce_candidates(expressions[i], mx);
        } 
    }
    
    for(int i = 0; i < (int)expressions.size(); i++){
        if(expressions[i][expressions[i].length() - 1] == 'X'){
            answer.push_back(calc(expressions[i], mx));
        } 
    }
    
    
    return answer;
}