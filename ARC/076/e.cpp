#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
using PII=pair<int,int>;

vector<PII> l;
int r, c, n;
int x[2], y[2];

bool is_bor(int xs, int ys){
    return xs == 0 || ys == 0 || xs == r || ys == c;
}

int main(void){
    cin >> r >> c >> n;
    rep(i, n){
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        if(is_bor(x[0], y[0]) && is_bor(x[1], y[1])){
            rep(j, 2){
                if(x[j] == 0){
                    l.push_back(PII(y[j], i));
                }else if(y[j] == c){
                    l.push_back(PII(c+x[j], i));
                }else if(x[j] == r){
                    l.push_back(PII(c+r+c-y[j], i));
                }else if(y[j] == 0){
                    l.push_back(PII(c+r+c+r-x[j], i));
                }
            }
        }
    }
    sort(l.begin(), l.end());

    stack<int> s;
    rep(i, l.size()){
        int m = l[i].second;
        if(s.empty()){
            s.push(m);
        }else{
            if(s.top() == m){
                s.pop();
            }else{
                s.push(m);
            }
        }
    }
    cout << (s.empty()?"YES":"NO") << endl;
    return 0;
}
