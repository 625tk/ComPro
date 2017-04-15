#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)


int main(void){
  int t, n, m;
  vector<int> a;
  vector<int> b;

  cin >> t;
  cin >> n;
  a.resize(n);
  for(int &a1 : a)cin >> a1;
  a.push_back(-100);
  cin >> m;
  b.resize(m);
  for(int &a1 : b)cin >> a1;
  
  int i = 0;

  for(const int &be : b){
    while(a[i] + t < be){
      i++;
      if(i >= n){
        cout << "no" << endl;
        return 0;
      }
    }
    if(a[i] > be){
        cout << "no" << endl;
        return 0;
    }
    i++;
  }
  cout << "yes" << endl;


  return 0;
}

