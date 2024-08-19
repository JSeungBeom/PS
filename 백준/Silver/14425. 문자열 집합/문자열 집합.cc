#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];
int nxt[MX][26];

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }

    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }

    return chk[cur];
}

void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return;
        cur = nxt[cur][c2i(c)];
    }

    chk[cur] = false;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;

    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    cin >> n >> m;

    string s;

    while (n--) {
        cin >> s;

        insert(s);
    }

    int cnt = 0;

    while (m--) {
        cin >> s;

        if (find(s)) cnt++;
    }

    cout << cnt;
}