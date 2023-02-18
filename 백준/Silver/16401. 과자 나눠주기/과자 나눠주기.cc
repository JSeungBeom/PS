#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[1000003];

bool solve(int len) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] / len;
    }
    return ans >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int st = 1;
    int en = 1000000000;

    while (st < en) {
        int mid = (st + en + 1) / 2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }

    if (!solve(st)) {
        cout << 0;
        return 0;
    }

    cout << st;
}
