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

vector<int> cxx[200000];
vector<pii> cx[200000];

int search(int x, int y){
  int ret;
  vector<int>::iterator pos;
  pos = lower_bound(all(cxx[x]), y);
  ret = cx[x][pos-cxx[x].begin()].Y;
  return ret;
}

int main(void){
  int r,c,n;
  int x,y,a;
  cin >> r >> c;
  cin >> n;
  rep(i,n){
    cin >> x >> y >> a;
    cx[x].pb(make_pair(y,a));
    cxx[x].pb(y);
  }
  rep(i,n){
    sort(all(cx[i]));
    sort(all(cxx[i]));
  }
  bool ok = true;
  int mx = max(r,c);
  rep(i,c+1){
    if(cx[i].sz > 0){
      rep(j, cx[i].sz){
        x = i;
        y = cx[i][j].X;
        int lu = cx[i][j].Y;
        reps(k, 1, mx){
          int rd = -1, ru = -1, ld = -1;
          int fd = 0;
          if( y+k > r || i+k > c) break;
          if(binary_search(all(cxx[i+k]), y+k)){
            rd = search(i+k, y+k);
            fd++;
          }
          if(binary_search(all(cxx[i]), y+k)){
            ld = search(i, y+k);
            fd++;
          }
          if(binary_search(all(cxx[i+k]), y)){
            ru = search(i+k, y);
            fd++;
          }
          if(fd == 3){
            if( rd + lu != ru + ld ) ok = false;
          }else if(fd == 2){
            if(rd == -1){
              rd = ru + ld - lu;
              if(rd < 0) ok = false;
              else{
                cx[i+k].pb(make_pair(y+k, rd));
                cxx[i+k].pb(y+k);
                sort(all(cx[i+k]));
                sort(all(cxx[i+k]));
              }
            }else if(ru == -1){
              ru = lu + rd - ld;
              if(ru < 0)ok = false;
              else{
                cx[i+k].pb(make_pair(y, ru));
                cxx[i+k].pb(y);
                sort(all(cx[i+k]));
                sort(all(cxx[i+k]));
              }
            }else if(ld == -1){
              ld = lu + rd - ru;
              if(ld < 0)ok = false;
              else{
                cx[i].pb(make_pair(y+k, ld));
                cxx[i].pb(y+k);
                sort(all(cx[i]));
                sort(all(cxx[i]));
              }
            }
          }
        }
      }
    }
    if(!ok)break;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;


  /*
  rep(i,n){
    if(cx[i].sz > 0){
      rep(j,cx[i].sz){
        cout << i << "," <<  cx[i][j].X << " : " << cx[i][j].Y << endl;
      }
    }
  }
  rep(i,n){
    if(cy[i].sz > 0){
      rep(j,cy[i].sz){
        cout << cy[i][j].X << "," <<  i << " : " << cy[i][j].Y << endl;
      }
    }
  }
  */
  return 0;

}
