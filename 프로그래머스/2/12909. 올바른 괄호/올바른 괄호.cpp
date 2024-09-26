#include<string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

bool solution(string s)
{
    bool answer = true;
    bool flag = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            st.push('(');
        else{
            if(st.empty()){
                flag = 1;
                break;
            }
            else
                st.pop();
        }
    }
    
    if(st.empty() && !flag)
        answer = 1;
    else
        answer = 0;
    return answer;
}