#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define X second
#define Y first

using namespace std;

int cell[64][64];
int cell_d[64][64];
int H,W,K,N, sy, sx;

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
string dd = "RDUL";

class A{
  public:
    int p;
    string s;
    int t;
    int x;
    int y;
    A(int a, string ss, int xx, int yy, int pp):p(pp),s(ss),t(a),x(xx),y(yy){};
};


string search(){
  int t = 0;
  string ans = "";
  int nx = sx;
  int ny = sy;

  while(t < K){
      vector<A> cands;
      int used[64][64]={0};
      used[ny][nx] = 1;
      rep(i,4){
        if(cell[dy[i] + ny][dx[i] + nx] == -1)continue;
        A a(t, "", dx[i]+nx, dy[i]+ny, 0);
        a.s+= dd[i];
        a.p += cell[a.y][a.x] - a.t*cell_d[a.y][a.x];
        a.t++;
        used[a.y][a.x] = 1;
        cands.push_back(a);
      }
      int ind = 0;
      int indd = cands.size();
      rep(loop,40){
        rep(j,indd-ind){
          A b=cands[ind+j];
          rep(i,4){
            if(cell[dy[i] + b.y][dx[i] + b.x] == -1)continue;
            if(used[dy[i] + b.y][dx[i] + b.x] == 1)continue;

            A a(b.t, b.s, dx[i]+b.x, dy[i]+b.y, b.p);
            a.s += dd[i];
            a.p += cell[a.y][a.x] - a.t*cell_d[a.y][a.x];
            a.t++;
            used[a.y][a.x] = 1;
            cands.push_back(a);
          }
        }
        ind = indd;
        indd = cands.size();
      }

      ind = -1;
      int mxp = -100;
      rep(i,indd){
        if(mxp < cands[i].p){
          ind = i;
          mxp = cands[i].p;
        }
      }
      if(mxp > 0){
        //cout << "points: " << mxp << endl;;
        //cout << "str: " << cands[ind].s << endl;
        t = cands[ind].t;
        ans += cands[ind].s;
        rep(j, cands[ind].s.size()){
          char x = cands[ind].s[j];
          if(x == 'U'){
            ny--;
          }else if(x == 'D'){
            ny++;
          }else if(x == 'L'){
            nx--;
          }else if(x =='R'){
            nx++;
          }
          cell[ny][nx] = 0;
          cell_d[ny][nx] = 0;
        }
      }else{
        break;
      }
  }
  return ans;
}

int main(void){
  string temp_s;
  int x,y,f,d;
  cin >> H >> W >> K >> sy >> sx;
  rep(i,H){
    cin >> temp_s;
    rep(j, W){
      if(temp_s[j] == '#'){
        cell[i+1][j+1] = -1;
      }
    }
  }
  rep(i,52){
    cell[0][i] = -1;
    cell[51][i] = -1;
    cell[i][0] = -1;
    cell[i][51] = -1;
  }

  H+=2;W+=2;
  cin >> N;
  rep(i,N){
    cin >> y >> x >> f >> d;
    cell[y][x] = f;
    cell_d[y][x] = d;
  }

  string ans = search();
  for(int i = K-ans.size(); i > 0; i--){
    ans += "-";
  }
  cout << ans << endl;

  return 0;
}

