#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i= 0; i < n; ++i)
using namespace std;

int main(void){
  int n, t;
  vector<int> tn;
  int ans = 0;
  int begin = -1;

  cin >> n >> t;
  tn.resize(n);
  for(auto& x: tn) cin >> x;

  begin = tn[0];
  for(int i = 1; i < n; ++i){
    if(begin + t > tn[i]){
      ans += tn[i] - begin;
    }else{
      ans += t;
    }
    begin = tn[i];
  }
  ans += t;


  cout << ans << endl;
  
  return 0;
}
