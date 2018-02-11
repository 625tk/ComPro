#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define X first
#define Y second

using namespace std;
using PII=pair<int,int>;

string cell[128][128];
string bo[128];
int cnt;

priority_queue<PII> q2;

int N, K, H, W, T;
int dx[]= { 1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string mv = "RLDU";;

string ans = "";

bool check(int x, int y){
    if( 0 <= x && x < W && 0 <= y && y < H) return true;
    return false;
}

void solve(pair<int,int> st){
    rep(i, 4){
        if( ans.size() >= T)return;
        int ny = st.Y + dy[i];
        int nx = st.X + dx[i];

        if(bo[ny][nx] == 'o'){
            ans += mv[i];
            bo[ny][nx] = ' ';
            solve(PII(nx, ny));
            if(i == 0){
                ans += "L";
            }else if(i == 1){
                ans += "R";
            }else if(i == 2){
                ans += "U";
            }else{
                ans += "D";
            }
        }
    }
//     cerr << ans << endl;
}

string bor[256];
int sim(int map, string ans){
    pair<int,int> pos;
    rep(i, H){
        bor[i] = cell[map][i];
    }


    rep(i, W){
        rep(j, H){
            if(bor[i][j] == '@'){
                pos.Y = i;
                pos.X = j;
                i = j = 1000;
            }
        }
    }

    int coin = 0;

    rep(i, min((int)ans.size(), T)){
        int m;
        if(ans[i] == 'R'){
            m = 0;
        }else if(ans[i] == 'L'){
            m = 1;
        }else if(ans[i] == 'D'){
            m = 2;
        }else if(ans[i] == 'U'){
            m = 3;
        }
        int nx = pos.X + dx[m];
        int ny = pos.Y + dy[m];

        if(bor[ny][nx] == 'x'){
//             cerr << "ops! " << i << endl;
            break;
        }
        else if(bor[ny][nx] == '#') continue;
        else if(bor[ny][nx] == 'o'){
            coin++;
            bor[ny][nx] = ' ';
        }
        pos.X = nx;
        pos.Y = ny;
    }

//     cerr << map << " :coin: "  << coin << endl;
    return coin;
}



int main(void){
    cin >> N >> K >> H >> W >> T;

    rep(i, N){
        int coin = 0, w = 0;
        rep(j, H){
            cin >> cell[i][j];
        }
        rep(j, H){
            rep(k,W){
                coin += cell[i][j][k] == 'o';
                w += cell[i][j][k] == 'x';
            }
        }
        q2.push(make_pair(-w, i));
    }
    
    vector<int> use;
    rep(i, N){
        PII p = q2.top();q2.pop();
        use.push_back(p.Y);
    }

    srand(15);
    int coins = 0;

    int mx = 0;
    vector<int> f_use;
    string f_ans;

    rep(tr, N){
        ans = "";
        coins = 0;
        priority_queue<PII> q;
//         while(!q.empty()) q.pop();
        vector<int> u;

        int mp = use[tr];
        rep(i, H) bo[i] = cell[mp][i];
        cerr << mp << endl;
        pair<int,int> st;
        rep(i, H){
            rep(j,W){
                if(cell[mp][i][j] == '@'){
                    st.X = j;
                    st.Y = i;
                }
            }
        }
        solve(st);
        if( ans.size() < T){
            rep(i, T-ans.size()){
                ans += mv[rand()%4];
            }
        }

        rep(i, N) q.push(make_pair(sim(i, ans), i));

        rep(i, K){
            PII p = q.top(); q.pop();
            u.push_back(p.Y);
            cerr << p.Y << " -> " << p.X << endl;
            coins+=p.X;
        }

        cerr << ans << endl;
        cerr << "coins: " << coins << endl;
        if(coins > mx){
            mx = coins;
            f_use = u;
            f_ans = ans;
        }
    }



    rep(i, K){
        cout << f_use[i] << " ";
    }cout << endl;
    ans = f_ans;
    if(ans.size() >= T){
        rep(i, T){
            cout << ans[i];
        }
        cerr << "ans > T " << ans.size() << endl;
    }else{
        cout << ans;
        cerr << "ans < T " << ans.size() << endl;
    }

    return 0;
}
