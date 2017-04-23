#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;

using namespace std;

int main(void){
  int n;
  vector<ll> a;
  vector<ll> s;

  cin >> n;
  a.resize(n);
  s.resize(n);
  for(ll &ai : a) cin >> ai;

  s[0] = a[0];
  for(int i = 1; i < a.size(); ++i){
    s[i] = s[i-1] + a[i];
  }

  bool x; //trueが正
  ll dif;
  ll tmp;
  ll ans = 0;

  x = true;
  dif = 0;
  ans = 0;
  for(int i = 0; i < n; i++){
    if(x && s[i]+dif >= 0){
      tmp += s[i]+dif+1;
      dif += -(s[i]+dif+1);
    }else if( !x && s[i]+dif <= 0){
      tmp += -(s[i]+dif-1);
      dif += -(s[i]+dif-1);
    }
    //cout << s[i]+dif << "   tmp : " << tmp << "  dif " << dif << endl;
    x = !x;
  }
  ans = tmp;

  x = false;
  dif = 0;
  tmp = 0;
  for(int i = 0; i < n; i++){
    if(x && s[i]+dif >= 0){
      tmp += s[i]+dif+1;
      dif += -(s[i]+dif+1);
    }else if( !x && s[i]+dif <= 0){
      tmp += -(s[i]+dif-1);
      dif += -(s[i]+dif-1);
    }
   // cout << s[i]+dif << "   tmp : " << tmp << "  dif " << dif << endl;
    x = !x;
  }
  ans = min(ans, tmp);

  cout << ans << endl;
  return 0;
}
