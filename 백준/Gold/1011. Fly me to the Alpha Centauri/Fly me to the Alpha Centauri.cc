#include <bits/stdc++.h>
using namespace std;

long long solve(long long k) {
    return floor(2 * sqrt(k) - 1e-9);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    long long x, y;

    while (t--) {
        cin >> x >> y;
        cout << solve(y - x) << '\n';
    }
}