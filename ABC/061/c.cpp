#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>

#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

vector<pair<int,int> > x;
int main(void){
  ll n,k;
  ll a,b;
  cin >> n >> k;
  rep(i,n){
    cin >> a >> b;
    x.push_back(make_pair(a,b));
  }
  sort(all(x));
  ll ind = 0;
  rep(i, n){
    ind += x[i].Y;
    if( ind >= k){
      cout << x[i].X << endl;
      return 0;
    }
  }
  return 0;
}
