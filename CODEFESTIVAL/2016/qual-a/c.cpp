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

vector<int> a[26];

int main(void){
  string s;
  int k;
  cin >> s;
  cin >> k;
  rep(i,s.sz){
    //cout << (26-(s[i]-'a')) << endl;

    if(s[i] != 'a' && k >= (26-(s[i]-'a'))){
      k = k - (26-(s[i]-'a'));
      s[i] = 'a';
    }

    //cout << k << " : " << s << endl; 
  }

  if( k > 0){
    s[s.sz-1] = ((s[s.sz-1] - 'a' + k)%26) + 'a';
  }
  cout << s << endl;
  return 0;
}
