#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define X second
#define Y first

using namespace std;

int orig_cell[64][64];
int H,W,K;

class Answer{
  public:
  int point;
  vector<pair<int,int>> cells;
  void print(){
    rep(i,cells.size()){
      cout << cells[i].Y << " " << cells[i].X << endl;
    }
  }
};

class Candidate{
  public:
  int point;
  pair<int,int> cell;
};
vector<Answer> answer;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
bool operator< (const Candidate& c1, const Candidate& c2){
  return c1.point < c2.point;
}

void search(){
  int cp_cell[64][64] = {0};
  rep(i,H)rep(j,W) cp_cell[i][j] = orig_cell[i][j];

  for(int number = 9; number > 0; number--){
    rep(i,H)rep(j,W){
      if(cp_cell[i][j] == number){
        Answer x;
        priority_queue<Candidate, vector<Candidate>> cands;
        int cs = K-1;
        cp_cell[i][j] = -cp_cell[i][j];

        x.point = number;
        x.cells.push_back(make_pair(i,j));
        rep(k,4){
          Candidate c;
          c.point = cp_cell[i+dy[k]][j+dx[k]];
          c.cell = make_pair(i+dy[k], j+dx[k]);
          cands.push(c);
        }
        while(cs>0 && !cands.empty()){
          Candidate c = cands.top();cands.pop();
          if(cp_cell[c.cell.Y][c.cell.X] <= 0)continue;
          x.cells.push_back(make_pair(c.cell.Y, c.cell.X));
          cp_cell[c.cell.Y][c.cell.X] = -cp_cell[c.cell.Y][c.cell.X];
          //cout << cp_cell[c.cell.Y][c.cell.X] << endl;
          cs--;
          rep(k,4){
            Candidate can;
            can.point = cp_cell[c.cell.Y+dy[k]][c.cell.X+dx[k]];
            can.cell = make_pair(c.cell.Y+dy[k], c.cell.X+dx[k]);
            cands.push(can);
          }
        }
        if(cs == 0){
          answer.push_back(x);
        }else{
          rep(k,x.cells.size()){
            cp_cell[x.cells[k].Y][x.cells[k].X] = -cp_cell[x.cells[k].Y][x.cells[k].X];
          }
        }
      }
    }
  }
}

int main(void){
  string temp_s;
  cin >> H >> W >> K;
  rep(i,H){
    cin >> temp_s;
    rep(j, W){
      orig_cell[i+1][j+1] = temp_s[j] - '0';
    }
  }
  H++;W++;

  search();

  cout << answer.size() << endl;
  rep(i,answer.size()){
    answer[i].print();
  }
  return 0;
}

