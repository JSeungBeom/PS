#include <bits/stdc++.h>
using namespace std;

int ans[102]; 
bool isopen[102];

void open(int n) {
  for(int i = 1; i * n <= 100; i++)
    isopen[i * n] = !isopen[i * n];

  for(int i = 1; i <= n; i++)
    if(isopen[i]) ans[n]++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // for n = 1
  fill(isopen, isopen + 101, 1);

  for(int i = 2; i <= 100; i++)
    open(i);
  
  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    cout << ans[x] << '\n';
  }
}