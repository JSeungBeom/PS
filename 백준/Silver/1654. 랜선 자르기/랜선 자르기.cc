#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int k, n;
int lan[10003];

bool solve(ll x) {
    ll cur = 0;
    for (int i = 0; i < k; i++) {
        cur += lan[i] / x;
    }

    return cur >= n;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
    }

    ll st = 1;
    ll en = 0x7fffffff; // 2^31 - 1

    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;
}
