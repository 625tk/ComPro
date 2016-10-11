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

int a[200000];

int main(void){
  int n;
  cin >> n;
  rep(i,n){
    cin >> a[i];
  }
  ll ans = 0;
  int mh = 2;
  rep(i,n){
    if(i == 0){
      ans += a[i]-1;
    }else{
      if(a[i] == mh){
        mh++;
      }else{
        if(a[i]%mh == 0)ans--;
        ans+=a[i]/mh;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
