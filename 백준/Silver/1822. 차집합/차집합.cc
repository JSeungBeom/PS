#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int na, nb, elem;
vector<ll> A, B;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> na >> nb;

    for (int i = 0; i < na; i++) {
        cin >> elem;
        A.push_back(elem);
    }

    for (int i = 0; i < nb; i++) {
        cin >> elem;
        B.push_back(elem);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> ans;
    int cnt = 0;

    for (int i = 0; i < na; i++) {
        if (!binary_search(B.begin(), B.end(), A[i])) {
            ans.push_back(A[i]);
            cnt++;
        }
    }

    cout << cnt << "\n";
    for (ll num : ans) {
        cout << num << " ";
    }
}
