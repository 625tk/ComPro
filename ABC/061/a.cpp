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


int main(void){
  int a,b,c;
  cin >> a >> b >> c;
  if( a<= c && c <= b){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
