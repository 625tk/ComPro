#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;

#define reps(i,f,n) for(int i = int(f); i <= int(n); i++)
#define rep(i,n) reps(i,0,int(n)-1)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)

#define all(x) (x).begin(),(x).end()
#define X first
#define Y second

#define sz size()
#define eb emplace_back
#define pb push_back

vector<int> p;
vector<int> q;

int main(void){
  int w,h;
  int t;
  ll ans = 0;
  cin >> w >> h;
  rep(i,w){
    cin >> t;
    p.push_back(t);
  }
  rep(i,h){
    cin >> t;
    q.push_back(t);
  }
  sort(all(p));
  sort(all(q));
  vector<int>::iterator it;
  ll pos;
  w++;h++;
  rep(i,p.size()){
    it = upper_bound(all(q), p[i]);
    pos = it - q.begin();
    it = lower_bound(all(q), p[i]);
    if(*it == p[i]){
      //cout << p[i] << endl;
      pos = it - q.begin();
    }
    ans += (h-pos)*p[i];
    //cout << p[i] << ":" << h-pos << endl;
  }
  rep(i,q.size()){
    it = upper_bound(all(p), q[i]);
    pos = it - p.begin();
    ans += (w-pos)*q[i];
    //cout << q[i] << "::" << w-pos << endl;
  }
  cout << ans << endl;
  return 0;
}
