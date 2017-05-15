#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>

#define X first
#define Y second
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int x[500];

int main(void){
  int n, m;
  cin >> n >> m;
  int a,b;
  rep(i,m){
    cin >> a >> b;
    a--;
    b--;
    x[a]++;x[b]++;
  }
  rep(i,n){
    cout << x[i] << endl;
  }
  return 0;
}
