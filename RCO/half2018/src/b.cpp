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



int dx[]= { 1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string mv = "RLDU";;
vector<int> r, c;
int cell[256][256];
int H, W, D, K;

int calc(int index){
    if( index == 0) return 0;
    return abs(r[index] - r[index-1]) + abs(c[index] - c[index-1]);
}

int calc2(int index){
    if( index <= 1) return 0;
    return abs(r[index] - r[index-2]) + abs(c[index] - c[index-2]);
}

bool check(int x, int y){
    if( 0 <= x && x < W && 0 <= y && y < H) return true;
    return false;
}

pair<int,int> a(int i){
    int r = i/(W*2);
    int c = i%(W*2);
    if(c >=W){
        return PII(2*W-c-1, r*2+1);
    }else{
        return PII(c, r*2);
    }
}


int costs[20000];

int main(void){
    int cost = 0;
    int mx = 0;
    int ind = 0;

    cin >> H >> W >> D >> K;
    r.resize(D);
    c.resize(D);
    rep(i, 256)rep(j,256) cell[i][j] = -1;

    rep(i, D){
        cin >> r[i] >> c[i];
        cell[r[i]][c[i]] = i;
    }

    int cnt = 0;
    int ans = 0;

    priority_queue<PII> pq;

    for(int i = 1; i < D; ++i){
        int diff = abs((calc(i) + calc(i+1)) - calc2(i+1));
        pq.push(PII(diff, i));
    }

    bool flag=true;
    while(cnt < K){
        if(cnt % 100 == 0 && cnt != 0 && flag){
            flag = false;
            while(!pq.empty())pq.pop();
            for(int i = 1; i < D; ++i){
                int diff = abs((calc(i) + calc(i+1)) - calc2(i+1));
                pq.push(PII(diff, i));
            }
        }

        cerr << "size " <<  pq.size() << endl;
        PII p = pq.top();pq.pop();
        int ind = p.Y;
        int diff = abs((calc(ind) + calc(ind+1)) - calc2(ind+1));
        if(diff < p.X){
            pq.push(PII(diff, ind));
            continue;
        }

        int xf = min(c[ind-1], c[ind+1]);
        int xt = max(c[ind-1], c[ind+1]);
        int yf = min(r[ind-1], r[ind+1]);
        int yt = max(r[ind-1], r[ind+1]);
        cerr << "-----------------------------" << endl;
        cerr << c[ind-1] << " " << r[ind-1] << endl;
        cerr << c[ind] << " " << r[ind] << endl;
        cerr << c[ind+1] << " " << r[ind+1] << endl;
        cerr << "( " << diff << " )" << endl;
        cerr << "-----------------------------" << endl;

        for(int x = xf; x<= xt; ++x){
            for(int y = yf; y <= yt; ++y){
                if(cell[y][x] == -1){
                    cell[r[ind]][c[ind]] = -1;
                    cell[y][x] = ind;
                    cout << r[ind] << " " << c[ind] << " " << y << " " << x << endl;
                    c[ind] = x;r[ind] = y;
                    cnt++;
                    flag = true;
                    x = y = 1000;
                }
            }
        }
        ans += diff;
    }

    cerr << ans << endl;
    cerr << cnt << endl;

    return 0;

}
