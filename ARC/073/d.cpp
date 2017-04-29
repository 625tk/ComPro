#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i= 0; i < n; ++i)
#define X first
#define Y second
#define all(x) x.begin(), x.end()
using namespace std;

long long dp[4][128];
int main(void){
  long long N,W;
  vector< pair<long long,long long> > wv;
  cin >> N >> W;
  wv.resize(N);
  vector<long long> v[4];

  for(auto& x: wv)cin >> x.X >> x.Y;
  long long base = wv[0].X;

  rep(i,wv.size()){
    v[wv[i].X-base].push_back(wv[i].Y);
  }

  rep(i,4){
    rep(j, v[i].size()){
      for(int k = 100; k >= 0; k--){
        dp[i][k+1] = max(dp[i][k+1], dp[i][k] + v[i][j]);
      }
    }
  }

  long long ans = 0;
  rep(i,v[0].size()+1)rep(j,v[1].size()+1)rep(k,v[2].size()+1)rep(l,v[3].size()+1){
    if( base*(i) + (base+1)*(j) + (base+2)*(k) + (base+3)*(l) <= W){
      //cout << i << " " << j << " " << k << " " << l << " " << endl;
      //cout << dp[0][i] << " " << dp[1][j] << " " << dp[2][k] << " " << dp[3][l] << " " << endl;
      ans = max(ans, dp[0][i] + dp[1][j] + dp[2][k] + dp[3][l]);
    }
  }

  cout << ans << endl;





  return 0;
}
