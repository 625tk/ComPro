#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(void){
  int n;
  vector<int> t;

  cin >> n;
  t.resize(n);

  for(int &a :t){
    cin >> a;
  }
  sort(t.begin(), t.end());
  cout << t[0] << endl;

  return 0;
}

