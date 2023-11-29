#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> failure_func(string& p) {
    vector<int> len(p.length());
    for (int i = 1, j = 0; i < p.length(); i++) {
        while (j > 0 && p[i] != p[j]) j = len[j - 1];
        if (p[i] == p[j]) len[i] = ++j;
    }
    return len;
}

int n;

int main() {
    int t;

    cin >> n;

    string s;
    cin >> s;

    vector<int> len = failure_func(s);
    int L = s.length();
    cout << L - len[L - 1];

}