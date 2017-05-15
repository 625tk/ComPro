#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>

#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define rep(i,n) for(ll i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll INF = 1000000000000000000LL;

vector<PII> edges[2000];
vector<PII> e[2000];
int n,m;

vector<ll> dist;

bool bellman_ford(){
  dist = vector<ll>(n,INF);

  dist[0] = 0;
  rep(i,n){
    rep(v,n){
      rep(k, edges[v].size()){
        PLL pi = edges[v][k];
        if( dist[v] != INF && dist[pi.X] > dist[v] + pi.Y){
          dist[pi.X] = dist[v] + pi.Y;
          if(i == n-1){
            dist[n-1] = INF;
            return true;
          }
        }
      }
    }
  }
  return false;
}

void f(){
  queue<int> q;
  q.push(n-1);
  bool r[2000];
  rep(i,2000) r[i] = false;
  while(!q.empty()){
    int pos = q.front();q.pop();
    r[pos] = true;
    rep(j,e[pos].size()){
      PII pi = e[pos][j];
      if(r[pi.X])continue;
      q.push(pi.X);
    }
  }

  rep(i,n){
    rep(j,e[i].size()){
      PII pi = e[i][j];
      if(r[i] && r[pi.X]){
        edges[pi.X].eb(i, pi.Y);
//         cout << pi.X << " -> " << i << endl;
      }
    }
  }
}




int main(void){
  ll a,b,c;

  cin >> n >> m;
  rep(i,m){
    cin >> a >> b >> c;
    a--;b--;
    c *= -1;
     e[b].eb(a,c);
  }

  f();
  bellman_ford();
  if(dist[n-1] == INF){
    cout << "inf" << endl;
  }else{
    cout << -1*dist[n-1] << endl;
  }

  return 0;
}
