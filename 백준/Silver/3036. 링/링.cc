#include <bits/stdc++.h>
using namespace std;

int n;
int ring[103];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ring[i];
    }
    
    for (int i = 1; i < n; i++) {
        int div = gcd(ring[0], ring[i]);
        cout << ring[0] / div << "/" << ring[i] / div << "\n";
    }
}
