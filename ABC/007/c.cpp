#include<iostream>
#include<queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define reps(i,f,n) for(int i = f; i < n; ++i)

using namespace std;

class S{
  public:
  int y,x,c;
  S(int a, int b, int d): y(a), x(b), c(d){};
};

int cell[64][64];
int used[64][64];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(void){
  int R, C;
  int sy, sx, gy, gx;
  string r[64];
  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;
  rep(i,R) cin >> r[i];
  rep(i,64)rep(j,64)used[i][j] = -1;
  rep(i,64)rep(j,64)cell[i][j] = -1;

  reps(i,1,R)reps(j,1,C)
    cell[i][j] = r[i-1][j-1] =='#';
  
  queue<S> q;

  q.push(S(sy, sx, 0));
  while(!q.empty()){
    int y = q.front().y;
    int x = q.front().x;
    int c = q.front().c;
    q.pop();
    rep(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(used[ny][nx] != -1 || cell[ny][nx] != 0) continue;
      used[ny][nx] = c+1;
      q.push(S(ny, nx, c+1));
    }
  }
  cout << used[gy][gx] << endl;
  return 0;
}
