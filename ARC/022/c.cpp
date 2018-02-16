#include<iostream>
#include<vector>
#include<queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

vector<int> g[100001];
int memo[2][100001];

int main(void){
    int n, a, b;
    cin >> n;
    rep(i,n-1){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int s = 0;
    int len = 0;
    queue<int> q;
    rep(i,2)rep(j,100001)memo[i][j]=-1;
    memo[0][s] = len;
    rep(i, g[s].size()) q.push(g[s][i]);
    while(!q.empty()){
        int t = q.size();
        len++;
        rep(i, t){
            s = q.front();q.pop();
            memo[0][s] = len;
            rep(j, g[s].size()) if(memo[0][g[s][j]] == -1)q.push(g[s][j]);
        }
    }

    int from = -1;
    int mx = -1;
    rep(i, n) if(memo[0][i] > mx){
        mx = memo[0][i];
        from = i;
    }
    s = from;
    memo[1][s] = 0;
    rep(i, g[s].size()) q.push(g[s][i]);
    while(!q.empty()){
        int t = q.size();
        len++;
        rep(i, t){
            s = q.front();q.pop();
            memo[1][s] = len;
            rep(j, g[s].size()) if(memo[1][g[s][j]] == -1)q.push(g[s][j]);
        }
    }
    int to = -1;
    mx = -1;
    rep(i, n) if(memo[1][i] > mx){
        mx = memo[1][i];
        to = i;
    }

    cout << from + 1 << " " << to + 1 << endl;

    return 0;
}

