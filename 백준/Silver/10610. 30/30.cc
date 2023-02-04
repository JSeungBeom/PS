#include <bits/stdc++.h>
using namespace std;

string N;
vector<int> nums;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (char c : N)
    nums.push_back(c - '0');

  sort(nums.begin(), nums.end(), greater<int>());
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 3 == 0 && nums.back() == 0)
    for (int n : nums) cout << n;
  else
    cout << -1;
}