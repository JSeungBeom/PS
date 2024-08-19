#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 10 + 5;
int nxt[MX][10];
int chk[MX];

int i2i(int c) {
    return c - '0';
}

bool insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][i2i(c)] == -1)
            nxt[cur][i2i(c)] = unused++;

        cur = nxt[cur][i2i(c)];
        if (chk[cur]) return 0;
    }

    if (cur != unused - 1) return 0;

    chk[cur] = true;
    return 1;
}


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;

    cin >> t;

    int n;

    while (t--) {
        cin >> n;

        bool flag = 0;

        for (int i = 0; i < MX; i++) {
            fill(nxt[i], nxt[i] + 10, -1);
        }

        fill(chk, chk + MX, 0);

        unused = 2;

        string s;
        while(n--){
            cin >> s;
            if (!insert(s)) {
                flag = 1;
            }
        }

        if (!flag)
            cout << "YES\n";
        else
            cout << "NO\n";

    }

}