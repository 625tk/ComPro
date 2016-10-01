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

int a[200002];
int b[200002];
pii lr[200002];
long long ans;

const int INF = 1000000000;
int main(void){
  int n;
  int mini = INF;
  rep(i,200002)a[i] = INF;
  cin >> n;
  rep(i,n){
    cin >> a[i+1];
    b[a[i+1]] = i+1;
  }
  pair<int,int> dm;
  dm.X = -1;
  dm.Y = -1;
  rep(i,200002)lr[i] = dm;

  //for(int i = 1; i < n+1; ++i){
  //  ans += b[i] * (n-b[i]);
  for(int i = n; i > 0; --i){
    ll pos = b[i];
    ll l = pos-1;
    ll r = pos+1;

    while(0<l && a[l] >= i) l = lr[l].X;
    while(r<=n && a[r] >= i) r = lr[r].Y;
    lr[pos].X = l;
    lr[pos].Y = r;


    ans += (r - pos) * (pos - l) * i;
  }
  cout << ans << endl;

  return 0;
}
