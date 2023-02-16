#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int U[1003];
vector<ll> two;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> U[i];
    }

    sort(U, U + n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            two.push_back(U[i] + U[j]);
        }
    }

    sort(two.begin(), two.end());

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(two.begin(), two.end(), U[i] - U[j])) {
                cout << U[i];
                return 0;
            }
        }
    }
}

// two[i] + U[k] = U[l] -> U[l] - U[k] = two[i];
