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

vector<pii> p[2][200000];

int u[2][200000];
int m[2];
const int INF=1000000000;

bool dfs(int now, int to, int pos){
  bool ret = true;
  //cout << now << " : " << to << " : " << pos << endl;
  m[pos] = min(m[pos], now);
  rep(i, p[pos][to].sz){
    int next = p[pos][to][i].X;
    int val = p[pos][to][i].Y;
    //cout << "next: " << next << "  val: " << val << "  u[" << 1-pos << "][" << next << "]: " << u[1-pos][next] << endl;

    if(u[1-pos][next] == INF){
      u[1-pos][next] = val-now;
      m[1-pos] = min(m[1-pos], u[1-pos][next]);
      if(m[0]+m[1] < 0)return false;
      ret &= dfs(u[1-pos][next], next, 1-pos);
    }else if(u[1-pos][next] != val-now){
      return false;
    }
  }
  //cout << "---" << endl;
  return ret;
}


int main(void){
  int r,c,n;
  int x,y,a;
  cin >> r >> c;
  cin >> n;
  rep(i,n){
    cin >> x >> y >> a;
    x--;y--;
    p[0][x].pb(make_pair(y,a));
    p[1][y].pb(make_pair(x,a));
  }
  
  rep(i, r)u[0][i] = INF;
  rep(i, c)u[1][i] = INF;

  bool ret = true;

  rep(i,r){
    if(u[0][i] == INF){
      u[0][i] = 0;
      m[0] = 0;m[1] = INF;
      ret &= dfs(0, i, 0);
    }
  }

  if(ret) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;

}
