#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007 
int m, n, s;

long long convert(long long x, long long y) {
    if (y == 1) return x;

    if (y % 2 == 1) return (x * convert(x, y - 1)) % MOD;

    long long val = convert(x, y / 2);
    return (val * val) % MOD;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;

    long long ans = 0;
    while (m--) {
        cin >> n >> s;
        long long val = (s * convert(n, MOD - 2)) % MOD;
        ans += (val % MOD);
    }
    cout << ans % MOD;
}