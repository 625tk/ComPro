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


int main(void){
  string s;
  cin >> s;
  int x=0;
  int ans = 0;
  rep(i,s.sz){
    if(s[i] =='S') x++;
    else{
      if(x > 0){ans++;x--;}
    }
  }
  cout << s.size() - ans*2 << endl;
  return 0;
}
