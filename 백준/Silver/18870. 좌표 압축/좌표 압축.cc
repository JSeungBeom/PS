#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll x[1000003];
ll x2[1000003];
vector<ll> a;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x2[i] = x[i];
    }

    sort(x, x + n);

    int val = x[0];
    a.push_back(val);

    for (int i = 1; i < n; i++) {
        if (x[i] != val) {
            val = x[i];
            a.push_back(val);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << upper_bound(a.begin(), a.end(), x2[i]) - a.begin() - 1<< " ";
    }
}
