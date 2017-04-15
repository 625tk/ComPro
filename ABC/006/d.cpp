#include<iostream>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0; i < n; ++i)

using namespace std;

vector<int> c;

int LIS(){
  int dp[c.size()];
  fill(dp, dp+c.size(), 1000000000);
  rep(i,c.size()){
    *lower_bound(dp, dp+c.size(), c[i]) = c[i];
  }
  return lower_bound(dp, dp+c.size(), 1000000000) - dp;
}

int main(void){
  int n;
  cin >> n;
  c.resize(n);
  for(auto &x: c) cin >> x;
  cout << n-LIS() << endl;
  return 0;
}
