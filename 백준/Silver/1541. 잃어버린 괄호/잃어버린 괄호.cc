#include <bits/stdc++.h>
using namespace std;

string s;
int sign = 1;
int tmp, ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    s.append("+");
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            ans += tmp * sign;
            if (s[i] == '-')
                sign = -1;
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += s[i] - '0';
        }
    }
        
    cout << ans;
}
