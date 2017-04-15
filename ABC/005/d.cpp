#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define reps(i,f,n) for(int i = f; i <= n; ++i)

int cell[64][64];
int sum[64][64];
int mx[4096];


int main(void){
  int n, m, a;

  //1~N
  cin >> n;
  rep(i,n)rep(j,n){
    cin >> cell[i+1][j+1];
  }

  reps(i,1,n)reps(j,1,n){
    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + cell[i][j];
  }
  /*
  reps(i,1,n){
    reps(j,1,n){
      cout << sum[i][j] << ",";
    }cout << endl;
  }
  */


  reps(i,1,n)reps(j,1,n){
    reps(k,i,n)reps(l,j,n){
      //cout << "( " << i << "," << j << ") - (" << k << "," << l << ") -> " << sum[k][l] - sum[k][j-1] - sum[i-1][l] + sum[i-1][j-1] << "( " << (k-i+1)*(l-j+1) << " )" << endl;
      mx[(k-i+1) * (l-j+1)] = max(mx[(k-i+1) * (l-j+1)], sum[k][l] - sum[k][j-1] - sum[i-1][l] + sum[i-1][j-1]);
    }
  }

  reps(i,1,2500){
    mx[i] = max(mx[i], mx[i-1]);
  }

  cin >> m;
  rep(i,m){
    cin >> a;
    cout << mx[a] << endl;;
  }

  return 0;
}
