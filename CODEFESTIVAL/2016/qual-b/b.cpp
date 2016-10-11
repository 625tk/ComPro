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
  int n, a, b;
  string s;
  cin >> n >> a >> b;
  cin >> s;
  int A=0,B=0;
  const string yes = "Yes";
  const string no = "No";
  rep(i,n){
    if(s[i] == 'a'){
      if(A+B<a+b){
        A++;
        cout << yes << endl;
      }
      else cout << no << endl;
    }else if(s[i] == 'b'){
      if(A+B<a+b &&B<b){
        cout << yes << endl;
        B++;
      }
      else cout << no << endl;
    }else{
      cout << no << endl;
    }
  }
  return 0;
}
