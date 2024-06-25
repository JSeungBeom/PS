#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    string tmp = s;
    stack<int> st;

    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == '(')
            st.push(1);
        else {
            if (st.empty())
                return false;
            else
                st.pop();
        }
    }

    if (st.empty())
        answer = true;
    else
        answer = false;

    return answer;
}